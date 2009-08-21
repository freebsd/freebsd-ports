--- gcc/config/mips/allegrex.md.orig	1970-01-01 01:00:00.000000000 +0100
+++ gcc/config/mips/allegrex.md	2006-05-07 13:27:40.000000000 +0100
@@ -0,0 +1,183 @@
+;; Sony ALLEGREX instructions.
+;; Copyright (C) 2005 Free Software Foundation, Inc.
+;;
+;; This file is part of GCC.
+;;
+;; GCC is free software; you can redistribute it and/or modify
+;; it under the terms of the GNU General Public License as published by
+;; the Free Software Foundation; either version 2, or (at your option)
+;; any later version.
+;;
+;; GCC is distributed in the hope that it will be useful,
+;; but WITHOUT ANY WARRANTY; without even the implied warranty of
+;; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
+;; GNU General Public License for more details.
+;;
+;; You should have received a copy of the GNU General Public License
+;; along with GCC; see the file COPYING.  If not, write to
+;; the Free Software Foundation, 59 Temple Place - Suite 330,
+;; Boston, MA 02111-1307, USA.
+
+; Multiply Add and Subtract.
+
+(define_insn "allegrex_madd"
+  [(set (match_operand:SI 0 "register_operand" "+l")
+      	(plus:SI (mult:SI (match_operand:SI 1 "register_operand" "d")
+			  (match_operand:SI 2 "register_operand" "d"))
+		 (match_dup 0)))
+   (clobber (match_scratch:SI 3 "=h"))]
+  "TARGET_ALLEGREX"
+  "madd\t%1,%2"
+  [(set_attr "type"	"imadd")
+   (set_attr "mode"	"SI")])
+
+(define_insn "allegrex_msub"
+  [(set (match_operand:SI 0 "register_operand" "+l")
+      	(minus:SI (match_dup 0)
+		  (mult:SI (match_operand:SI 1 "register_operand" "d")
+			   (match_operand:SI 2 "register_operand" "d"))))
+   (clobber (match_scratch:SI 3 "=h"))]
+  "TARGET_ALLEGREX"
+  "msub\t%1,%2"
+  [(set_attr "type"	"imadd")
+   (set_attr "mode"	"SI")])
+
+
+; Min and max.
+
+(define_insn "sminsi3"
+  [(set (match_operand:SI 0 "register_operand" "=d")
+        (smin:SI (match_operand:SI 1 "register_operand" "d")
+                 (match_operand:SI 2 "register_operand" "d")))]
+  "TARGET_ALLEGREX"
+  "min\t%0,%1,%2"
+  [(set_attr "type"	"arith")
+   (set_attr "mode"	"SI")])
+
+(define_insn "smaxsi3"
+  [(set (match_operand:SI 0 "register_operand" "=d")
+        (smax:SI (match_operand:SI 1 "register_operand" "d")
+                 (match_operand:SI 2 "register_operand" "d")))]
+  "TARGET_ALLEGREX"
+  "max\t%0,%1,%2"
+  [(set_attr "type"	"arith")
+   (set_attr "mode"	"SI")])
+
+
+; Extended shift instructions.
+
+(define_insn "allegrex_bitrev"
+  [(set (match_operand:SI 0 "register_operand" "=d")
+	(unspec:SI [(match_operand:SI 1 "register_operand" "d")]
+		   UNSPEC_BITREV))]
+  "TARGET_ALLEGREX"
+  "bitrev\t%0,%1"
+  [(set_attr "type"	"arith")
+   (set_attr "mode"	"SI")])
+
+(define_insn "allegrex_wsbh"
+  [(set (match_operand:SI 0 "register_operand" "=d")
+	(unspec:SI [(match_operand:SI 1 "register_operand" "d")]
+		   UNSPEC_WSBH))]
+  "TARGET_ALLEGREX"
+  "wsbh\t%0,%1"
+  [(set_attr "type"	"arith")
+   (set_attr "mode"	"SI")])
+
+(define_insn "allegrex_wsbw"
+  [(set (match_operand:SI 0 "register_operand" "=d")
+	(unspec:SI [(match_operand:SI 1 "register_operand" "d")]
+		   UNSPEC_WSBW))]
+  "TARGET_ALLEGREX"
+  "wsbw\t%0,%1"
+  [(set_attr "type"	"arith")
+   (set_attr "mode"	"SI")])
+
+
+; Count leading ones, count trailing zeros, and count trailing ones (clz is
+; already defined).
+
+(define_insn "allegrex_clo"
+  [(set (match_operand:SI 0 "register_operand" "=d")
+      	(unspec:SI [(match_operand:SI 1 "register_operand" "d")]
+		   UNSPEC_CLO))]
+  "TARGET_ALLEGREX"
+  "clo\t%0,%1"
+  [(set_attr "type"	"clz")
+   (set_attr "mode"	"SI")])
+
+(define_expand "ctzsi2"
+  [(set (match_operand:SI 0 "register_operand")
+      	(ctz:SI (match_operand:SI 1 "register_operand")))]
+  "TARGET_ALLEGREX"
+{
+  rtx r1;
+
+  r1 = gen_reg_rtx (SImode);
+  emit_insn (gen_allegrex_bitrev (r1, operands[1]));
+  emit_insn (gen_clzsi2 (operands[0], r1));
+  DONE;
+})
+
+(define_expand "allegrex_cto"
+  [(set (match_operand:SI 0 "register_operand")
+      	(unspec:SI [(match_operand:SI 1 "register_operand")]
+		   UNSPEC_CTO))]
+  "TARGET_ALLEGREX"
+{
+  rtx r1;
+
+  r1 = gen_reg_rtx (SImode);
+  emit_insn (gen_allegrex_bitrev (r1, operands[1]));
+  emit_insn (gen_allegrex_clo (operands[0], r1));
+  DONE;
+})
+
+
+; Misc.
+
+(define_insn "allegrex_sync"
+  [(unspec_volatile [(const_int 0)] UNSPEC_SYNC)]
+  "TARGET_ALLEGREX"
+  "sync"
+  [(set_attr "type"	"unknown")
+   (set_attr "mode"	"none")])
+
+(define_insn "allegrex_cache"
+  [(unspec_volatile [(match_operand:SI 0 "const_int_operand" "")
+		     (match_operand:SI 1 "register_operand" "d")]
+		    UNSPEC_CACHE)]
+  "TARGET_ALLEGREX"
+  "cache\t%0,0(%1)"
+  [(set_attr "type"	"unknown")
+   (set_attr "mode"	"none")])
+
+
+; Floating-point builtins.
+
+(define_insn "allegrex_ceil_w_s"
+  [(set (match_operand:SI 0 "register_operand" "=f")
+      	(unspec:SI [(match_operand:SF 1 "register_operand" "f")]
+		   UNSPEC_CEIL_W_S))]
+  "TARGET_ALLEGREX"
+  "ceil.w.s\t%0,%1"
+  [(set_attr "type"	"fcvt")
+   (set_attr "mode"	"SF")])
+
+(define_insn "allegrex_floor_w_s"
+  [(set (match_operand:SI 0 "register_operand" "=f")
+      	(unspec:SI [(match_operand:SF 1 "register_operand" "f")]
+		   UNSPEC_FLOOR_W_S))]
+  "TARGET_ALLEGREX"
+  "floor.w.s\t%0,%1"
+  [(set_attr "type"	"fcvt")
+   (set_attr "mode"	"SF")])
+
+(define_insn "allegrex_round_w_s"
+  [(set (match_operand:SI 0 "register_operand" "=f")
+      	(unspec:SI [(match_operand:SF 1 "register_operand" "f")]
+		   UNSPEC_ROUND_W_S))]
+  "TARGET_ALLEGREX"
+  "round.w.s\t%0,%1"
+  [(set_attr "type"	"fcvt")
+   (set_attr "mode"	"SF")])
