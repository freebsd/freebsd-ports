--- cleanup.sh.orig	Tue Jun 29 10:42:05 2004
+++ cleanup.sh	Sun Jul 11 23:58:19 2004
@@ -1,7 +1,11 @@
 #!/bin/sh
+PREFIX=/usr/local
 
 for old in childsplay.mo letters.mo numbers.mo memory.mo \
 		     soundmemory.mo soundNpic.mo packid.mo; do
     echo "Looking for $old"
-    find /usr/share/locale/ -name $old -exec rm -v {} \;
+    if [ -e $PREFIX/share/locale ] 
+    then
+        find $PREFIX/share/locale/ -name $old -exec rm -v {} \;
+    fi
 done
