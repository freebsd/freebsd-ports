--- gnu-devtools-for-arm/utilities.sh.orig	2025-07-31 23:01:18 UTC
+++ gnu-devtools-for-arm/utilities.sh
@@ -33,6 +33,8 @@ number_of_cores()
     grep -c "^processor" /proc/cpuinfo
   elif [ "$(uname -s)" == "Darwin" ]; then
     sysctl -n hw.ncpu
+  elif [ "$(uname -s)" == "FreeBSD" ]; then
+    nproc 2> /dev/null || sysctl -n hw.ncpu
   else
     echo "1"
   fi
@@ -50,12 +52,15 @@ find_build_triple ()
 # Get the triple of the machine we're running on, i.e. the build machine.
 find_build_triple ()
 {
-  machine=$(uname -m)
+  machine=$(uname -p)
   plat=$(uname -s)
   if [[ "$plat" == "Darwin" ]]; then
     echo "$machine-apple-darwin"    # e.g. x86_64-apple-darwin or arm64-apple-darwin
   elif [[ "$plat" == "Linux" ]]; then
     echo "$machine-none-linux-gnu"  # e.g. x86_64-none-linux-gnu
+  elif [[ "$plat" == "FreeBSD" ]]; then
+    ver=$(uname -r | sed 's/-.*$//')
+    echo "$machine-unknown-freebsd$ver"
   else
     echo "$this_script: unsupported platform: $plat" >&2
     exit 1
@@ -134,7 +139,7 @@ find_source_tree ()
   do
     if [[ "$d" == "gcc" ]]
     then
-      for x in `find "$srcdir" -maxdepth 1 -type d -printf '%f\n' | grep "^arm-gnu-toolchain-src-snapshot[0-9.-]*" | sort`
+      for x in `gfind "$srcdir" -maxdepth 1 -type d -printf '%f\n' | grep "^arm-gnu-toolchain-src-snapshot[0-9.-]*" | sort`
       do
         echo "$srcdir/$x"
         return 0
@@ -213,7 +218,7 @@ do_install ()
   test -n "$install_targets" || install_targets=install
 
   update_stage "install ${component}"
-  make ${extra_install_envflags} DESTDIR=$destdir INSTALL="$(command -v install) -C" \
+  gmake ${extra_install_envflags} DESTDIR=$destdir INSTALL="$(command -v install) -C" \
      -C $objdir $install_targets
   echo "${component}_install_targets=$install_targets" >> "$build_flags_path"
 }
@@ -303,7 +308,7 @@ do_make ()
     make_opts="$parallel"
   fi
 
-  make $make_opts -C $objdir $build_targets
+  gmake $make_opts -C $objdir $build_targets
   echo "${component}_build_targets=$build_targets" >> "$build_flags_path"
 }
 
@@ -323,7 +328,7 @@ check_in_gcc()
   local resultdir="$4"
 
   ( ulimit -v $memlimit &&
-    make -C "$dir" $parallel -k $target RUNTESTFLAGS="$RUNTESTFLAGS") || true
+    gmake -C "$dir" $parallel -k $target RUNTESTFLAGS="$RUNTESTFLAGS") || true
 
   # Capture the results
   mkdir -p "$resultdir"
@@ -344,7 +349,7 @@ check_in_newlib()
   ( ulimit -v $memlimit &&
     RUNTESTFLAGS="$RUNTESTFLAGS" \
     DEJAGNU_TIMEOUT=$timelimit toolchain_prefix="$gcc_prefix" \
-    make -C "$dir" $parallel -k "$check_target" \
+    gmake -C "$dir" $parallel -k "$check_target" \
     CC_FOR_TARGET="${gcc_prefix}/bin/$target-gcc") || true
   # Capture the results
   mkdir -p "$resultdir"
