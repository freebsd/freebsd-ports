--- plugins/vidinput_v4l/vidinput_v4l.cxx.orig	2009-09-20 20:25:31.000000000 -0400
+++ plugins/vidinput_v4l/vidinput_v4l.cxx	2010-01-27 14:11:25.000000000 -0500
@@ -38,6 +38,17 @@
 
 PCREATE_VIDINPUT_PLUGIN(V4L);
 
+#ifdef HAS_LIBV4L
+#include <libv4l1.h>
+#else
+#define v4l1_open open
+#define v4l1_close close
+#define v4l1_ioctl ioctl
+#define v4l1_read read
+#define v4l1_mmap mmap
+#define v4l1_munmap munmap
+#endif  
+
 ///////////////////////////////////////////////////////////////////////////////
 // Linux Video4Linux Driver Hints Tables.
 //
@@ -261,27 +272,46 @@
 void
 V4LNames::Update()
 {
-  PDirectory   procvideo("/proc/video/dev");
-  PString      entry;
-  PStringList  devlist;
   
   PWaitAndSignal m(mutex);
   inputDeviceNames.RemoveAll (); // flush the previous run
+
+#if defined(P_FREEBSD)
+  for (int i = 0; i < 10; i++) {
+    PString thisDevice = PString("/dev/video") + PString(i);
+    int videoFd = ::v4l1_open((const char *)thisDevice, O_RDONLY | O_NONBLOCK);
+
+    if ((videoFd > 0) || (errno == EBUSY)){
+      PBoolean valid = PFalse;
+      struct video_capability  videoCaps;
+      if (v4l1_ioctl(videoFd, VIDIOCGCAP, &videoCaps) >= 0 && (videoCaps.type & VID_TYPE_CAPTURE) != 0)
+        valid = PTrue;
+      if (videoFd >= 0)
+        v4l1_close(videoFd); 
+      if (valid)
+        inputDeviceNames += thisDevice;
+    }
+  }
+#else
+  PDirectory   procvideo("/proc/video/dev");
+  PString      entry;
+  PStringList  devlist;
+
   if (procvideo.Exists()) {
     if (procvideo.Open(PFileInfo::RegularFile)) {
       do {
         entry = procvideo.GetEntryName();
         if ((entry.Left(5) == "video") || (entry.Left(7) == "capture")) {
           PString thisDevice = "/dev/video" + entry.Right(1);
-          int videoFd = ::open((const char *)thisDevice, O_RDONLY | O_NONBLOCK);
+          int videoFd = ::v4l1_open((const char *)thisDevice, O_RDONLY | O_NONBLOCK);
 
           if ((videoFd > 0) || (errno == EBUSY)){
             PBoolean valid = PFalse;
             struct video_capability  videoCaps;
-            if (ioctl(videoFd, VIDIOCGCAP, &videoCaps) >= 0 && (videoCaps.type & VID_TYPE_CAPTURE) != 0)
+            if (v4l1_ioctl(videoFd, VIDIOCGCAP, &videoCaps) >= 0 && (videoCaps.type & VID_TYPE_CAPTURE) != 0)
               valid = PTrue;
             if (videoFd >= 0)
-              close(videoFd); 
+              v4l1_close(videoFd); 
             if (valid)
               inputDeviceNames += thisDevice;
           }
@@ -289,16 +319,17 @@
       } while (procvideo.Next());
     }   
   } 
+#endif
   if (inputDeviceNames.GetSize() == 0) {
     POrdinalToString vid;
     ReadDeviceDirectory("/dev/", vid);
 
     for (PINDEX i = 0; i < vid.GetSize(); i++) {
       PINDEX cardnum = vid.GetKeyAt(i);
-      int fd = ::open(vid[cardnum], O_RDONLY | O_NONBLOCK);
+      int fd = ::v4l1_open(vid[cardnum], O_RDONLY | O_NONBLOCK);
       if ((fd >= 0) || (errno == EBUSY)) {
         if (fd >= 0)
-          ::close(fd);
+          ::v4l1_close(fd);
         inputDeviceNames += vid[cardnum];
       }
     }
@@ -411,18 +442,18 @@
 {
   PString Result;
 
-  int fd = ::open((const char *)devname, O_RDONLY);
+  int fd = ::v4l1_open((const char *)devname, O_RDONLY);
   if(fd < 0) {
     return devname;
   }
 
   struct video_capability videocap;
-  if (::ioctl(fd, VIDIOCGCAP, &videocap) < 0)  {
-      ::close(fd);
+  if (::v4l1_ioctl(fd, VIDIOCGCAP, &videocap) < 0)  {
+      ::v4l1_close(fd);
       return devname;
     }
   
-  ::close(fd);
+  ::v4l1_close(fd);
   PString ufname(videocap.name);  
 
   return ufname;
@@ -515,7 +546,7 @@
   // check if it is a userfriendly name, and if so, get the real device name
 
   PString deviceName = GetNames().GetDeviceName(devName);
-  videoFd = ::open((const char *)deviceName, O_RDWR);
+  videoFd = ::v4l1_open((const char *)deviceName, O_RDWR);
   if (videoFd < 0) {
     PTRACE(1,"PVideoInputDevice_V4L::Open failed : "<< ::strerror(errno));
     return PFalse;
@@ -523,14 +554,14 @@
   
   // get the device capabilities
   if (!RefreshCapabilities()) {
-    ::close (videoFd);
+    ::v4l1_close (videoFd);
     videoFd = -1;
     return PFalse;
   }
   
   if ((videoCapability.type & VID_TYPE_CAPTURE) == 0) {
     PTRACE(1,"PVideoInputDevice_V4L:: device capablilities reports cannot capture");
-    ::close (videoFd);
+    ::v4l1_close (videoFd);
     videoFd = -1;
     return PFalse;
   }
@@ -579,7 +610,7 @@
   if (hint_index >= PARRAYSIZE(driver_hints)-1) {
      struct video_channel channel;
      memset(&channel, 0, sizeof(struct video_channel));
-     if (::ioctl(videoFd, VIDIOCGCHAN, &channel) == 0) {
+     if (::v4l1_ioctl(videoFd, VIDIOCGCHAN, &channel) == 0) {
 	/* Only check if the called doesn't return an error */
 	for (tbl = 0; tbl < PARRAYSIZE(bridges_with_640x480_fixed_width); tbl ++) {
 	   if (strcmp(bridges_with_640x480_fixed_width[tbl], channel.name) == 0) {
@@ -609,7 +640,7 @@
 #define VIDIOCQCSCOMPATIBLE     _IOWR('v',QC_IOCTLBASE+10,int)  /* Set enable workaround for bugs, bitfield */
 
     int reg = 2; /* enable double buffering */
-    ::ioctl (videoFd, VIDIOCQCSCOMPATIBLE, &reg);
+    ::v4l1_ioctl (videoFd, VIDIOCQCSCOMPATIBLE, &reg);
   }
 
     
@@ -620,11 +651,11 @@
 
   // Init audio
   struct video_audio videoAudio;
-  if (::ioctl(videoFd, VIDIOCGAUDIO, &videoAudio) >= 0 &&
+  if (::v4l1_ioctl(videoFd, VIDIOCGAUDIO, &videoAudio) >= 0 &&
                       (videoAudio.flags & VIDEO_AUDIO_MUTABLE) != 0) {
     videoAudio.flags &= ~VIDEO_AUDIO_MUTE;
     videoAudio.mode = VIDEO_SOUND_MONO;
-    ::ioctl(videoFd, VIDIOCSAUDIO, &videoAudio);
+    ::v4l1_ioctl(videoFd, VIDIOCSAUDIO, &videoAudio);
     } 
 
   return PTrue;
@@ -645,14 +676,14 @@
 
   // Mute audio
   struct video_audio videoAudio;
-  if (::ioctl(videoFd, VIDIOCGAUDIO, &videoAudio) >= 0 &&
+  if (::v4l1_ioctl(videoFd, VIDIOCGAUDIO, &videoAudio) >= 0 &&
                       (videoAudio.flags & VIDEO_AUDIO_MUTABLE) != 0) {
     videoAudio.flags |= VIDEO_AUDIO_MUTE;
-    ::ioctl(videoFd, VIDIOCSAUDIO, &videoAudio);
+    ::v4l1_ioctl(videoFd, VIDIOCSAUDIO, &videoAudio);
   }
 
   ClearMapping();
-  ::close(videoFd);
+  ::v4l1_close(videoFd);
 
   videoFd = -1;
   canMap  = -1;
@@ -703,7 +734,7 @@
 
   struct video_channel channel;
   channel.channel = channelNumber;
-  if (::ioctl(videoFd, VIDIOCGCHAN, &channel) < 0) {
+  if (::v4l1_ioctl(videoFd, VIDIOCGCHAN, &channel) < 0) {
     PTRACE(1,"VideoInputDevice Get Channel info failed : "<< ::strerror(errno));    
     return PFalse;
   }
@@ -714,7 +745,7 @@
   channel.norm = fmt[newFormat];
 
   // set the information
-  if (::ioctl(videoFd, VIDIOCSCHAN, &channel) >= 0) {
+  if (::v4l1_ioctl(videoFd, VIDIOCSCHAN, &channel) >= 0) {
     // format change might affect frame size limits; grab them again
     RefreshCapabilities();
     return PTrue;
@@ -754,7 +785,7 @@
   // get channel information (to check if channel is valid)
   struct video_channel channel;
   channel.channel = channelNumber;
-  if (::ioctl(videoFd, VIDIOCGCHAN, &channel) < 0) {
+  if (::v4l1_ioctl(videoFd, VIDIOCGCHAN, &channel) < 0) {
     PTRACE(1,"VideoInputDevice:: Get info on channel " << channelNumber << " failed : "<< ::strerror(errno));    
     return PFalse;
   }
@@ -763,7 +794,7 @@
   channel.channel = channelNumber;
 
   // set the information
-  if (::ioctl(videoFd, VIDIOCSCHAN, &channel) < 0) {
+  if (::v4l1_ioctl(videoFd, VIDIOCSCHAN, &channel) < 0) {
     PTRACE(1,"VideoInputDevice:: Set info on channel " << channelNumber << " failed : "<< ::strerror(errno));    
     return PFalse;
   }
@@ -792,7 +823,7 @@
   // get channel information (to check if channel is valid)
   struct video_channel channel;
   channel.channel = channelNumber;
-  if (::ioctl(videoFd, VIDIOCGCHAN, &channel) < 0) {
+  if (::v4l1_ioctl(videoFd, VIDIOCGCHAN, &channel) < 0) {
     PTRACE(1,"VideoInputDevice Get Channel info failed : "<< ::strerror(errno));    
 
     return PFalse;
@@ -803,7 +834,7 @@
   channel.channel = channelNumber;
 
   // set the information
-  if (::ioctl(videoFd, VIDIOCSCHAN, &channel) < 0) {
+  if (::v4l1_ioctl(videoFd, VIDIOCSCHAN, &channel) < 0) {
     PTRACE(1,"VideoInputDevice SetChannel failed : "<< ::strerror(errno));  
 
     return PFalse;
@@ -830,7 +861,7 @@
 
   // get current picture information
   struct video_picture pictureInfo;
-  if (::ioctl(videoFd, VIDIOCGPICT, &pictureInfo) < 0) {
+  if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &pictureInfo) < 0) {
     PTRACE(1,"PVideoInputDevice_V4L::Get pict info failed : "<< ::strerror(errno));
     return PFalse;
   }
@@ -842,7 +873,7 @@
     pictureInfo.depth = 16;
 
   // set the information
-  if (::ioctl(videoFd, VIDIOCSPICT, &pictureInfo) < 0) {
+  if (::v4l1_ioctl(videoFd, VIDIOCSPICT, &pictureInfo) < 0) {
     PTRACE(1,"PVideoInputDevice_V4L::Set pict info failed : "<< ::strerror(errno));
     PTRACE(1,"PVideoInputDevice_V4L:: used code of "<<colourFormatCode);
     PTRACE(1,"PVideoInputDevice_V4L:: palette: "<<colourFormatTab[colourFormatIndex].colourFormat);
@@ -871,7 +902,7 @@
 
   // Some V4L drivers can't use CGPICT to check for errors.
   if (!HINT(HINT_CGPICT_DOESNT_SET_PALETTE)) {
-    if (::ioctl(videoFd, VIDIOCGPICT, &pictureInfo) < 0) {
+    if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &pictureInfo) < 0) {
       PTRACE(1,"PVideoInputDevice_V4L::Get pict info failed : "<< ::strerror(errno));
       return PFalse;
     }
@@ -959,12 +990,12 @@
 {
   if (canMap < 0) {
     //When canMap is < 0, it is the first use of GetFrameData. Check for memory mapping.
-    if (::ioctl(videoFd, VIDIOCGMBUF, &frame) < 0) {
+    if (::v4l1_ioctl(videoFd, VIDIOCGMBUF, &frame) < 0) {
       canMap=0;
       PTRACE(3, "VideoGrabber " << deviceName << " cannot do memory mapping - GMBUF failed.");
       //This video device cannot do memory mapping.
     } else {
-      videoBuffer = (BYTE *)::mmap(0, frame.size, PROT_READ|PROT_WRITE, MAP_SHARED, videoFd, 0);
+      videoBuffer = (BYTE *)::v4l1_mmap(0, frame.size, PROT_READ|PROT_WRITE, MAP_SHARED, videoFd, 0);
      
       if (videoBuffer < 0) {
         canMap = 0;
@@ -985,7 +1016,7 @@
 
         currentFrame = 0;
         int ret;
-        ret = ::ioctl(videoFd, VIDIOCMCAPTURE, &frameBuffer[currentFrame]);
+        ret = ::v4l1_ioctl(videoFd, VIDIOCMCAPTURE, &frameBuffer[currentFrame]);
         if (ret < 0) {
           PTRACE(1,"PVideoInputDevice_V4L::GetFrameData mcapture1 failed : " << ::strerror(errno));
           ClearMapping();  
@@ -1029,7 +1060,7 @@
   // fallback to read() on errors.
   int ret = -1;
   
-  ret = ::ioctl(videoFd, VIDIOCMCAPTURE, &frameBuffer[ 1 - currentFrame ]);
+  ret = ::v4l1_ioctl(videoFd, VIDIOCMCAPTURE, &frameBuffer[ 1 - currentFrame ]);
   if ( ret < 0 ) {
     PTRACE(1,"PVideoInputDevice_V4L::GetFrameData mcapture2 failed : " << ::strerror(errno));
     ClearMapping();
@@ -1042,7 +1073,7 @@
   // device does support memory mapping, get data
 
   // wait for the frame to load. 
-  ret = ::ioctl(videoFd, VIDIOCSYNC, &currentFrame);
+  ret = ::v4l1_ioctl(videoFd, VIDIOCSYNC, &currentFrame);
   pendingSync[currentFrame] = PFalse;    
   if (ret < 0) {
     PTRACE(1,"PVideoInputDevice_V4L::GetFrameData csync failed : " << ::strerror(errno));
@@ -1077,7 +1108,7 @@
    ret = -1;
    while (ret < 0) {
 
-     ret = ::read(videoFd, resultBuffer, frameBytes);
+     ret = ::v4l1_read(videoFd, resultBuffer, frameBytes);
      if ((ret < 0) && (errno == EINTR))
        continue;
     
@@ -1108,12 +1139,12 @@
   if ((canMap == 1) && (videoBuffer != NULL)) {
     for (int i=0; i<2; i++) {
       if (pendingSync[i]) {
-        int res = ::ioctl(videoFd, VIDIOCSYNC, &i);
+        int res = ::v4l1_ioctl(videoFd, VIDIOCSYNC, &i);
         if (res < 0) 
           PTRACE(1,"PVideoInputDevice_V4L::GetFrameData csync failed : " << ::strerror(errno));
           pendingSync[i] = PFalse;    
         }
-        ::munmap(videoBuffer, frame.size);
+        ::v4l1_munmap(videoBuffer, frame.size);
     }
   }
   
@@ -1154,7 +1185,7 @@
   }
   
   // Request current hardware frame size
-  if (::ioctl(videoFd, VIDIOCGWIN, &vwin) < 0) {
+  if (::v4l1_ioctl(videoFd, VIDIOCGWIN, &vwin) < 0) {
     PTRACE(3,"PVideoInputDevice_V4L\t VerifyHardwareFrameSize VIDIOCGWIN1 error::" << ::strerror(errno));
     return PFalse;
   }
@@ -1172,10 +1203,10 @@
     vwin.flags = 0;
   }
   
-  ::ioctl(videoFd, VIDIOCSWIN, &vwin);
+  ::v4l1_ioctl(videoFd, VIDIOCSWIN, &vwin);
   
   // Read back settings to be careful about existing (broken) V4L drivers
-  if (::ioctl(videoFd, VIDIOCGWIN, &vwin) < 0) {
+  if (::v4l1_ioctl(videoFd, VIDIOCGWIN, &vwin) < 0) {
     PTRACE(3,"PVideoInputDevice_V4L\t VerifyHardwareFrameSize VIDIOCGWIN2 error::" << ::strerror(errno));
     return PFalse;
   }
@@ -1195,7 +1226,7 @@
 
   struct video_picture vp;
 
-  if (::ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
     return -1;
   frameBrightness = vp.brightness;
 
@@ -1210,7 +1241,7 @@
 
   struct video_picture vp;
 
-  if (::ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
     return -1;
   frameWhiteness = vp.whiteness;
 
@@ -1224,7 +1255,7 @@
 
   struct video_picture vp;
 
-  if (::ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
     return -1;
   frameColour = vp.colour;
 
@@ -1240,7 +1271,7 @@
 
   struct video_picture vp;
 
-  if (::ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
     return -1;
   frameContrast = vp.contrast;
 
@@ -1254,7 +1285,7 @@
 
   struct video_picture vp;
 
-  if (::ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
     return -1;
   frameHue = vp.hue;
 
@@ -1268,11 +1299,11 @@
 
   struct video_picture vp;
 
-  if (::ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
     return PFalse;
 
   vp.brightness = newBrightness;
-  if (::ioctl(videoFd, VIDIOCSPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCSPICT, &vp) < 0)
     return PFalse;
 
   frameBrightness=newBrightness;
@@ -1285,11 +1316,11 @@
 
   struct video_picture vp;
 
-  if (::ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
     return PFalse;
 
   vp.whiteness = newWhiteness;
-  if (::ioctl(videoFd, VIDIOCSPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCSPICT, &vp) < 0)
     return PFalse;
 
   frameWhiteness = newWhiteness;
@@ -1303,11 +1334,11 @@
 
   struct video_picture vp;
 
-  if (::ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
     return PFalse;
 
   vp.colour = newColour;
-  if (::ioctl(videoFd, VIDIOCSPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCSPICT, &vp) < 0)
     return PFalse;
 
   frameColour = newColour;
@@ -1320,11 +1351,11 @@
 
   struct video_picture vp;
 
-  if (::ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
     return PFalse;
 
   vp.contrast = newContrast;
-  if (::ioctl(videoFd, VIDIOCSPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCSPICT, &vp) < 0)
     return PFalse;
 
   frameContrast = newContrast;
@@ -1338,11 +1369,11 @@
 
   struct video_picture vp;
 
-  if (::ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
     return PFalse;
 
   vp.hue = newHue;
-  if (::ioctl(videoFd, VIDIOCSPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCSPICT, &vp) < 0)
     return PFalse;
 
    frameHue=newHue; 
@@ -1357,7 +1388,7 @@
 
   struct video_picture vp;
 
-  if (::ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
+  if (::v4l1_ioctl(videoFd, VIDIOCGPICT, &vp) < 0)
     {
       PTRACE(3, "GetParams bombs out!");
       return PFalse;
@@ -1385,7 +1416,7 @@
 
 PBoolean PVideoInputDevice_V4L::RefreshCapabilities()
 {
-  if (::ioctl(videoFd, VIDIOCGCAP, &videoCapability) < 0)  {
+  if (::v4l1_ioctl(videoFd, VIDIOCGCAP, &videoCapability) < 0)  {
     PTRACE(1,"PVideoInputV4lDevice:: get device capablilities failed : "<< ::strerror(errno));
     return PFalse;
   }
