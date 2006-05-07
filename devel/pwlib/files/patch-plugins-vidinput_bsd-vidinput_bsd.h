--- plugins/vidinput_bsd/vidinput_bsd.h.orig	Tue Aug  9 11:08:09 2005
+++ plugins/vidinput_bsd/vidinput_bsd.h	Thu Apr  6 09:37:11 2006
@@ -1,13 +1,24 @@
+#ifndef _PVIDEOIOBSDCAPTURE
 
-//#include <sys/mman.h>
-//#include <sys/time.h>
+#define _PVIDEOIOBSDCAPTURE
+
+#ifdef __GNUC__   
+#pragma interface
+#endif
+
+#include <sys/mman.h>
 
 #include <ptlib.h>
 #include <ptlib/videoio.h>
 #include <ptlib/vconvert.h>
 
 #if defined(P_FREEBSD)
+#include <sys/param.h>
+# if __FreeBSD_version >= 502100
+#include <dev/bktr/ioctl_meteor.h>
+# else
 #include <machine/ioctl_meteor.h>
+# endif
 #endif
 
 #if defined(P_OPENBSD) || defined(P_NETBSD)
@@ -20,19 +30,24 @@
 #endif
 #endif
 
-class PVideoInputDevice_BSDCAPTURE: public PVideoInputDevice
+#if !P_USE_INLINES
+#include <ptlib/contain.inl>
+#endif
+
+
+class PVideoInputDevice_BSDCAPTURE : public PVideoInputDevice
 {
 
+  PCLASSINFO(PVideoInputDevice_BSDCAPTURE, PVideoInputDevice);
+
 public:
   PVideoInputDevice_BSDCAPTURE();
   ~PVideoInputDevice_BSDCAPTURE();
 
-  static PStringList GetInputDeviceNames();
-
-  PStringList GetDeviceNames() const
-  { return GetInputDeviceNames(); }
-
-  BOOL Open(const PString &deviceName, BOOL startImmediate);
+  BOOL Open(
+    const PString &deviceName,
+    BOOL startImmediate = TRUE
+  );
 
   BOOL IsOpen();
 
@@ -43,11 +58,24 @@
 
   BOOL IsCapturing();
 
+  static PStringList GetInputDeviceNames();
+
+  PStringList GetDeviceNames() const
+  { return GetInputDeviceNames(); }
+
   PINDEX GetMaxFrameBytes();
 
-  BOOL GetFrame(PBYTEArray & frame);
-  BOOL GetFrameData(BYTE*, PINDEX*);
-  BOOL GetFrameDataNoDelay(BYTE*, PINDEX*);
+//  BOOL GetFrame(
+//    PBYTEArray & frame
+//  );
+  BOOL GetFrameData(
+    BYTE * buffer,
+    PINDEX * bytesReturned = NULL
+  );
+  BOOL GetFrameDataNoDelay(
+    BYTE * buffer,
+    PINDEX * bytesReturned = NULL
+  );
 
   BOOL GetFrameSizeLimits(unsigned int&, unsigned int&,
 			  unsigned int&, unsigned int&);
@@ -99,3 +127,5 @@
   int    mmap_size;
  
 };
+
+#endif
