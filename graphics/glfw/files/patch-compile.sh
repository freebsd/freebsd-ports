--- compile.sh.orig	2007-07-01 11:46:46.000000000 +0200
+++ compile.sh	2008-06-14 23:22:27.000000000 +0200
@@ -63,7 +63,7 @@
   CC=cc
 fi
 
-CFLAGS=
+#CFLAGS=
 LFLAGS=
 LDFLAGS=
 INCS=
@@ -164,10 +164,10 @@
 fi
 rm -f conftest*
 
-echo " Using GNU C: ""$use_gcc" 1>&6
-if [ "x$use_gcc" = xyes ]; then
-  CC=gcc
-fi
+#echo " Using GNU C: ""$use_gcc" 1>&6
+#if [ "x$use_gcc" = xyes ]; then
+#  CC=gcc
+#fi
 echo " " 1>&6
 
 
@@ -254,11 +254,11 @@
 EOF
 
 # Try -pthread (most systems)
-CFLAGS_THREAD="-pthread"
+CFLAGS_THREAD="$PTHREAD_CFLAGS"
 CFLAGS_OLD="$CFLAGS"
 CFLAGS="$CFLAGS $CFLAGS_THREAD"
 LIBS_OLD="$LIBS"
-LIBS="$LIBS -pthread"
+LIBS="$LIBS ${PTHREAD_LIBS}"
 if { (eval echo $config_script: \"$link\") 1>&5; (eval $link) 2>&5; }; then
   rm -rf conftest*
   has_pthread=yes
@@ -267,20 +267,6 @@
   cat conftest.c >&5
 fi
 
-# Try -lpthread 
-if [ "x$has_pthread" = xno ]; then
-  CFLAGS_THREAD="-D_REENTRANT"
-  CFLAGS="$CFLAGS_OLD $CFLAGS_THREAD" 
-  LIBS="$LIBS_OLD -lpthread"
-  if { (eval echo $config_script: \"$link\") 1>&5; (eval $link) 2>&5; }; then
-    rm -rf conftest*
-    has_pthread=yes
-  else
-    echo "$config_script: failed program was:" >&5
-    cat conftest.c >&5
-  fi
-fi
-
 # Try -lsocket (e.g. QNX)
 if [ "x$has_pthread" = xno ]; then
   CFLAGS="$CFLAGS_OLD" 
@@ -534,9 +520,9 @@
 # Post fixups
 ##########################################################################
 if [ "x$use_gcc" = xyes ]; then
-  CFLAGS_SPEED="-c -I. -I.. $CFLAGS -O3 -ffast-math -Wall"
+  CFLAGS_SPEED="-c -I. -I.. $CFLAGS -ffast-math -Wall"
   CFLAGS="-c -I. -I.. $CFLAGS -Os -Wall"
-  CFLAGS_LINK="$INCS -O3 -ffast-math -Wall"
+  CFLAGS_LINK="$INCS -ffast-math -Wall"
 else
   CFLAGS_SPEED="-c -I. -I.. $CFLAGS -O"
   CFLAGS="-c -I. -I.. $CFLAGS -O"
