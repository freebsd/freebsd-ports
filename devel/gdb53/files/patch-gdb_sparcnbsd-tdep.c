--- gdb/sparcnbsd-tdep.c.orig	Sat Aug 31 20:28:37 2002
+++ gdb/sparcnbsd-tdep.c	Thu Oct 17 06:30:25 2002
@@ -37,6 +37,8 @@
 #define REG32_OFFSET_Y		(3 * 4)
 #define REG32_OFFSET_GLOBAL	(4 * 4)
 #define REG32_OFFSET_OUT	(12 * 4)
+#define REG32_SIZE		(20 * 4)
+#define FPREG32_SIZE		(33 * 4)
 
 #define REG64_OFFSET_TSTATE	(0 * 8)
 #define REG64_OFFSET_PC		(1 * 8)
@@ -44,6 +46,11 @@
 #define REG64_OFFSET_Y		(3 * 8)
 #define REG64_OFFSET_GLOBAL	(4 * 8)
 #define REG64_OFFSET_OUT	(12 * 8)
+#define REG64_SIZE		(36 * 8)
+#define FPREG64_SIZE		((64 * 4) \
+				  + 8  /* fsr */ \
+				  + 4  /* gsr */ \
+				  + 4) /* pad */
 
 void
 sparcnbsd_supply_reg32 (char *regs, int regno)
@@ -375,16 +382,13 @@
 
   if (gdbarch_ptr_bit (current_gdbarch) == 32)
     {
-      reg_size = (20 * 4);
-      fpreg_size = (33 * 4);
+      reg_size = REG32_SIZE;
+      fpreg_size = FPREG32_SIZE;
     }
   else
     {
-      reg_size = (20 * 8);
-      fpreg_size = (64 * 4)
-        + 8  /* fsr */
-        + 4  /* gsr */
-        + 4; /* pad */
+      reg_size = REG64_SIZE;
+      fpreg_size = FPREG64_SIZE;
     }
 
   switch (which)
