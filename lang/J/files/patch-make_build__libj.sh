--- make/build_libj.sh.orig	2019-03-10 15:39:26 UTC
+++ make/build_libj.sh
@@ -1,6 +1,6 @@
 #!/usr/local/bin/bash
 # $1 is j32 or j64
-cd ~
+. make/jvars.sh
 
 # gcc 5 vs 4 - killing off linux asm routines (overflow detection)
 # new fast code uses builtins not available in gcc 4
@@ -14,7 +14,7 @@ if [ $USE_OPENMP -eq 1 ] ; then
 OPENMP=" -fopenmp "
 LDOPENMP=" -fopenmp "
 if [ "x$compiler" = x'gcc' ] ; then
-LDOPENMP32=" -l:libgomp.so.1 "    # gcc
+LDOPENMP32=" -l:libgomp.so "    # gcc
 else
 LDOPENMP32=" -l:libomp.so.5 "     # clang
 fi
@@ -92,6 +92,22 @@ TARGET=libj.dylib
 COMPILE="$darwin -mavx -mmacosx-version-min=10.5 -DC_AVX=1"
 LINK=" -dynamiclib -lm -ldl $LDOPENMP -mmacosx-version-min=10.5 -o libj.dylib"
 OBJS_FMA=" blis/gemm_int-fma.o "
+;;
+
+freebsd_j32) # freebsd x86
+TARGET=libj.so
+# faster, but sse2 not available for 32-bit amd cpu
+# sse does not support mfpmath=sse in 32-bit gcc
+COMPILE="$common -m32 -msse2 -mfpmath=sse -DC_NOMULTINTRINSIC "
+# slower, use 387 fpu and truncate extra precision
+# COMPILE="$common -m32 -ffloat-store "
+LINK=" -shared -Wl,-soname,libj.so -m32 -lm -ldl $LDOPENMP32 -o libj.so "
+;;
+
+freebsd_j64) # freebsd amd64
+TARGET=libj.so
+COMPILE="$common -DC_NOMULTINTRINSIC "
+LINK=" -shared -Wl,-soname,libj.so -lm -ldl $LDOPENMP -o libj.so "
 ;;
 
 *)
