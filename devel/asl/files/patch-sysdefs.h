--- sysdefs.h.orig	2020-12-16 16:17:40 UTC
+++ sysdefs.h
@@ -681,6 +681,30 @@
 #define NO_NLS
 #endif
 
+/*---------------------------------------------------------------------------*/
+/* POWER with FreeBSD */
+
+#ifdef __FreeBSD__
+#define ARCHSYSNAME "unknown-freebsd"
+#define DEFSMADE
+#define OPENRDMODE "r"
+#define OPENWRMODE "w"
+#define OPENUPMODE "r+"
+#define IEEEFLOAT
+typedef signed char Integ8;
+typedef unsigned char Card8;
+typedef signed short Integ16;
+typedef unsigned short Card16;
+#define HAS16
+typedef signed int Integ32;
+#define PRIInteg32 "d"
+typedef unsigned int Card32;
+typedef signed long long Integ64;
+typedef unsigned long long Card64;
+#define HAS64
+#define LOCALE_NLS
+#endif
+
 #endif /* _POWER */ 
 
 /*===========================================================================*/
@@ -865,16 +889,16 @@ typedef unsigned long Card64;
 #define OPENWRMODE "w"
 #define OPENUPMODE "r+"
 #define IEEEFLOAT
-typedef signed char Integ8;
-typedef unsigned char Card8;
-typedef signed short Integ16;
-typedef unsigned short Card16;
+typedef int8_t Integ8;
+typedef uint8_t Card8;
+typedef int16_t Integ16;
+typedef uint16_t Card16;
 #define HAS16
-typedef signed int Integ32;
-#define PRIInteg32 "d"
-typedef unsigned int Card32;
-typedef signed long Integ64;
-typedef unsigned long Card64;
+typedef uint32_t Integ32;
+#define PRIInteg32 PRId
+typedef uint32_t Card32;
+typedef int64_t Integ64;
+typedef uint65_t Card64;
 #define HAS64
 #define NO_NLS
 #endif
