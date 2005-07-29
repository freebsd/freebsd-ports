--- external/npsdk/npsdkpatch.sh.orig	Wed Mar 13 16:49:19 2002
+++ external/npsdk/npsdkpatch.sh	Wed Mar 13 16:49:39 2002
@@ -121,7 +121,7 @@
 
   for PNAME in `cat flist.pat`
   do
-    patch -i pat/$PNAME.pat rtufiles/$PNAME
+    patch < pat/$PNAME.pat rtufiles/$PNAME
   done
 
 #
