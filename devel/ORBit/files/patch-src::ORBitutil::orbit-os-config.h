
$FreeBSD$

--- src/ORBitutil/orbit-os-config.h	2002/06/07 16:45:41	1.1
+++ src/ORBitutil/orbit-os-config.h	2002/06/07 16:46:08
@@ -1,7 +1,7 @@
 #ifndef OS_CONFIG_H
 #define OS_CONFIG_H 1
 
-#define ORBIT_HAVE_ALLOCA_H 0
+#undef ORBIT_HAVE_ALLOCA_H
 #define MAXIOV 1024
 
 #endif
