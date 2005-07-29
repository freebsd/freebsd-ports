--- external/expat/expatpatch.sh.orig	Wed Mar 13 16:59:16 2002
+++ external/expat/expatpatch.sh	Wed Mar 13 17:00:18 2002
@@ -87,7 +87,7 @@
 
   for PNAME in `cat flist.pat`
   do
-     patch -i pat/$PNAME.pat rtufiles/$PNAME
+     patch < pat/$PNAME.pat rtufiles/$PNAME
   done
 
   for SDNAME in `cat flist.sd`
