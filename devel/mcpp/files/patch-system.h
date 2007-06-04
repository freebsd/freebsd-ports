Place this text as ports/devel/mcpp/files/patch-src-system.H.
I copy and paste the file here, since attaching file does not work somehow.
TABs are lost in this.  Please en-tab in the first two tag-lines.

--- src/system.H.orig   Wed May  2 21:37:29 2007
+++ src/system.H        Sun Jun  3 16:51:33 2007
@@ -49,7 +49,16 @@
 
 /* Some system has a wrong definition of UCHAR_MAX.  See cpp-test.html#5.1.3 */
 #if     UCHARMAX < -255
+#if     __FreeBSD__
+/*
+ * This is a temporary patch for FreeBSD on amd64, alpha, ia64 and sparc64.
+ * limits.h of these systems wrongly define UCHAR_MAX as 255U.
+ */
+#undef  UCHARMAX
+#define UCHARMAX 255
+#else
 #error  "The definition of UCHARMAX (possibly UCHAR_MAX too) is wrong.  Define it as signed int value as 255, not as unsigned value as 255U."
+#endif
 #endif
 
 /*


