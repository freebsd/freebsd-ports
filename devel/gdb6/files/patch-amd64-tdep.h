--- gdb/amd64-tdep.h.orig	Wed May  5 10:48:28 2004
+++ gdb/amd64-tdep.h	Wed May  5 11:02:33 2004
@@ -59,6 +59,13 @@
 /* Number of general purpose registers.  */
 #define AMD64_NUM_GREGS		24
 
+#define AMD64_NUM_FREGS		16
+#define AMD64_NUM_XREGS		17
+#define AMD64_NUM_REGS_TOTAL	(AMD64_NUM_GREGS + AMD64_NUM_FREGS \
+				 + AMD64_NUM_XREGS)
+
+extern int amd64_num_regs (void);
+
 extern void amd64_init_abi (struct gdbarch_info info, struct gdbarch *gdbarch);
 
 /* Fill register REGNUM in REGCACHE with the appropriate
