--- target.make.orig	Thu May 10 22:07:23 2001
+++ target.make	Tue Jun  5 09:26:45 2001
@@ -79,8 +79,8 @@
   ifeq ("$(objc_threaded)","")
     TARGET_SYSTEM_LIBS := $(CONFIG_SYSTEM_LIBS) -lm
   else
-    INTERNAL_CFLAGS = -D_REENTRANT
-    INTERNAL_OBJCFLAGS = -D_REENTRANT
+    INTERNAL_CFLAGS = -D_REENTRANT -D_THREAD_SAFE
+    INTERNAL_OBJCFLAGS = -D_REENTRANT -D_THREAD_SAFE
     TARGET_SYSTEM_LIBS := $(CONFIG_SYSTEM_LIBS) $(objc_threaded) -lm
   endif
 endif
