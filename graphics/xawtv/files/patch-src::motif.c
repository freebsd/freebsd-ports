--- src/motif.c.orig	Mon Sep 17 00:42:53 2001
+++ src/motif.c	Mon Sep 17 00:45:40 2001
@@ -24,6 +24,19 @@
 # include <sys/soundcard.h>
 #endif
 
+#if defined(__FreeBSD__)
+typedef struct mixer_info
+{
+  char id[16];  
+  char name[32];
+  int  modify_counter;
+  int fillers[10];
+} mixer_info;
+
+
+# define SOUND_MIXER_INFO                _IOR ('M', 101, mixer_info)
+#endif
+
 #include <X11/Xlib.h>
 #include <X11/Intrinsic.h>
 #include <Xm/Xm.h>

