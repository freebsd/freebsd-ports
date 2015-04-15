--- ipl/cfuncs/mklib.sh.orig	2015-03-22 15:13:09 UTC
+++ ipl/cfuncs/mklib.sh
@@ -11,7 +11,7 @@ shift
 SYS=`uname -s`
 set -x
 case "$SYS" in
-   Linux*|*BSD*|GNU*)
+   DragonFly*|Linux*|*BSD*|GNU*)
       $CC -shared -o $LIBNAME -fPIC "$@";;
    CYGWIN*)
       # move the win32 import library for iconx.exe callbacks
