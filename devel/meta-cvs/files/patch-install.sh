$FreeBSD$

--- code/install.sh.orig	Thu Feb 13 19:30:54 2003
+++ code/install.sh	Thu Feb 13 19:31:01 2003
@@ -51,12 +51,6 @@
   exit 1
 fi
 
-if [ ! -e $LINKSET ] ; then
-    export CLISP_LINKKIT="${CLISP_LIB}linkkit"
-    sh "${CLISP_LIB}clisp-link" add-module-set unix-bindings \
-    "${CLISP_LIB}base" $LINKSET
-fi
-
 LISPRUN=$LINKSET/lisp
 
 if [ -f $LISPRUN.run ] ; then
@@ -65,18 +59,8 @@
 elif [ -f $LISPRUN.exe ] ; then
   LISPRUN=$LISPRUN.exe
   LISPEXE=.exe
-else
-  echo "linking set failed to build."
-  exit 1
-fi
-
-if ! $LISPRUN -M $LINKSET/lispinit.mem -q -c mcvs-main ; then
-  echo "There were compilation errors."
-  exit 1
 fi
 
-$LISPRUN -M $LINKSET/lispinit.mem -q -i mcvs-main -x '(ext:saveinitmem "mcvs.mem" :quiet t)'
-
 if ! cp mcvs.mem $TARGET_LIB/lispinit.mem; then
   echo "Unable to copy to $TARGET_LIB."
   exit 1
@@ -84,87 +68,6 @@
 
 if ! cp $LISPRUN $TARGET_LIB; then
   echo "Unable to copy to $TARGET_LIB."
-  exit 1
-fi
-
-if ! cat > $TARGET_BIN/mcvs <<END
-#!$TARGET_LIB/lisp$LISPEXE -M$TARGET_LIB/lispinit.mem
-(mcvs)
-END
-then
-  echo "Could not create mcvs script in $TARGET."
-  exit 1
-fi
-
-if ! chmod a+x "$TARGET_BIN/mcvs" ; then
-  echo "Could not set permissions of mcvs script in $TARGET."
-  exit 1
-fi
-
-if ! cat > $TARGET_BIN/mcvs-upgrade <<END
-#!/bin/sh
-TARGET_LIB="$TARGET_LIB"
-LISPRUN="\$TARGET_LIB/lisp.run -M \$TARGET_LIB/lispinit.mem"
-
-if [ \$# != 1 ] ; then
-  echo
-  echo "Syntax:"
-  echo
-  echo "  mcvs-upgrade <path-to-source>"
-  echo
-  echo "The path specifies the directory which holds unpacked Meta-CVS source,"
-  echo "the place where the file mcvs-main.lisp is located."
-  echo
-  echo "This upgrade mechanism is intended to make it possible to use a"
-  echo "newer version of Meta-CVS without having to obtain a complete binary"
-  echo "distribution that includes the Lisp executable, and without having"
-  echo "to install the Lisp development environment to build the sources."
-  echo
-  echo "Note that it's not possible to upgrade if the newer Meta-CVS sources"
-  echo "rely on new C functions being linked into the Lisp system; get a"
-  echo "new binary distribution, or set up CLISP and compile Meta-CVS from"
-  echo "the sources using its install.sh script"
-  echo
-  echo "Ignore the copious compiler warnings about objects and functions"
-  echo "being redefined; this is what we want."
-  echo
-  exit 1
-fi
-
-SOURCE_PATH="\$1"
-
-if ! cd "\$SOURCE_PATH" ; then
-  echo "unable to change to \$SOURCE_PATH"
-  exit 1
-fi
-
-if ! \$LISPRUN -c mcvs-main ; then
-  echo "unable to compile"
-  exit 1
-fi
-
-if ! \$LISPRUN -q -i mcvs-main -x '(ext:saveinitmem "mcvs.mem" :quiet t)' ; then
-  echo "unable to load and generate memory image"
-  exit 1
-fi
-
-if ! cp mcvs.mem \$TARGET_LIB/lispinit.mem ; then
-  echo "unable to copy new Meta-CVS image to \$TARGET_LIB directory."
-  exit 1
-fi
-
-echo
-echo "It appears that Meta-CVS has been re-generated from the given sources."
-echo 
-
-END
-then
-  echo "Could not create mcvs script in $TARGET."
-  exit 1
-fi
-
-if ! chmod a+x "$TARGET_BIN/mcvs-upgrade" ; then
-  echo "Could not set permissions of mcvs script in $TARGET."
   exit 1
 fi
 
