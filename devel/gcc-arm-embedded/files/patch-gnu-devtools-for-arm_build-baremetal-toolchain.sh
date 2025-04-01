--- gnu-devtools-for-arm/build-baremetal-toolchain.sh.orig	2025-03-31 10:59:01 UTC
+++ gnu-devtools-for-arm/build-baremetal-toolchain.sh
@@ -263,7 +263,7 @@ flag_morello=0
 check_targets="check-binutils check-ld check-gas check-gcc check-g++ check-target-libatomic check-target-libstdc++-v3 check-gdb"
 check_nano_targets="check-gcc-nano check-g++-nano check-target-libstdc++-v3-nano"
 # Parse command-line options
-args=$(getopt -ohj:l:x -l bugurl:,builddir:,config-flags-binutils:,config-flags-gcc:,config-flags-host-tools:,config-flags-qemu:,debug,debug-target,dejagnu-site:,dejagnu-src:,enable-gdb,enable-gdb-with-python:,disable-gdb,enable-gcc,disable-gcc,enable-binutils,disable-binutils,enable-newlib,disable-newlib,enable-maintainer-mode,disable-maintainer-mode,enable-newlib-nano,disable-newlib-nano,enable-newlib-nano-check,disable-newlib-nano-check,enable-qemu,disable-qemu,help,host-toolchain-path:,ldflags-for-target:,ldflags-for-nano-target:,newlib-installdir:,package,no-package,qemu-test-path:,release,no-release,resultdir:,srcdir:,tag:,tardir:,target:,target-board:,timestamp:,with-language:,check-gdb,no-check-gdb,morello,host: -n $(basename "$0") -- "$@")
+args=$(${LOCALBASE}/bin/getopt -ohj:l:x -l bugurl:,builddir:,config-flags-binutils:,config-flags-gcc:,config-flags-host-tools:,config-flags-qemu:,debug,debug-target,dejagnu-site:,dejagnu-src:,enable-gdb,enable-gdb-with-python:,disable-gdb,enable-gcc,disable-gcc,enable-binutils,disable-binutils,enable-newlib,disable-newlib,enable-maintainer-mode,disable-maintainer-mode,enable-newlib-nano,disable-newlib-nano,enable-newlib-nano-check,disable-newlib-nano-check,enable-qemu,disable-qemu,help,host-toolchain-path:,ldflags-for-target:,ldflags-for-nano-target:,newlib-installdir:,package,no-package,qemu-test-path:,release,no-release,resultdir:,srcdir:,tag:,tardir:,target:,target-board:,timestamp:,with-language:,check-gdb,no-check-gdb,morello,host: -n $(basename "$0") -- "$@")
 eval set -- "$args"
 while [ $# -gt 0 ]; do
   if [ -n "${opt_prev:-}" ]; then
@@ -1305,7 +1305,7 @@ while true; do
     ( ulimit -v $memlimit &&
       RUNTESTFLAGS="$RUNTESTFLAGS" \
       DEJAGNU_TIMEOUT=$timelimit toolchain_prefix="$installdir$prefix" \
-      make -C "$objdir/binutils" $parallel -k "$stage" \
+      gmake -C "$objdir/binutils" $parallel -k "$stage" \
       CC_FOR_TARGET="$installdir$prefix/bin/$target-gcc") || true
     # Capture the results
     mkdir -p "$resultdir/vanilla"
@@ -1357,7 +1357,7 @@ while true; do
       if [ $flag_check_gdb -eq 1 ]; then
         ( ulimit -v $memlimit &&
           RUNTESTFLAGS="${default_target_board:+--target_board=$default_target_board} $RUNTESTFLAGS" \
-          toolchain_prefix="$installdir$prefix" make -C "$objdir/gdb" $parallel -k "$stage") || true
+          toolchain_prefix="$installdir$prefix" gmake -C "$objdir/gdb" $parallel -k "$stage") || true
 
         # Capture the results
         mkdir -p "$resultdir/vanilla"
