--- gdb/amd64-tdep.c.orig	Fri Apr  9 16:24:05 2004
+++ gdb/amd64-tdep.c	Wed May  5 10:56:22 2004
@@ -126,6 +126,12 @@
 #define AMD64_NUM_REGS \
   (sizeof (amd64_register_info) / sizeof (amd64_register_info[0]))
 
+int
+amd64_num_regs(void)
+{
+  return AMD64_NUM_REGS;
+}
+
 /* Return the name of register REGNUM.  */
 
 static const char *
