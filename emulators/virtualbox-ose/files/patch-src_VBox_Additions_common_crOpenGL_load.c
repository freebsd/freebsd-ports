--- src/VBox/Additions/common/crOpenGL/load.c.orig	2016-07-18 11:50:44 UTC
+++ src/VBox/Additions/common/crOpenGL/load.c
@@ -1123,7 +1123,7 @@ stubInit(void)
     return bRc;
 }
 
-#if defined(Linux) && !defined(VBOXOGL_FAKEDRI)
+#if (defined(Linux) || defined(FreeBSD)) && !defined(VBOXOGL_FAKEDRI)
 # include <dlfcn.h>
 /* We only support being used by GLX clients.  If the X server GLX extension
  * tries to use our OpenGL library it will fail, as it is written specifically
@@ -1136,7 +1136,7 @@ stubInit(void)
  * can do, better for GLX to fail than the whole X server).  To keep things as
  * simple and fail-safe as possible, we use a fixed path to the system GL
  * library. */
-#ifndef RTLD_DEEPBIND
+#if defined(Linux) && !defined(RTLD_DEEPBIND)
 # define RTLD_DEEPBIND 0x8
 #endif
 
@@ -1146,8 +1146,13 @@ void __attribute__ ((constructor)) check
 
     if (!pszDisplay || !*pszDisplay)
     {
+#ifdef Linux
         dlopen("/var/lib/VBoxGuestAdditions/lib/system/libGL.so.1", RTLD_LAZY | RTLD_GLOBAL | RTLD_DEEPBIND);
         dlopen("/var/lib/VBoxGuestAdditions/lib/system/libEGL.so.1", RTLD_LAZY | RTLD_GLOBAL | RTLD_DEEPBIND);
+#else
+        dlopen("/usr/local/lib/.mesa/libGL.so.1", RTLD_LAZY | RTLD_GLOBAL);
+        dlopen("/usr/local/lib/.mesa/libEGL.so.1", RTLD_LAZY | RTLD_GLOBAL);
+#endif
     }
 }
 #endif
