--- gnu-devtools-for-arm/build-cross-linux-toolchain.sh.orig	2025-03-31 10:59:01 UTC
+++ gnu-devtools-for-arm/build-cross-linux-toolchain.sh
@@ -1174,7 +1174,7 @@ EOF
     mkdir -p "${build_sysroot}/$target_libdir"
     mkdir -p "${build_sysroot}/$target_rtlddir"
 
-    make -C "$objdir/$libname-headers" csu/subdir_lib
+    gmake -C "$objdir/$libname-headers" csu/subdir_lib
     cp $objdir/$libname-headers/csu/crt1.o $objdir/$libname-headers/csu/crti.o $objdir/$libname-headers/csu/crtn.o "$build_sysroot/$target_libdir"
 
     libc_host_compiler="$installdir/$host_prefix/bin"
@@ -1445,7 +1445,7 @@ EOF
       ( ulimit -S -t 120 &&
         RUNTESTFLAGS="$RUNTESTFLAGS" \
         DESTDIR=${installdir} \
-        make -C $objdir_local -k $parallel $stage \
+        gmake -C $objdir_local -k $parallel $stage \
         CC_FOR_TARGET="${installdir}/${host_prefix}/bin/$target-gcc" ) \
       || true
 
@@ -1481,7 +1481,7 @@ EOF
   if [ -d "$srcdir/libffi" ];
   then
     RUNTESTFLAGS="$RUNTESTFLAGS CC_FOR_TARGET=$target-gcc" \
-    make -C "$objdir/libffi" PARALLELMFLAGS=$parallel -k check || true
+    gmake -C "$objdir/libffi" PARALLELMFLAGS=$parallel -k check || true
     # Capture the results
     mkdir -p "$resultdir"
     name=libffi
