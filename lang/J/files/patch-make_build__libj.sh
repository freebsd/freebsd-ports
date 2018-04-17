--- make/build_libj.sh.orig	2018-04-09 18:12:26 UTC
+++ make/build_libj.sh
@@ -1,7 +1,6 @@
 #!/usr/local/bin/bash
 # $1 is j32 or j64
-cd ~
-. jvars.sh
+. make/jvars.sh
 
 # gcc 5 vs 4 - killing off linux asm routines (overflow detection)
 # new fast code uses builtins not available in gcc 4
@@ -15,6 +14,8 @@ common="-fPIC -O1 -fno-if-conversion2 -f
 # clang
 # common="-Werror -fPIC -O1 -fwrapv -fno-strict-aliasing -Wextra -Wno-clobbered -Wno-maybe-uninitialized -Wno-unused-parameter -Wno-sign-compare -Wno-empty-body -Wno-unused-value -Wno-pointer-sign -Wno-parentheses -Wno-unsequenced -Wno-string-plus-int"
 darwin="-fPIC -O1 -fwrapv -fno-strict-aliasing -Wno-string-plus-int -Wno-empty-body -Wno-unsequenced -Wno-unused-value -Wno-pointer-sign -Wno-parentheses -Wno-return-type -Wno-constant-logical-operand -Wno-comment -Wno-unsequenced"
+freebsd="-fPIC -O1 -fwrapv -fno-strict-aliasing -Wno-string-plus-int -Wno-empty-body -Wno-unsequenced -Wno-unused-value -Wno-pointer-sign -Wno-parentheses -Wno-return-type -Wno-constant-logical-operand -Wno-comment -Wno-unsequenced"
+
 
 case $jplatform\_$1 in
 
@@ -50,6 +51,21 @@ TARGET=libj.dylib
 COMPILE="$darwin -mmacosx-version-min=10.5"
 LINK=" -dynamiclib -lm -ldl -mmacosx-version-min=10.5 -o libj.dylib"
 ;;
+
+freebsd_j32) # freebsd x86
+TARGET=libj.so
+# faster, but sse2 not available for 32-bit amd cpu
+# sse does not support mfpmath=sse in 32-bit gcc
+COMPILE="$freebsd -m32 -msse2 -mfpmath=sse -DC_NOMULTINTRINSIC "
+# slower, use 387 fpu and truncate extra precision
+# COMPILE="$freebsd -m32 -ffloat-store "
+LINK=" -shared -Wl,-soname,libj.so -m32 -lm -o libj.so "
+;;
+freebsd_j64) # freebsd x86
+TARGET=libj.so
+COMPILE="$freebsd -DC_NOMULTINTRINSIC "
+LINK=" -shared -Wl,-soname,libj.so -lm -o libj.so "
+;;
 *)
 echo no case for those parameters
 exit
