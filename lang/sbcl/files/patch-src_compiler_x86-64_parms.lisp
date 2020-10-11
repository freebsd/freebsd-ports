--- src/compiler/x86-64/parms.lisp.orig	2020-10-11 10:03:19 UTC
+++ src/compiler/x86-64/parms.lisp
@@ -178,8 +178,8 @@
 (defvar *binding-stack-pointer*)
 
 ;;; Bit indices into *CPU-FEATURE-BITS*
-(defconstant cpu-has-ymm-registers   1)
-(defconstant cpu-has-popcnt          2)
+(defconstant cpu-has-ymm-registers   0)
+(defconstant cpu-has-popcnt          1)
 
 (defconstant-eqx +static-symbols+
  `#(,@+common-static-symbols+
