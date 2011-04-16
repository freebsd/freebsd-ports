--- GSCache.m.orig	2011-03-03 11:51:46.000000000 +0100
+++ GSCache.m	2011-04-15 20:46:35.000000000 +0200
@@ -51,6 +51,8 @@
 #if (MAC_OS_X_VERSION_MAX_ALLOWED <= MAC_OS_X_VERSION_10_4)
 #define class_getInstanceSize(isa)  ((struct objc_class *)isa)->instance_size
 #endif
+#else
+#define class_getInstanceSize(isa)  ((struct objc_class *)isa)->instance_size
 #endif
 
 @interface	GSCache (Threading)
