--- ikvm-native/jni.c.orig	Thu May  5 17:53:25 2005
+++ ikvm-native/jni.c	Thu May  5 17:53:33 2005
@@ -28,7 +28,9 @@
 #include <malloc.h>
 #define ALLOCA _alloca
 #else
-#if !defined(__FreeBSD__) && !defined(__NetBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
+#include <stdlib.h>
+#else
 #include <alloca.h>
 #endif
 #define ALLOCA alloca
