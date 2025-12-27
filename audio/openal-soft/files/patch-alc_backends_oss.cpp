Backport upstream commits to fix build.

https://github.com/kcat/openal-soft/commit/278d1dc4d607b84e4e7b2d93af094d7932588962
https://github.com/kcat/openal-soft/commit/b93a15cc886cda8ce7626e84c637bdaf7c346773
https://github.com/kcat/openal-soft/commit/5f0bf631d7d43f568f10065aae561c892c02d43e
https://github.com/kcat/openal-soft/commit/78a2ddb791163ae0d603937c88613523d27fa22d

https://github.com/kcat/openal-soft/issues/1215

--- alc/backends/oss.cpp.orig	2025-12-22 09:17:45 UTC
+++ alc/backends/oss.cpp
@@ -33,6 +33,7 @@
 #include <cerrno>
 #include <cstring>
 #include <exception>
+#include <functional>
 #include <memory>
 #include <span>
 #include <string>
@@ -65,12 +66,9 @@
 #define SOUND_MIXER_WRITE MIXER_WRITE
 #endif
 
-#if defined(SOUND_VERSION) && (SOUND_VERSION < 0x040000)
+#if (defined(SOUND_VERSION) && (SOUND_VERSION < 0x040000)) || !defined(SNDCTL_AUDIOINFO)
 #define ALC_OSS_COMPAT
 #endif
-#ifndef SNDCTL_AUDIOINFO
-#define ALC_OSS_COMPAT
-#endif
 
 /*
  * FreeBSD strongly discourages the use of specific devices,
@@ -98,32 +96,28 @@ std::vector<DevMap> CaptureDevices;
 std::vector<DevMap> PlaybackDevices;
 std::vector<DevMap> CaptureDevices;
 
-
-#ifdef ALC_OSS_COMPAT
-
-#define DSP_CAP_OUTPUT 0x00020000
-#define DSP_CAP_INPUT 0x00010000
-void ALCossListPopulate(std::vector<DevMap> &devlist, int type)
-{
-    devlist.emplace_back(std::string{GetDefaultName()},
-        (type==DSP_CAP_INPUT) ? DefaultCapture : DefaultPlayback);
-}
-
-#else
-
 class FileHandle {
     int mFd{-1};
 
 public:
     FileHandle() = default;
     FileHandle(const FileHandle&) = delete;
-    FileHandle& operator=(const FileHandle&) = delete;
+    FileHandle(FileHandle&& rhs) noexcept : mFd{std::exchange(rhs.mFd, -1)} { }
     ~FileHandle() { if(mFd != -1) ::close(mFd); }
 
+    auto operator=(const FileHandle&) -> FileHandle& = delete;
+    auto operator=(FileHandle&& rhs) noexcept -> FileHandle&
+    {
+        close();
+        mFd = std::exchange(rhs.mFd, -1);
+        return *this;
+    }
+
     template<typename ...Args>
-    [[nodiscard]] auto open(const char *fname, Args&& ...args) -> bool
+    [[nodiscard]] auto open(gsl::czstring const fname, Args&& ...args) -> bool
     {
         close();
+        /* NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg) */
         mFd = ::open(fname, std::forward<Args>(args)...);
         return mFd != -1;
     }
@@ -134,10 +128,35 @@ class FileHandle { (public)
         mFd = -1;
     }
 
-    [[nodiscard]]
-    auto get() const noexcept -> int { return mFd; }
+    template<typename ...Args>
+    [[nodiscard]] auto ioctl(Args&& ...args) const
+    {
+        /* NOLINTNEXTLINE(cppcoreguidelines-pro-type-vararg) */
+        return ::ioctl(mFd, std::forward<Args>(args)...);
+    }
+
+    [[nodiscard]] auto read(std::span<std::byte> const bytes) const
+    { return ::read(mFd, bytes.data(), bytes.size()); }
+
+    [[nodiscard]] auto write(std::span<std::byte const> const bytes) const
+    { return ::write(mFd, bytes.data(), bytes.size()); }
+
+    [[nodiscard]] auto get() const noexcept -> int { return mFd; }
 };
 
