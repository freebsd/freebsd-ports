--- gnat2why/smissing.c.orig	2014-04-10 15:20:38 UTC
+++ gnat2why/smissing.c
@@ -32,6 +32,15 @@
    allocation strategy for large objects in certain cases). */
 int flag_stack_check = 0;
 
+/* Controls the balance between GNAT encodings and standard DWARF to
+   emit in the debug information.  Useful for DWARF debugging information
+   generation only so not used in SPARK2014 */ 
+int gnat_encodings = 0;
+
+/* controlled by -fcompare-debug option on gcc, hardcode to 0 based on
+   comment above */
+int flag_compare_debug = 0;
+
 /*  Originally defined in GCC's toplev.c. */
 int optimize = 0;
 int optimize_size = 0;
