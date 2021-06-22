--- build/ld.linux.exe.sh.orig	2021-06-20 16:32:05 UTC
+++ build/ld.linux.exe.sh
@@ -313,6 +313,8 @@ then
     fi
 fi
 
+CMD="$CMD -lepoll-thread -lbz2 -lz"
+
 # add in math library
 if [ $HAVE_M -ne 0 ]
 then
