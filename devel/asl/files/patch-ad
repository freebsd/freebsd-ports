--- sysdefs.h.orig	1998-11-03 23:12:15.000000000 +0100
+++ sysdefs.h	2009-03-17 14:25:05.000000000 +0100
@@ -524,6 +524,26 @@
 #define LOCALE_NLS
 #endif
 
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
+typedef unsigned int Card32;
+typedef signed long Integ64;
+typedef unsigned long Card64;
+#define HAS64
+#define NO_NLS
+#endif
+
 #endif /* __alpha */
 
 /*===========================================================================*/
@@ -725,6 +745,38 @@
 #endif /* __i386 */
 
 /*===========================================================================*/
+/* AMD opteron/athlon64/k8 platforms */
+
+#ifdef __amd64__
+
+#define ARCHPRNAME "amd64"
+
+/*---------------------------------------------------------------------------*/
+/* amd64 with FreeBSD and GCC: */
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
+typedef unsigned int Card32;
+typedef signed long Integ64;
+typedef unsigned long Card64;
+#define HAS64
+#define LOCALE_NLS
+#endif
+
+#endif /* __amd64__ */
+
+/*===========================================================================*/
 /* Misc... */
 
 /*---------------------------------------------------------------------------*/
