--- riscv/insn_template.cc.orig	2016-08-01 15:40:47 UTC
+++ riscv/insn_template.cc
@@ -1,6 +1,6 @@
 // See LICENSE for license details.
 
-#include "insn_template.h"
+#include "insn_template.hpp"
 
 reg_t rv32_NAME(processor_t* p, insn_t insn, reg_t pc)
 {
