--- build.sh.orig	2007-11-01 21:00:00 UTC
+++ build.sh
@@ -15,6 +15,16 @@ fi
 if [ "$1" ]; then OS=$1; fi
 if [ "$2" ]; then ARCH=$2; fi
 
+# respect the user's options patch here
+echo " "
+echo "=== this is RAMspeed's build script ===================================="
+echo " "
+if [ -n "$CC" -a \( -n "$LD" -o -n "$AS" -o -n "$CFLAGS" -o -n "$LDFLAGS" \) ]
+then
+    _CC=$CC;_LD=$LD;_AS=$AS;_CFLAGS=$CFLAGS;_LDFLAGS=$LDFLAGS;_respect=yes
+fi
+# end of patch
+
 case $OS in
 
     FreeBSD)
@@ -127,10 +137,20 @@ case $OS in
 esac
 
 echo "building for $OS $RELEASE $ARCH"
-echo "compiler is $CC, linker is $LD, assembler is $AS"
-echo "compiler's flags are $CFLAGS"
-echo "linker's flags are $LFLAGS"
+echo "compiler is '$CC', linker is '$LD', assembler is '$AS'"
+echo "compiler's flags are '$CFLAGS'"
+echo "linker's flags are '$LFLAGS'"
 echo " "
+# respect the user's options patch here
+if [ X"$_respect" = Xyes ] ; then
+    CC=$_CC;LD=$_CC;AS=${_AS:-$AS};CFLAGS=$_CFLAGS;LFLAGS=$_LDFLAGS
+    echo "OVERRIDING build script defaults with your system's defaults:"
+    echo "compiler is '$CC', linker is '$LD', assembler is '$AS'"
+    echo "compiler's flags are '$CFLAGS'"
+    echo "linker's flags are '$LFLAGS'"
+    echo " "
+fi
+# end of patch
 
 if [ $TARGET = "GENERIC" ]
 then echo "WARNING! BUILDING FOR AN UNSUPPORTED OPERATING SYSTEM AND\OR ARCHITECTURE!"
@@ -139,8 +159,10 @@ then echo "WARNING! BUILDING FOR AN UNSU
      echo " "
 fi
 
-echo "press Enter to continue or Control-C to abort"
-read ANS
+if [ X"$_respect" != Xyes -a -t 0 -a -t 1 ] ; then
+    echo "press Enter to continue or Control-C to abort"
+    read ANS
+fi
 
 case $TARGET in
 
