--- external/dt/dtpatch.sh.orig	Wed Mar 13 17:09:43 2002
+++ external/dt/dtpatch.sh	Wed Mar 13 17:09:47 2002
@@ -96,7 +96,7 @@
     done
 
     chmod -R +w rtufiles/*.h
-    patch -i pat/editor.h.pat rtufiles/editor.h 2> newpatch
+    patch < pat/editor.h.pat rtufiles/editor.h 2> newpatch
 
     if test -s "patcherror"; then
        echo "Please install the SUNWdtinc Version 1.2 package on your Solaris machine" >> patcherror
