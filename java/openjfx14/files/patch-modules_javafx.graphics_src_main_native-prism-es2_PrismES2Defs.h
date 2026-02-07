--- modules/javafx.graphics/src/main/native-prism-es2/PrismES2Defs.h.orig	2020-07-17 10:21:33 UTC
+++ modules/javafx.graphics/src/main/native-prism-es2/PrismES2Defs.h
@@ -26,7 +26,7 @@
 #ifndef _Prism_es2_defs_h_
 #define _Prism_es2_defs_h_
 
-#if defined(SOLARIS) || defined(LINUX) || defined(ANDROID_NDK) /* SOLARIS || LINUX */
+#if defined(SOLARIS) || defined(LINUX) || defined(ANDROID_NDK) || defined(FREEBSD) /* SOLARIS || LINUX */
 #define GLX_GLEXT_PROTOTYPES
 #define GLX_GLXEXT_PROTOTYPES
 #define UNIX
