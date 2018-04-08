--- make/build_jdll.sh.orig	2018-02-24 19:49:42 UTC
+++ make/build_jdll.sh
@@ -1,7 +1,6 @@
 #!/usr/local/bin/bash
 # $1 is j32 or j64
-cd ~
-. jvars.sh
+. make/jvars.sh
 
 # gcc 5 vs 4 - killing off linux asm routines (overflow detection)
 # new fast code uses builtins not available in gcc 4
@@ -37,10 +36,10 @@ fi
 
 if [ "x$COMPILER" = x'gcc' ] ; then
 # gcc
-common="$OPENMP -fPIC -O1 -fwrapv -fno-strict-aliasing -Wextra -Wno-maybe-uninitialized -Wno-unused-parameter -Wno-sign-compare -Wno-clobbered -Wno-empty-body -Wno-unused-value -Wno-pointer-sign -Wno-parentheses -Wno-shift-negative-value"
+common="$OPENMP -fPIC -fwrapv -fno-strict-aliasing -Wextra -Wno-maybe-uninitialized -Wno-unused-parameter -Wno-sign-compare -Wno-clobbered -Wno-empty-body -Wno-unused-value -Wno-pointer-sign -Wno-parentheses -Wno-shift-negative-value"
 else
 # clang 3.5 .. 5.0
-common="$OPENMP -Werror -fPIC -O1 -fwrapv -fno-strict-aliasing -Wextra -Wno-consumed -Wno-uninitialized -Wno-unused-parameter -Wno-sign-compare -Wno-empty-body -Wno-unused-value -Wno-pointer-sign -Wno-parentheses -Wno-unsequenced -Wno-string-plus-int"
+common="$OPENMP -Werror -fPIC -fwrapv -fno-strict-aliasing -Wextra -Wno-consumed -Wno-uninitialized -Wno-unused-parameter -Wno-sign-compare -Wno-empty-body -Wno-unused-value -Wno-pointer-sign -Wno-parentheses -Wno-unsequenced -Wno-string-plus-int"
 fi
 darwin="$OPENMP -fPIC -O1 -fwrapv -fno-strict-aliasing -Wno-string-plus-int -Wno-empty-body -Wno-unsequenced -Wno-unused-value -Wno-pointer-sign -Wno-parentheses -Wno-return-type -Wno-constant-logical-operand -Wno-comment -Wno-unsequenced"
 
@@ -101,6 +100,29 @@ LINK=" -dynamiclib -lm -ldl $LDOPENMP -m
 OBJS_FMA=" blis/gemm_int-fma.o "
 ;;
 
+freebsd_j32) # freebsd x86
+TARGET=libj.so
+# faster, but sse2 not available for 32-bit amd cpu
+# sse does not support mfpmath=sse in 32-bit gcc
+COMPILE="$common -m32 -msse2 -mfpmath=sse -DC_NOMULTINTRINSIC "
+# slower, use 387 fpu and truncate extra precision
+# COMPILE="$common -m32 -ffloat-store "
+LINK=" -shared -Wl,-soname,libj.so -m32 -lm $LDOPENMP32 -o libj.so "
+;;
+
+freebsd_j64) # freebsd intel 64bit
+TARGET=libj.so
+COMPILE="$common $OPENMP "
+LINK=" -shared -Wl,-soname,libj.so -lm $LDOPENMP -o libj.so "
+;;
+
+freebsd_j64avx) # freebsd intel 64bit avx
+TARGET=libj.so
+COMPILE="$common -mavx -DC_AVX=1 $OPENMP "
+LINK=" -shared -Wl,-soname,libj.so -lm $LDOPENMP -o libj.so "
+OBJS_FMA=" blis/gemm_int-fma.o "
+;;
+
 windows_j32) # windows x86
 DLLOBJS=" jdll.o jdllcomx.o "
 LIBJDEF=" $jgit/dllsrc/jdll.def "
