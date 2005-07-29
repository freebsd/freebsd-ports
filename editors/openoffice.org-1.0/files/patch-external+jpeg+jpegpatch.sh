--- external/jpeg/jpegpatch.sh.orig	Wed Mar 13 17:04:35 2002
+++ external/jpeg/jpegpatch.sh	Wed Mar 13 17:08:02 2002
@@ -112,7 +112,7 @@
 
   for PNAME in `cat flist.pat`
   do
-      patch -i pat/$PNAME.pat $PNAME
+      patch < pat/$PNAME.pat $PNAME
   done
 
   cp -rf jpeg-6b/* rtufiles/