+
+#ifdef ALC_OSS_COMPAT
+
+#define DSP_CAP_OUTPUT 0x00020000
+#define DSP_CAP_INPUT 0x00010000
+void ALCossListPopulate(std::vector<DevMap> &devlist, int type)
+{
+    devlist.emplace_back(std::string{GetDefaultName()},
+        (type==DSP_CAP_INPUT) ? DefaultCapture : DefaultPlayback);
+}
+
+#else
+
 void ALCossListAppend(std::vector<DevMap> &list, std::string_view handle, std::string_view path)
 {
 #ifdef ALC_OSS_DEVNODE_TRUC
@@ -149,45 +168,63 @@ void ALCossListAppend(std::vector<DevMap> &list, std::
             if(strncmp(path.data() + i, handle.data() + hoffset, path.size() - i) == 0)
                 handle = handle.substr(0, hoffset);
             path = path.substr(0, i);
+            break;
         }
     }
 #endif
-    if(handle.empty())
-        handle = path;
+    if(path.empty())
+        return;
 
     if(std::ranges::find(list, path, &DevMap::device_name) != list.end())
         return;
 
+    if(handle.empty())
+        handle = path;
+
     auto count = 1;
     auto newname = std::string{handle};
     while(std::ranges::find(list, newname, &DevMap::name) != list.end())
         newname = al::format("{} #{}", handle, ++count);
 
-    const auto &entry = list.emplace_back(std::move(newname), path);
-    TRACE("Got device \"{}\", \"{}\"", entry.name, entry.device_name);
+    const auto &entry = list.emplace_back(std::move(newname), std::string{path});
+    TRACE(R"(Got device "{}", "{}")", entry.name, entry.device_name);
 }
 
