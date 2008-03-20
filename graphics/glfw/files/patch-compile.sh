--- compile.sh.orig	2004-07-25 00:36:46.000000000 +0400
+++ compile.sh	2008-03-20 05:20:39.000000000 +0300
@@ -72,10 +72,10 @@
 ##########################################################################
 if [ "x$force_gcc" = xyes ]; then
   CC=gcc
-else
-  CC=${CC-cc}
+#else
+#  CC=${CC-cc}
 fi
-CFLAGS=
+#CFLAGS=
 LFLAGS=
 INCS=
 LIBS="-lGL -lX11"
@@ -99,10 +99,10 @@
  INCS="-I/usr/X11/include"
  echo " X11 libraries location: /usr/X11/lib" 1>&6
 # X11R6 in /usr/X11R6/lib ?
-elif [ -r "/usr/X11R6/lib" ]; then
- LFLAGS="$LFLAGS -L/usr/X11R6/lib"
- INCS="-I/usr/X11R6/include"
- echo " X11 libraries location: /usr/X11R6/lib" 1>&6
+elif [ -r "${X11BASE}/lib" ]; then
+ LFLAGS="$LFLAGS -L${X11BASE}/lib"
+ INCS="-I${X11BASE}/include"
+ echo " X11 libraries location: ${X11BASE}/lib" 1>&6
 # X11R5 in /usr/X11R5/lib ?
 elif [ -r "/usr/X11R5/lib" ]; then
  LFLAGS="$LFLAGS -L/usr/X11R5/lib"
@@ -145,9 +145,9 @@
 rm -f conftest*
 
 echo " Using GNU C: ""$use_gcc" 1>&6
-if [ "x$use_gcc" = xyes ]; then
-  CC=gcc
-fi
+#if [ "x$use_gcc" = xyes ]; then
+#  CC=gcc
+#fi
 echo " " 1>&6
 
 
@@ -169,6 +169,8 @@
 int main() {; return 0;}
 EOF
 
+CFLAGS="${CFLAGS} -I${X11BASE}/include"
+
 if { (eval echo $config_script: \"$compile\") 1>&5; (eval $compile) 2>&5; }; then
   rm -rf conftest*
   has_xf86vm=yes
@@ -200,18 +202,10 @@
 
 # Try -lpthread (most systems)
 LIBS_OLD="$LIBS"
-LIBS="$LIBS -lpthread"
-if { (eval echo $config_script: \"$link\") 1>&5; (eval $link) 2>&5; }; then
-  rm -rf conftest*
-  has_pthread=yes
-else
-  echo "$config_script: failed program was:" >&5
-  cat conftest.c >&5
-fi
 
 # Try -pthread (e.g. FreeBSD)
 if [ "x$has_pthread" = xno ]; then
-  LIBS="$LIBS_OLD -pthread"
+  LIBS="$LIBS_OLD ${PTHREAD_LIBS}"
   if { (eval echo $config_script: \"$link\") 1>&5; (eval $link) 2>&5; }; then
     rm -rf conftest*
     has_pthread=yes
@@ -369,24 +363,24 @@
 echo "$config_script: Checking for sysconf support" >&5
 has_sysconf=no
 
-cat > conftest.c <<EOF
+#cat > conftest.c <<EOF
 #include <unistd.h>
 #ifndef _SC_NPROCESSORS_ONLN
 #ifndef _SC_NPROC_ONLN
 #error Neither _SC_NPROCESSORS_ONLN nor _SC_NPROC_ONLN available
 #endif
 #endif
-int main() {long x=sysconf(_SC_ARG_MAX); return 0; }
-EOF
+#int main() {long x=sysconf(_SC_ARG_MAX); return 0; }
+#EOF
 
-if { (eval echo $config_script: \"$link\") 1>&5; (eval $link) 2>&5; }; then
-  rm -rf conftest*
-  has_sysconf=yes
-else
-  echo "$config_script: failed program was:" >&5
-  cat conftest.c >&5
-fi
-rm -f conftest*
+#if { (eval echo $config_script: \"$link\") 1>&5; (eval $link) 2>&5; }; then
+#  rm -rf conftest*
+#  has_sysconf=yes
+#else
+#  echo "$config_script: failed program was:" >&5
+#  cat conftest.c >&5
+#fi
+#rm -f conftest*
 
 echo " sysconf support: ""$has_sysconf" 1>&6
 if [ "x$has_sysconf" = xyes ]; then
@@ -429,9 +423,9 @@
 # Post fixups
 ##########################################################################
 if [ "x$use_gcc" = xyes ]; then
-  CFLAGS_SPEED="-c -I. -I.. $CFLAGS -O3 -ffast-math -Wall"
+  CFLAGS_SPEED="-c -I. -I.. $CFLAGS -Wall"
   CFLAGS="-c -I. -I.. $CFLAGS -Os -Wall"
-  CFLAGS_LINK="$INCS -O3 -ffast-math -Wall"
+  CFLAGS_LINK="$INCS -Wall"
 else
   CFLAGS_SPEED="-c -I. -I.. $CFLAGS -O"
   CFLAGS="-c -I. -I.. $CFLAGS -O"
