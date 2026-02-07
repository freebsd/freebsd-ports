--- gnu-devtools-for-arm/build-gnu-toolchain.sh.orig	2025-03-31 10:59:01 UTC
+++ gnu-devtools-for-arm/build-gnu-toolchain.sh
@@ -191,7 +191,7 @@ EOF
 set_darwin_envvars
 
 # Parse command-line options
-args=$(getopt -ohj:l:x -l aprofile,check-gdb,no-check-gdb,debug,debug-target,dejagnu-site:,dejagnu-src:,disable-gdb,disable-multilib,morello,extra:,native,rmprofile,help,target:,with-arch:,builddir:,host-toolchain:,target-board: -n $(basename "$0") -- "$@")
+args=$(${LOCALBASE}/bin/getopt -ohj:l:x -l aprofile,check-gdb,no-check-gdb,debug,debug-target,dejagnu-site:,dejagnu-src:,disable-gdb,disable-multilib,morello,extra:,native,rmprofile,help,target:,with-arch:,builddir:,host-toolchain:,target-board: -n $(basename "$0") -- "$@")
 eval set -- "$args"
 while [ $# -gt 0 ]; do
   if [ -n "${opt_prev:-}" ]; then
