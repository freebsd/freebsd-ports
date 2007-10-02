--- regs.h.orig	2007-10-02 18:53:19.000000000 +0200
+++ regs.h	2007-10-02 18:53:55.000000000 +0200
@@ -3,6 +3,8 @@
 #ifndef __REGS_H
 #define __REGS_H
 
+#include "z80-asm.h"
+
 #define R_EMPTY 0
 #define R_A 1
 #define R_B 2
