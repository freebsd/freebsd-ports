--- bfd/aout-arm.c.orig	Mon Aug 21 10:22:41 2000
+++ bfd/aout-arm.c	Mon Aug 21 10:23:42 2000
@@ -20,13 +20,13 @@
 
 
 #define N_TXTADDR(x) \
-  ((N_MAGIC(x) == NMAGIC) ? 0x8000 : \
+  ((N_MAGIC(x) == NMAGIC) ? 0x0000 : \
    (N_MAGIC(x) != ZMAGIC) ? 0 : \
    (N_SHARED_LIB(x)) ? ((x).a_entry & ~(TARGET_PAGE_SIZE - 1)) : \
    TEXT_START_ADDR)
 
-#define TEXT_START_ADDR 0x8000
-#define TARGET_PAGE_SIZE 0x8000
+#define TEXT_START_ADDR 0x0000
+#define TARGET_PAGE_SIZE 0x1000
 #define SEGMENT_SIZE TARGET_PAGE_SIZE
 #define DEFAULT_ARCH bfd_arch_arm
 
