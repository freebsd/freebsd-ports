--- dispatch/glproc_egl.cpp.orig	2019-11-26 14:27:11 UTC
+++ dispatch/glproc_egl.cpp
@@ -93,7 +93,7 @@ _getPublicProcAddress(const char *procName)
     if (procName[0] == 'e' && procName[1] == 'g' && procName[2] == 'l') {
         static void *libEGL = NULL;
         if (!libEGL) {
-            libEGL = _dlopen("libEGL.so", RTLD_LOCAL | RTLD_LAZY | RTLD_DEEPBIND);
+            libEGL = _dlopen("libEGL.so", RTLD_LOCAL | RTLD_LAZY);
             if (!libEGL) {
                 return NULL;
             }
@@ -136,7 +136,7 @@ _getPublicProcAddress(const char *procName)
 
         static void *libGLESv2 = NULL;
         if (!libGLESv2) {
-            libGLESv2 = _dlopen("libGLESv2.so", RTLD_LOCAL | RTLD_LAZY | RTLD_DEEPBIND);
+            libGLESv2 = _dlopen("libGLESv2.so", RTLD_LOCAL | RTLD_LAZY);
         }
         if (libGLESv2) {
             proc = dlsym(libGLESv2, procName);
@@ -147,7 +147,7 @@ _getPublicProcAddress(const char *procName)
 
         static void *libGLESv1 = NULL;
         if (!libGLESv1) {
-            libGLESv1 = _dlopen("libGLESv1_CM.so", RTLD_LOCAL | RTLD_LAZY | RTLD_DEEPBIND);
+            libGLESv1 = _dlopen("libGLESv1_CM.so", RTLD_LOCAL | RTLD_LAZY);
         }
         if (libGLESv1) {
             proc = dlsym(libGLESv1, procName);
