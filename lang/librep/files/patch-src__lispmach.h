--- src/lispmach.h.orig
+++ src/lispmach.h
@@ -475,7 +475,7 @@
 #ifdef __arm__
 #define PC_REG asm("r9")
 #define SP_REG asm("r8")
-#define SLOTS_REG asm("r7")
+#define SLOTS_REG asm("r10")
 #endif
 #endif
 