-void ALCossListPopulate(std::vector<DevMap> &devlist, int type_flag)
+void ALCossListPopulate(std::vector<DevMap> &devlist, int const type_flag)
 {
+    /* Make sure to move the default device to the start of the devlist (or
+     * adding the default if it doesn't exist) before returning.
+     */
+    auto _ = gsl::finally([&devlist, type_flag]
+    {
+        auto const &defdev = (type_flag == DSP_CAP_INPUT) ? DefaultCapture : DefaultPlayback;
+        if(auto const iter = std::ranges::find(devlist, defdev, &DevMap::device_name);
+            iter != devlist.end())
+            std::ranges::rotate(devlist.begin(), iter, iter+1);
+        else
+            devlist.insert(devlist.begin(), DevMap{std::string{GetDefaultName()}, defdev});
+        devlist.shrink_to_fit();
+    });
+
     auto si = oss_sysinfo{};
     auto file = FileHandle{};
     if(!file.open("/dev/mixer", O_RDONLY))
     {
         TRACE("Could not open /dev/mixer: {}", std::generic_category().message(errno));
-        goto done;
+        return;
     }
 
-    if(ioctl(file.get(), SNDCTL_SYSINFO, &si) == -1)
+    if(file.ioctl(SNDCTL_SYSINFO, &si) == -1)
     {
         TRACE("SNDCTL_SYSINFO failed: {}", std::generic_category().message(errno));
-        goto done;
+        return;
     }
 
-    for(int i{0};i < si.numaudios;i++)
+    for(auto const i : std::views::iota(0, si.numaudios))
     {
-        oss_audioinfo ai{};
+        auto ai = oss_audioinfo{};
         ai.dev = i;
-        if(ioctl(file.get(), SNDCTL_AUDIOINFO, &ai) == -1)
+        if(file.ioctl(SNDCTL_AUDIOINFO, &ai) == -1)
         {
             ERR("SNDCTL_AUDIOINFO ({}) failed: {}", i, std::generic_category().message(errno));
             continue;
@@ -195,30 +232,17 @@ void ALCossListPopulate(std::vector<DevMap> &devlist, 
         if(!(ai.caps&type_flag) || ai.devnode[0] == '\0')
             continue;
 
-        std::string_view handle;
-        if(ai.handle[0] != '\0')
-            handle = {ai.handle, strnlen(ai.handle, sizeof(ai.handle))};
-        else
-            handle = {ai.name, strnlen(ai.name, sizeof(ai.name))};
-        const std::string_view devnode{ai.devnode, strnlen(ai.devnode, sizeof(ai.devnode))};
+        auto const handle = std::invoke([&ai]() -> std::string_view
+        {
+            if(ai.handle[0] != '\0')
+                return {std::data(ai.handle), strnlen(std::data(ai.handle), std::size(ai.handle))};
+            return {std::data(ai.name), strnlen(std::data(ai.name), std::size(ai.name))};
+        });
+        auto const devnode = std::string_view{std::data(ai.devnode),
+            strnlen(std::data(ai.devnode), std::size(ai.devnode))};
 
         ALCossListAppend(devlist, handle, devnode);
     }
-
-done:
-    file.close();
-
-    const char *defdev{((type_flag==DSP_CAP_INPUT) ? DefaultCapture : DefaultPlayback).c_str()};
-    auto iter = std::ranges::find(devlist, defdev, &DevMap::device_name);
-    if(iter == devlist.end())
-        devlist.insert(devlist.begin(), DevMap{GetDefaultName(), defdev});
-    else
-    {
-        auto entry = DevMap{std::move(*iter)};
-        devlist.erase(iter);
-        devlist.insert(devlist.begin(), std::move(entry));
-    }
-    devlist.shrink_to_fit();
 }
 
 #endif
@@ -247,7 +271,7 @@ struct OSSPlayback final : BackendBase {
     void start() override;
     void stop() override;
 
-    int mFd{-1};
+    FileHandle mFd;
 
     std::vector<std::byte> mMixData;
 
@@ -255,12 +279,7 @@ struct OSSPlayback final : BackendBase {
     std::thread mThread;
 };
 
-OSSPlayback::~OSSPlayback()
-{
-    if(mFd != -1)
-        ::close(mFd);
-    mFd = -1;
-}
+OSSPlayback::~OSSPlayback() = default;
 
 
 void OSSPlayback::mixerProc()
@@ -275,7 +294,7 @@ void OSSPlayback::mixerProc()
         && mDevice->Connected.load(std::memory_order_acquire))
     {
         auto pollitem = pollfd{};
-        pollitem.fd = mFd;
+        pollitem.fd = mFd.get();
         pollitem.events = POLLOUT;
 
         if(const auto pret = poll(&pollitem, 1, 1000); pret < 0)
@@ -298,7 +317,7 @@ void OSSPlayback::mixerProc()
             gsl::narrow_cast<u32>(write_buf.size()/frame_size), frame_step);
         while(!write_buf.empty() && !mKillNow.load(std::memory_order_acquire))
         {
-            const auto wrote = write(mFd, write_buf.data(), write_buf.size());
+            const auto wrote = mFd.write(write_buf);
             if(wrote < 0)
             {
                 if(errno == EAGAIN || errno == EWOULDBLOCK || errno == EINTR)
@@ -332,15 +351,10 @@ void OSSPlayback::open(std::string_view name)
         devname = iter->device_name.c_str();
     }
 
-    const auto fd = ::open(devname, O_WRONLY); /* NOLINT(cppcoreguidelines-pro-type-vararg) */
-    if(fd == -1)
+    if(not mFd.open(devname, O_WRONLY))
         throw al::backend_exception{al::backend_error::NoDevice, "Could not open {}: {}", devname,
             std::generic_category().message(errno)};
 
-    if(mFd != -1)
-        ::close(mFd);
-    mFd = fd;
-
     mDeviceName = name;
 }
 
@@ -349,21 +363,21 @@ auto OSSPlayback::reset() -> bool
     auto ossFormat = int{};
     switch(mDevice->FmtType)
     {
-        case DevFmtByte:
-            ossFormat = AFMT_S8;
-            break;
-        case DevFmtUByte:
-            ossFormat = AFMT_U8;
-            break;
-        case DevFmtUShort:
-        case DevFmtInt:
-        case DevFmtUInt:
-        case DevFmtFloat:
-            mDevice->FmtType = DevFmtShort;
-            [[fallthrough]];
-        case DevFmtShort:
-            ossFormat = AFMT_S16_NE;
-            break;
+    case DevFmtByte:
+        ossFormat = AFMT_S8;
+        break;
+    case DevFmtUByte:
+        ossFormat = AFMT_U8;
+        break;
+    case DevFmtUShort:
+    case DevFmtInt:
+    case DevFmtUInt:
+    case DevFmtFloat:
+        mDevice->FmtType = DevFmtShort;
+        [[fallthrough]];
+    case DevFmtShort:
+        ossFormat = AFMT_S16_NE;
+        break;
     }
 
     auto numChannels = mDevice->channelsFromFmt();
@@ -373,22 +387,20 @@ auto OSSPlayback::reset() -> bool
     auto numFragmentsLogSize = ((mDevice->mBufferSize + mDevice->mUpdateSize/2)
         / mDevice->mUpdateSize) << 16u;
     /* According to the OSS spec, 16 bytes is the minimum period size. */
-    numFragmentsLogSize |= std::max(log2i(mDevice->mUpdateSize * frameSize), 4u);
+    numFragmentsLogSize |= std::max(log2i(mDevice->mUpdateSize * frameSize), 4_u32);
 
     auto info = audio_buf_info{};
 #define CHECKERR(func) if((func) < 0)                                         \
     throw al::backend_exception{al::backend_error::DeviceError, #func " failed: {}", \
         std::generic_category().message(errno)};
-
-    /* NOLINTBEGIN(cppcoreguidelines-pro-type-vararg) */
     /* Don't fail if SETFRAGMENT fails. We can handle just about anything
-     * that's reported back via GETOSPACE */
-    ioctl(mFd, SNDCTL_DSP_SETFRAGMENT, &numFragmentsLogSize);
-    CHECKERR(ioctl(mFd, SNDCTL_DSP_SETFMT, &ossFormat));
-    CHECKERR(ioctl(mFd, SNDCTL_DSP_CHANNELS, &numChannels));
-    CHECKERR(ioctl(mFd, SNDCTL_DSP_SPEED, &ossSpeed));
-    CHECKERR(ioctl(mFd, SNDCTL_DSP_GETOSPACE, &info));
-    /* NOLINTEND(cppcoreguidelines-pro-type-vararg) */
+     * that's reported back via GETOSPACE.
+     */
+    std::ignore = mFd.ioctl(SNDCTL_DSP_SETFRAGMENT, &numFragmentsLogSize);
+    CHECKERR(mFd.ioctl(SNDCTL_DSP_SETFMT, &ossFormat));
+    CHECKERR(mFd.ioctl(SNDCTL_DSP_CHANNELS, &numChannels));
+    CHECKERR(mFd.ioctl(SNDCTL_DSP_SPEED, &ossSpeed));
+    CHECKERR(mFd.ioctl(SNDCTL_DSP_GETOSPACE, &info));
 #undef CHECKERR
 
     if(mDevice->channelsFromFmt() != numChannels)
@@ -436,14 +448,14 @@ void OSSPlayback::stop()
         return;
     mThread.join();
 
-    if(ioctl(mFd, SNDCTL_DSP_RESET) != 0) /* NOLINT(cppcoreguidelines-pro-type-vararg) */
+    if(mFd.ioctl(SNDCTL_DSP_RESET) != 0)
         ERR("Error resetting device: {}", std::generic_category().message(errno));
 }
 
 
-struct OSScapture final : public BackendBase {
-    explicit OSScapture(gsl::not_null<DeviceBase*> device) noexcept : BackendBase{device} { }
-    ~OSScapture() override;
+struct OSSCapture final : BackendBase {
+    explicit OSSCapture(gsl::not_null<DeviceBase*> const device) noexcept : BackendBase{device} { }
+    ~OSSCapture() override;
 
     void recordProc() const;
 
@@ -453,7 +465,7 @@ struct OSScapture final : public BackendBase {
     void captureSamples(std::span<std::byte> outbuffer) override;
     auto availableSamples() -> usize override;
 
-    int mFd{-1};
+    FileHandle mFd;
 
     RingBufferPtr<std::byte> mRing;
 
@@ -461,15 +473,10 @@ struct OSScapture final : public BackendBase {
     std::thread mThread;
 };
 
-OSScapture::~OSScapture()
-{
-    if(mFd != -1)
-        close(mFd);
-    mFd = -1;
-}
+OSSCapture::~OSSCapture() = default;
 
 
-void OSScapture::recordProc() const
+void OSSCapture::recordProc() const
 {
     SetRTPriority();
     althrd_setname(GetRecordThreadName());
@@ -478,7 +485,7 @@ void OSScapture::recordProc() const
     while(!mKillNow.load(std::memory_order_acquire))
     {
         auto pollitem = pollfd{};
-        pollitem.fd = mFd;
+        pollitem.fd = mFd.get();
         pollitem.events = POLLIN;
 
         if(auto const pret = poll(&pollitem, 1, 1000); pret < 0)
@@ -496,10 +503,9 @@ void OSScapture::recordProc() const
             continue;
         }
 
-        auto vec = mRing->getWriteVector();
-        if(!vec[0].empty())
+        if(auto const vec = mRing->getWriteVector(); !vec[0].empty())
         {
-            auto amt = read(mFd, vec[0].data(), vec[0].size());
+            auto const amt = mFd.read(vec[0]);
             if(amt < 0)
             {
                 auto const errstr = std::generic_category().message(errno);
@@ -513,7 +519,7 @@ void OSScapture::recordProc() const
 }
 
 
-void OSScapture::open(std::string_view name)
+void OSSCapture::open(std::string_view name)
 {
     auto *devname = DefaultCapture.c_str();
     if(name.empty())
@@ -523,15 +529,14 @@ void OSScapture::open(std::string_view name)
         if(CaptureDevices.empty())
             ALCossListPopulate(CaptureDevices, DSP_CAP_INPUT);
 
-        auto iter = std::ranges::find(CaptureDevices, name, &DevMap::name);
+        auto const iter = std::ranges::find(CaptureDevices, name, &DevMap::name);
         if(iter == CaptureDevices.end())
             throw al::backend_exception{al::backend_error::NoDevice,
                 "Device name \"{}\" not found", name};
         devname = iter->device_name.c_str();
     }
 
-    mFd = ::open(devname, O_RDONLY); /* NOLINT(cppcoreguidelines-pro-type-vararg) */
-    if(mFd == -1)
+    if(not mFd.open(devname, O_RDONLY))
         throw al::backend_exception{al::backend_error::NoDevice, "Could not open {}: {}", devname,
             std::generic_category().message(errno)};
 
@@ -568,13 +573,11 @@ void OSScapture::open(std::string_view name)
     throw al::backend_exception{al::backend_error::DeviceError, #func " failed: {}", \
         std::generic_category().message(errno)};                              \
 }
-    /* NOLINTBEGIN(cppcoreguidelines-pro-type-vararg) */
-    CHECKERR(ioctl(mFd, SNDCTL_DSP_SETFRAGMENT, &numFragmentsLogSize));
-    CHECKERR(ioctl(mFd, SNDCTL_DSP_SETFMT, &ossFormat));
-    CHECKERR(ioctl(mFd, SNDCTL_DSP_CHANNELS, &numChannels));
-    CHECKERR(ioctl(mFd, SNDCTL_DSP_SPEED, &ossSpeed));
-    CHECKERR(ioctl(mFd, SNDCTL_DSP_GETISPACE, &info));
-    /* NOLINTEND(cppcoreguidelines-pro-type-vararg) */
+    CHECKERR(mFd.ioctl(SNDCTL_DSP_SETFRAGMENT, &numFragmentsLogSize));
+    CHECKERR(mFd.ioctl(SNDCTL_DSP_SETFMT, &ossFormat));
+    CHECKERR(mFd.ioctl(SNDCTL_DSP_CHANNELS, &numChannels));
+    CHECKERR(mFd.ioctl(SNDCTL_DSP_SPEED, &ossSpeed));
+    CHECKERR(mFd.ioctl(SNDCTL_DSP_GETISPACE, &info));
 #undef CHECKERR
 
     if(mDevice->channelsFromFmt() != numChannels)
@@ -594,11 +597,11 @@ void OSScapture::open(std::string_view name)
     mDeviceName = name;
 }
 
-void OSScapture::start()
+void OSSCapture::start()
 {
     try {
         mKillNow.store(false, std::memory_order_release);
-        mThread = std::thread{&OSScapture::recordProc, this};
+        mThread = std::thread{&OSSCapture::recordProc, this};
     }
     catch(std::exception& e) {
         throw al::backend_exception{al::backend_error::DeviceError,
@@ -606,20 +609,20 @@ void OSScapture::start()
     }
 }
 
-void OSScapture::stop()
+void OSSCapture::stop()
 {
     if(mKillNow.exchange(true, std::memory_order_acq_rel) || !mThread.joinable())
         return;
     mThread.join();
 
-    if(ioctl(mFd, SNDCTL_DSP_RESET) != 0) /* NOLINT(cppcoreguidelines-pro-type-vararg) */
+    if(mFd.ioctl(SNDCTL_DSP_RESET) != 0)
         ERR("Error resetting device: {}", std::generic_category().message(errno));
 }
 
-void OSScapture::captureSamples(std::span<std::byte> outbuffer)
+void OSSCapture::captureSamples(std::span<std::byte> outbuffer)
 { std::ignore = mRing->read(outbuffer); }
 
-auto OSScapture::availableSamples() -> usize
+auto OSSCapture::availableSamples() -> usize
 { return mRing->readSpace(); }
 
 } // namespace
@@ -672,12 +675,12 @@ auto OSSBackendFactory::createBackend(gsl::not_null<De
     if(type == BackendType::Playback)
         return BackendPtr{new OSSPlayback{device}};
     if(type == BackendType::Capture)
-        return BackendPtr{new OSScapture{device}};
+        return BackendPtr{new OSSCapture{device}};
     return nullptr;
 }
 
 auto OSSBackendFactory::getFactory() -> BackendFactory&
 {
-    static OSSBackendFactory factory{};
+    static auto factory = OSSBackendFactory{};
     return factory;
 }
