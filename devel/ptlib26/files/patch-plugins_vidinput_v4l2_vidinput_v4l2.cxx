--- plugins/vidinput_v4l2/vidinput_v4l2.cxx.orig	2009-09-20 20:25:31.000000000 -0400
+++ plugins/vidinput_v4l2/vidinput_v4l2.cxx	2010-01-27 14:28:45.000000000 -0500
@@ -48,6 +48,7 @@
 #include <libv4l2.h>
 #else
 #define v4l2_fd_open(fd, flags) (fd)
+#define v4l2_open open
 #define v4l2_close close
 #define v4l2_ioctl ioctl
 #define v4l2_read read
@@ -161,7 +162,7 @@
   PString name = GetNames().GetDeviceName(devName);
   PTRACE(1,"PVidInDev\tOpen()\tdevName:" << name << "  videoFd:" << videoFd);
   
-  videoFd = ::open((const char *)name, O_RDWR);
+  videoFd = ::v4l2_open((const char *)name, O_RDWR);
   if (videoFd < 0) {
     PTRACE(1,"PVidInDev\topen failed : " << ::strerror(errno));
     return PFalse;
@@ -977,6 +978,32 @@
 V4L2Names::Update()
 {
   PTRACE(1,"Detecting V4L2 devices");
+  PWaitAndSignal m(mutex);
+  inputDeviceNames.RemoveAll (); // flush the previous run
+#if defined(P_FREEBSD)
+  for (int i = 0; i < 10; i++) {
+    PString thisDevice = PString("/dev/video") + PString(i);
+    int videoFd=::v4l2_open((const char *)thisDevice, O_RDONLY | O_NONBLOCK);
+    if ((videoFd > 0) || (errno == EBUSY)) {
+      PBoolean valid = PFalse;
+      struct v4l2_capability videoCaps;
+      memset(&videoCaps,0,sizeof(videoCaps));
+      if ((errno == EBUSY) ||
+          (v4l2_ioctl(videoFd, VIDIOC_QUERYCAP, &videoCaps) >= 0 &&
+          (videoCaps.capabilities & V4L2_CAP_VIDEO_CAPTURE))) {
+        PTRACE(1,"PV4L2Plugin\tdetected capture device " << videoCaps.card);
+        valid = PTrue;
+      }
+      else {
+        PTRACE(1,"PV4L2Plugin\t" << thisDevice << "is not deemed valid");
+      }
+      if (videoFd>0)
+        ::v4l2_close(videoFd);
+      if(valid)
+        inputDeviceNames += thisDevice;
+    }
+  }
+#else
   PDirectory   procvideo2_4("/proc/video/dev");
   PDirectory   procvideo2_6("/sys/class/video4linux");
   PDirectory * procvideo;
@@ -996,8 +1023,6 @@
     kernelVersion=KUNKNOWN;
     procvideo=0;
   }
-  PWaitAndSignal m(mutex);
-  inputDeviceNames.RemoveAll (); // flush the previous run
   if (procvideo) {
     PTRACE(2,"PV4L2Plugin\tdetected device metadata at "<<*procvideo);
     if (((kernelVersion==K2_6 && procvideo->Open(PFileInfo::SubDirectory)) || 
@@ -1006,7 +1031,7 @@
         entry = procvideo->GetEntryName();
         if ((entry.Left(5) == "video")) {
           PString thisDevice = "/dev/" + entry;
-          int videoFd=::open((const char *)thisDevice, O_RDONLY | O_NONBLOCK);
+          int videoFd=::v4l2_open((const char *)thisDevice, O_RDONLY | O_NONBLOCK);
           if ((videoFd > 0) || (errno == EBUSY)) {
             PBoolean valid = PFalse;
             struct v4l2_capability videoCaps;
@@ -1021,7 +1046,7 @@
               PTRACE(1,"PV4L2Plugin\t" << thisDevice << "is not deemed valid");
             }
             if (videoFd>0)
-              ::close(videoFd);
+              ::v4l2_close(videoFd);
             if(valid)
               inputDeviceNames += thisDevice;
           }
@@ -1035,16 +1060,17 @@
   else {
     PTRACE(1,"Unable to detect v4l2 directory");
   }
+#endif
   if (inputDeviceNames.GetSize() == 0) {
     POrdinalToString vid;
     ReadDeviceDirectory("/dev/", vid);
 
     for (PINDEX i = 0; i < vid.GetSize(); i++) {
       PINDEX cardnum = vid.GetKeyAt(i);
-      int fd = ::open(vid[cardnum], O_RDONLY | O_NONBLOCK);
+      int fd = ::v4l2_open(vid[cardnum], O_RDONLY | O_NONBLOCK);
       if ((fd >= 0) || (errno == EBUSY)) {
         if (fd >= 0)
-          ::close(fd);
+          ::v4l2_close(fd);
         inputDeviceNames += vid[cardnum];
       }
     }
@@ -1056,7 +1082,7 @@
 {
   PString Result;
 
-  int fd = ::open((const char *)devname, O_RDONLY);
+  int fd = ::v4l2_open((const char *)devname, O_RDONLY);
   if(fd < 0) {
     return devname;
   }
@@ -1064,11 +1090,11 @@
   struct v4l2_capability videocap;
   memset(&videocap,0,sizeof(videocap));
   if (v4l2_ioctl(fd, VIDIOC_QUERYCAP, &videocap) < 0)  {
-      ::close(fd);
+      ::v4l2_close(fd);
       return devname;
     }
   
-  ::close(fd);
+  ::v4l2_close(fd);
   PString ufname((const char*)videocap.card);
 
   return ufname;
