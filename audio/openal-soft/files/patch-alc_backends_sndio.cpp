--- alc/backends/sndio.cpp.orig	2021-02-04 19:09:06 UTC
+++ alc/backends/sndio.cpp
@@ -22,6 +22,7 @@
 
 #include "backends/sndio.h"
 
+#include <poll.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -43,7 +44,12 @@ namespace {
 
 static const char sndio_device[] = "SndIO Default";
 
+struct SioPar : public sio_par {
+    SioPar() { sio_initpar(this); }
 
+    void clear() { sio_initpar(this); }
+};
+
 struct SndioPlayback final : public BackendBase {
     SndioPlayback(ALCdevice *device) noexcept : BackendBase{device} { }
     ~SndioPlayback() override;
@@ -56,6 +62,7 @@ struct SndioPlayback final : public BackendBase {
     void stop() override;
 
     sio_hdl *mSndHandle{nullptr};
+    uint mFrameStep{};
 
     al::vector<al::byte> mBuffer;
 
@@ -74,39 +81,29 @@ SndioPlayback::~SndioPlayback()
 
 int SndioPlayback::mixerProc()
 {
-    sio_par par;
-    sio_initpar(&par);
-    if(!sio_getpar(mSndHandle, &par))
-    {
-        mDevice->handleDisconnect("Failed to get device parameters");
-        return 1;
-    }
+    const size_t frameStep{mFrameStep};
+    const size_t frameSize{frameStep * mDevice->bytesFromFmt()};
 
-    const size_t frameStep{par.pchan};
-    const size_t frameSize{frameStep * par.bps};
-
     SetRTPriority();
     althrd_setname(MIXER_THREAD_NAME);
 
     while(!mKillNow.load(std::memory_order_acquire)
         && mDevice->Connected.load(std::memory_order_acquire))
     {
-        al::byte *WritePtr{mBuffer.data()};
-        size_t len{mBuffer.size()};
+        al::span<al::byte> buffer{mBuffer};
 
-        mDevice->renderSamples(WritePtr, static_cast<uint>(len/frameSize), frameStep);
-        while(len > 0 && !mKillNow.load(std::memory_order_acquire))
+        mDevice->renderSamples(buffer.data(), static_cast<uint>(buffer.size() / frameSize),
+            frameStep);
+        while(!buffer.empty() && !mKillNow.load(std::memory_order_acquire))
         {
-            size_t wrote{sio_write(mSndHandle, WritePtr, len)};
+            size_t wrote{sio_write(mSndHandle, buffer.data(), buffer.size())};
             if(wrote == 0)
             {
                 ERR("sio_write failed\n");
                 mDevice->handleDisconnect("Failed to write playback samples");
                 break;
             }
-
-            len -= wrote;
-            WritePtr += wrote;
+            buffer = buffer.subspan(wrote);
         }
     }
 
@@ -131,26 +128,12 @@ void SndioPlayback::open(const char *name)
 
 bool SndioPlayback::reset()
 {
-    sio_par par;
-    sio_initpar(&par);
+    SioPar par;
 
-    par.rate = mDevice->Frequency;
-    switch(mDevice->FmtChans)
+    auto tryfmt = mDevice->FmtType;
+retry_params:
+    switch(tryfmt)
     {
-    case DevFmtMono   : par.pchan = 1; break;
-    case DevFmtQuad   : par.pchan = 4; break;
-    case DevFmtX51Rear: // fall-through - "Similar to 5.1, except using rear channels instead of sides"
-    case DevFmtX51    : par.pchan = 6; break;
-    case DevFmtX61    : par.pchan = 7; break;
-    case DevFmtX71    : par.pchan = 8; break;
-
-    // fall back to stereo for Ambi3D
-    case DevFmtAmbi3D : // fall-through
-    case DevFmtStereo : par.pchan = 2; break;
-    }
-
-    switch(mDevice->FmtType)
-    {
     case DevFmtByte:
         par.bits = 8;
         par.sig = 1;
@@ -159,7 +142,6 @@ bool SndioPlayback::reset()
         par.bits = 8;
         par.sig = 0;
         break;
-    case DevFmtFloat:
     case DevFmtShort:
         par.bits = 16;
         par.sig = 1;
@@ -168,6 +150,7 @@ bool SndioPlayback::reset()
         par.bits = 16;
         par.sig = 0;
         break;
+    case DevFmtFloat:
     case DevFmtInt:
         par.bits = 32;
         par.sig = 1;
@@ -177,70 +160,64 @@ bool SndioPlayback::reset()
         par.sig = 0;
         break;
     }
+    par.bps = SIO_BPS(par.bits);
     par.le = SIO_LE_NATIVE;
+    par.msb = 1;
 
+    par.rate = mDevice->Frequency;
+    par.pchan = mDevice->channelsFromFmt();
+
     par.round = mDevice->UpdateSize;
     par.appbufsz = mDevice->BufferSize - mDevice->UpdateSize;
     if(!par.appbufsz) par.appbufsz = mDevice->UpdateSize;
 
-    if(!sio_setpar(mSndHandle, &par) || !sio_getpar(mSndHandle, &par))
-    {
-        ERR("Failed to set device parameters\n");
-        return false;
-    }
+    try {
+        if(!sio_setpar(mSndHandle, &par))
+            throw al::backend_exception{al::backend_error::DeviceError,
+                "Failed to set device parameters"};
 
-    if(par.bits != par.bps*8)
-    {
-        ERR("Padded samples not supported (%u of %u bits)\n", par.bits, par.bps*8);
-        return false;
-    }
-    if(par.le != SIO_LE_NATIVE)
-    {
-        ERR("Non-native-endian samples not supported (got %s-endian)\n",
-            par.le ? "little" : "big");
-        return false;
-    }
+        par.clear();
+        if(!sio_getpar(mSndHandle, &par))
+            throw al::backend_exception{al::backend_error::DeviceError,
+                "Failed to get device parameters"};
 
-    mDevice->Frequency = par.rate;
-
-    if(par.pchan < 2)
-    {
-        if(mDevice->FmtChans != DevFmtMono)
-        {
-            WARN("Got %u channel for %s\n", par.pchan, DevFmtChannelsString(mDevice->FmtChans));
-            mDevice->FmtChans = DevFmtMono;
-        }
+        if(par.bps > 1 && par.le != SIO_LE_NATIVE)
+            throw al::backend_exception{al::backend_error::DeviceError,
+                "%s-endian samples not supported", par.le ? "Little" : "Big"};
+        if(par.bits < par.bps*8 && !par.msb)
+            throw al::backend_exception{al::backend_error::DeviceError,
+                "MSB-padded samples not supported (%u of %u bits)", par.bits, par.bps*8};
+        if(par.pchan < 1)
+            throw al::backend_exception{al::backend_error::DeviceError,
+                "No playback channels on device"};
     }
-    else if((par.pchan == 2 && mDevice->FmtChans != DevFmtStereo)
-        || par.pchan == 3
-        || (par.pchan == 4 && mDevice->FmtChans != DevFmtQuad)
-        || par.pchan == 5
-        || (par.pchan == 6 && mDevice->FmtChans != DevFmtX51 && mDevice->FmtChans != DevFmtX51Rear)
-        || (par.pchan == 7 && mDevice->FmtChans != DevFmtX61)
-        || (par.pchan == 8 && mDevice->FmtChans != DevFmtX71)
-        || par.pchan > 8)
-    {
-        WARN("Got %u channels for %s\n", par.pchan, DevFmtChannelsString(mDevice->FmtChans));
-        mDevice->FmtChans = DevFmtStereo;
+    catch(al::backend_exception &e) {
+        if(tryfmt == DevFmtShort)
+            throw;
+        par.clear();
+        tryfmt = DevFmtShort;
+        goto retry_params;
     }
 
-    if(par.bits == 8 && par.sig == 1)
-        mDevice->FmtType = DevFmtByte;
-    else if(par.bits == 8 && par.sig == 0)
-        mDevice->FmtType = DevFmtUByte;
-    else if(par.bits == 16 && par.sig == 1)
-        mDevice->FmtType = DevFmtShort;
-    else if(par.bits == 16 && par.sig == 0)
-        mDevice->FmtType = DevFmtUShort;
-    else if(par.bits == 32 && par.sig == 1)
-        mDevice->FmtType = DevFmtInt;
-    else if(par.bits == 32 && par.sig == 0)
-        mDevice->FmtType = DevFmtUInt;
+    if(par.bps == 1)
+        mDevice->FmtType = (par.sig==1) ? DevFmtByte : DevFmtUByte;
+    else if(par.bps == 2)
+        mDevice->FmtType = (par.sig==1) ? DevFmtShort : DevFmtUShort;
+    else if(par.bps == 4)
+        mDevice->FmtType = (par.sig==1) ? DevFmtInt : DevFmtUInt;
     else
+        throw al::backend_exception{al::backend_error::DeviceError,
+            "Unhandled sample format: %s %u-bit", (par.sig?"signed":"unsigned"), par.bps*8};
+
+    mFrameStep = par.pchan;
+    if(par.pchan != mDevice->channelsFromFmt())
     {
-        ERR("Unhandled sample format: %s %u-bit\n", (par.sig?"signed":"unsigned"), par.bits);
-        return false;
+        WARN("Got %u channel%s for %s\n", par.pchan, (par.pchan==1)?"":"s",
+            DevFmtChannelsString(mDevice->FmtChans));
+        if(par.pchan < 2) mDevice->FmtChans = DevFmtMono;
+        else mDevice->FmtChans = DevFmtStereo;
     }
+    mDevice->Frequency = par.rate;
 
     setDefaultChannelOrder();
 
@@ -287,6 +264,11 @@ void SndioPlayback::stop()
 }
 
 
+/* TODO: This could be improved by avoiding the ring buffer and record thread,
+ * counting the available samples with the sio_onmove callback and reading
+ * directly from the device. However, this depends on reasonable support for
+ * capture buffer sizes apps may request.
+ */
 struct SndioCapture final : public BackendBase {
     SndioCapture(ALCdevice *device) noexcept : BackendBase{device} { }
     ~SndioCapture() override;
@@ -323,40 +305,65 @@ int SndioCapture::recordProc()
 
     const uint frameSize{mDevice->frameSizeFromFmt()};
 
+    int nfds_pre{sio_nfds(mSndHandle)};
+    if(nfds_pre <= 0)
+    {
+        mDevice->handleDisconnect("Incorrect return value from sio_nfds(): %d", nfds_pre);
+        return 1;
+    }
+
+    auto fds = std::make_unique<pollfd[]>(static_cast<uint>(nfds_pre));
+
     while(!mKillNow.load(std::memory_order_acquire)
         && mDevice->Connected.load(std::memory_order_acquire))
     {
-        auto data = mRing->getWriteVector();
-        size_t todo{data.first.len + data.second.len};
-        if(todo == 0)
+        /* Wait until there's some samples to read. */
+        const int nfds{sio_pollfd(mSndHandle, fds.get(), POLLIN)};
+        if(nfds <= 0)
         {
-            static char junk[4096];
-            sio_read(mSndHandle, junk,
-                minz(sizeof(junk)/frameSize, mDevice->UpdateSize)*frameSize);
+            mDevice->handleDisconnect("Failed to get polling fds: %d", nfds);
+            break;
+        }
+        int pollres{::poll(fds.get(), static_cast<uint>(nfds), 2000)};
+        if(pollres < 0)
+        {
+            if(errno == EINTR) continue;
+            mDevice->handleDisconnect("Poll error: %s", strerror(errno));
+            break;
+        }
+        if(pollres == 0)
             continue;
+
+        const int revents{sio_revents(mSndHandle, fds.get())};
+        if((revents&POLLHUP))
+        {
+            mDevice->handleDisconnect("Got POLLHUP from poll events");
+            break;
         }
+        if(!(revents&POLLIN))
+            continue;
 
-        size_t total{0u};
-        data.first.len  *= frameSize;
-        data.second.len *= frameSize;
-        todo = minz(todo, mDevice->UpdateSize) * frameSize;
-        while(total < todo)
+        auto data = mRing->getWriteVector();
+        al::span<al::byte> buffer{data.first.buf, data.first.len*frameSize};
+        while(!buffer.empty())
         {
-            if(!data.first.len)
-                data.first = data.second;
+            size_t got{sio_read(mSndHandle, buffer.data(), buffer.size())};
+            if(got == 0) break;
 
-            size_t got{sio_read(mSndHandle, data.first.buf, minz(todo-total, data.first.len))};
-            if(!got)
+            mRing->writeAdvance(got / frameSize);
+            buffer = buffer.subspan(got);
+            if(buffer.empty())
             {
-                mDevice->handleDisconnect("Failed to read capture samples");
-                break;
+                data = mRing->getWriteVector();
+                buffer = {data.first.buf, data.first.len*frameSize};
             }
-
-            data.first.buf += got;
-            data.first.len -= got;
-            total += got;
         }
-        mRing->writeAdvance(total / frameSize);
+        if(buffer.empty())
+        {
+            /* Got samples to read, but no place to store it. Drop it. */
+            static char junk[4096];
+            sio_read(mSndHandle, junk, sizeof(junk) - (sizeof(junk)%frameSize));
+        }
     }
 
     return 0;
@@ -371,76 +378,80 @@ void SndioCapture::open(const char *name)
         throw al::backend_exception{al::backend_error::NoDevice, "Device name \"%s\" not found",
             name};
 
-    mSndHandle = sio_open(nullptr, SIO_REC, 0);
+    mSndHandle = sio_open(nullptr, SIO_REC, true);
     if(mSndHandle == nullptr)
         throw al::backend_exception{al::backend_error::NoDevice, "Could not open backend device"};
 
-    sio_par par;
-    sio_initpar(&par);
-
+    SioPar par;
     switch(mDevice->FmtType)
     {
     case DevFmtByte:
-        par.bps = 1;
+        par.bits = 8;
         par.sig = 1;
         break;
     case DevFmtUByte:
-        par.bps = 1;
+        par.bits = 8;
         par.sig = 0;
         break;
     case DevFmtShort:
-        par.bps = 2;
+        par.bits = 16;
         par.sig = 1;
         break;
     case DevFmtUShort:
-        par.bps = 2;
+        par.bits = 16;
         par.sig = 0;
         break;
     case DevFmtInt:
-        par.bps = 4;
+        par.bits = 32;
         par.sig = 1;
         break;
     case DevFmtUInt:
-        par.bps = 4;
+        par.bits = 32;
         par.sig = 0;
         break;
     case DevFmtFloat:
         throw al::backend_exception{al::backend_error::DeviceError,
             "%s capture samples not supported", DevFmtTypeString(mDevice->FmtType)};
     }
-    par.bits = par.bps * 8;
+    par.bps = SIO_BPS(par.bits);
     par.le = SIO_LE_NATIVE;
-    par.msb = SIO_LE_NATIVE ? 0 : 1;
+    par.msb = 1;
     par.rchan = mDevice->channelsFromFmt();
     par.rate = mDevice->Frequency;
 
     par.appbufsz = maxu(mDevice->BufferSize, mDevice->Frequency/10);
-    par.round = minu(par.appbufsz, mDevice->Frequency/40);
+    par.round = minu(par.appbufsz/2, mDevice->Frequency/40);
 
-    mDevice->UpdateSize = par.round;
-    mDevice->BufferSize = par.appbufsz;
-
     if(!sio_setpar(mSndHandle, &par) || !sio_getpar(mSndHandle, &par))
         throw al::backend_exception{al::backend_error::DeviceError,
             "Failed to set device praameters"};
 
-    if(par.bits != par.bps*8)
+    if(par.bps > 1 && par.le != SIO_LE_NATIVE)
         throw al::backend_exception{al::backend_error::DeviceError,
+            "%s-endian samples not supported", par.le ? "Little" : "Big"};
+    if(par.bits < par.bps*8 && !par.msb)
+        throw al::backend_exception{al::backend_error::DeviceError,
             "Padded samples not supported (got %u of %u bits)", par.bits, par.bps*8};
 
-    if(!((mDevice->FmtType == DevFmtByte && par.bits == 8 && par.sig != 0)
-        || (mDevice->FmtType == DevFmtUByte && par.bits == 8 && par.sig == 0)
-        || (mDevice->FmtType == DevFmtShort && par.bits == 16 && par.sig != 0)
-        || (mDevice->FmtType == DevFmtUShort && par.bits == 16 && par.sig == 0)
-        || (mDevice->FmtType == DevFmtInt && par.bits == 32 && par.sig != 0)
-        || (mDevice->FmtType == DevFmtUInt && par.bits == 32 && par.sig == 0))
-        || mDevice->channelsFromFmt() != par.rchan || mDevice->Frequency != par.rate)
+    auto match_fmt = [](DevFmtType fmttype, const sio_par &par) -> bool
+    {
+        return (fmttype == DevFmtByte && par.bps == 1 && par.sig != 0)
+            || (fmttype == DevFmtUByte && par.bps == 1 && par.sig == 0)
+            || (fmttype == DevFmtShort && par.bps == 2 && par.sig != 0)
+            || (fmttype == DevFmtUShort && par.bps == 2 && par.sig == 0)
+            || (fmttype == DevFmtInt && par.bps == 4 && par.sig != 0)
+            || (fmttype == DevFmtUInt && par.bps == 4 && par.sig == 0);
+    };
+    if(!match_fmt(mDevice->FmtType, par) || mDevice->channelsFromFmt() != par.rchan
+        || mDevice->Frequency != par.rate)
         throw al::backend_exception{al::backend_error::DeviceError,
             "Failed to set format %s %s %uhz, got %c%u %u-channel %uhz instead",
             DevFmtTypeString(mDevice->FmtType), DevFmtChannelsString(mDevice->FmtChans),
-            mDevice->Frequency, par.sig?'s':'u', par.bits, par.rchan, par.rate};
+            mDevice->Frequency, par.sig?'s':'u', par.bps*8, par.rchan, par.rate};
 
     mRing = RingBuffer::Create(mDevice->BufferSize, par.bps*par.rchan, false);
+    mDevice->BufferSize = static_cast<uint>(mRing->writeSpace());
+    mDevice->UpdateSize = par.round;
 
     setDefaultChannelOrder();
 
