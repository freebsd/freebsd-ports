--- compile.sh.orig	Wed Jan  8 12:19:48 2003
+++ compile.sh	Sat Jan 24 18:39:15 2004
@@ -69,10 +69,10 @@
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
 LIBS="-lGL -lX11"
 
@@ -88,9 +88,9 @@
 # Check for X11 libs directory
 ##########################################################################
 echo "Checking for X11 libraries location... " 1>&6
-if [ -r "/usr/X11R6/lib/libX11.so" ]; then
- LFLAGS="$LFLAGS -L/usr/X11R6/lib"
- echo " X11 libraries location: /usr/X11R6/lib" 1>&6
+if [ -r "${X11BASE}/lib/libX11.so" ]; then
+ LFLAGS="$LFLAGS -L${X11BASE}/lib"
+ echo " X11 libraries location: ${X11BASE}/lib" 1>&6
 elif [ -r "/usr/X11R5/lib/libX11.so" ]; then
  LFLAGS="$LFLAGS -L/usr/X11R5/lib"
  echo " X11 libraries location: /usr/X11R5/lib" 1>&6
@@ -120,9 +120,9 @@
 rm -f conftest*
 
 echo " Using GNU C: ""$use_gcc" 1>&6
-if [ "x$use_gcc" = xyes ]; then
-  CC=gcc
-fi
+#if [ "x$use_gcc" = xyes ]; then
+#  CC=gcc
+#fi
 echo " " 1>&6
 
 
@@ -139,6 +139,8 @@
 int main() {; return 0;}
 EOF
 
+CFLAGS="${CFLAGS} -I${X11BASE}/include"
+
 if { (eval echo $config_script: \"$compile\") 1>&5; (eval $compile) 2>&5; }; then
   rm -rf conftest*
   has_xf86vm=yes
@@ -279,29 +281,29 @@
 ##########################################################################
 # Check for sysconf support
 ##########################################################################
-echo "Checking for sysconf support... " 1>&6
-echo "$config_script: Checking for sysconf support" >&5
-has_sysconf=no
+#echo "Checking for sysconf support... " 1>&6
+#echo "$config_script: Checking for sysconf support" >&5
+#has_sysconf=no
 
-cat > conftest.c <<EOF
+#cat > conftest.c <<EOF
 #include <unistd.h>
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
-
-echo " sysconf support: ""$has_sysconf" 1>&6
-if [ "x$has_sysconf" = xyes ]; then
-   CFLAGS="$CFLAGS -D_GLFW_HAS_SYSCONF"
-fi
-echo " " 1>&6
+#if { (eval echo $config_script: \"$link\") 1>&5; (eval $link) 2>&5; }; then
+#  rm -rf conftest*
+#  has_sysconf=yes
+#else
+#  echo "$config_script: failed program was:" >&5
+#  cat conftest.c >&5
+#fi
+#rm -f conftest*
+
+#echo " sysconf support: ""$has_sysconf" 1>&6
+#if [ "x$has_sysconf" = xyes ]; then
+#   CFLAGS="$CFLAGS -D_GLFW_HAS_SYSCONF"
+#fi
+#echo " " 1>&6
 
 
 ##########################################################################
@@ -337,7 +339,8 @@
 ##########################################################################
 # Post fixups
 ##########################################################################
-if [ "x$CC" = xgcc ]; then
+CFLAGS_NO_COMPILE="${CFLAGS}"
+if [ "x$use_gcc" = xyes ]; then
   CFLAGS_SPEED="-c -I. -I.. $CFLAGS -O3 -ffast-math -Wall"
   CFLAGS="-c -I. -I.. $CFLAGS -Os -Wall"
   CFLAGS_LINK="-O3 -ffast-math -Wall"
@@ -346,8 +349,8 @@
   CFLAGS="-c -I. -I.. $CFLAGS -O"
   CFLAGS_LINK="-O"
 fi
-CFLAGS_LINK="-I../include $CFLAGS_LINK"
-LFLAGS="$LFLAGS -L../lib/x11 -s -lglfw -lGLU $LIBS -lpthread -lm"
+CFLAGS_LINK="-I../include ${CFLAGS_NO_COMPILE} $CFLAGS_LINK"
+LFLAGS="$LFLAGS -L../lib/x11 -s -lglfw -lGLU $LIBS ${PTHREAD_LIBS} -lm"
 
 
 ##########################################################################
