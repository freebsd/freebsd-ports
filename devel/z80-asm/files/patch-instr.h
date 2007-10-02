--- instr.h.orig	2007-10-02 18:55:31.000000000 +0200
+++ instr.h	2007-10-02 18:55:46.000000000 +0200
@@ -3,6 +3,8 @@
 #ifndef __INSTR_H
 #define __INSTR_H
 
+#include "z80-asm.h"
+
 #define I_DEFS 71
 #define I_DEFW 70
 #define I_DEFB 69
