--- ../external/neon/neonpatch.sh.orig	Mon Apr 15 15:22:48 2002
+++ ../external/neon/neonpatch.sh	Mon Apr 15 15:22:54 2002
@@ -121,7 +121,7 @@
 
   for PNAME in `cat flist.pat`
   do
-      patch -i pat/$PNAME.pat rtufiles/$PNAME
+      patch < pat/$PNAME.pat rtufiles/$PNAME
   done
 
 #
