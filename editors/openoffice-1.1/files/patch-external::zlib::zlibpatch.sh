--- ../external/zlib/zlibpatch.sh.orig	Wed Mar 13 16:51:46 2002
+++ ../external/zlib/zlibpatch.sh	Wed Mar 13 16:52:02 2002
@@ -111,7 +111,7 @@
 
   for PNAME in `cat flist.pat`
   do
-      patch -i pat/$PNAME.pat $PNAME
+      patch < pat/$PNAME.pat $PNAME
   done
 
   cp -rf zlib-1.1.3/* rtufiles/
