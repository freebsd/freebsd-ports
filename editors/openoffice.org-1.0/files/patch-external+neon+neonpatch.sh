--- external/neon/neonpatch.sh.orig	Tue May 29 17:40:10 2001
+++ external/neon/neonpatch.sh	Thu Aug  8 22:43:04 2002
@@ -119,10 +119,7 @@
 # apply the patches
 #
 
-  for PNAME in `cat flist.pat`
-  do
-      patch -i pat/$PNAME.pat rtufiles/$PNAME
-  done
+  patch < md5.c.pat rtufiles/md5.c
 
 #
 # copy the SD files into rtufiles directory
