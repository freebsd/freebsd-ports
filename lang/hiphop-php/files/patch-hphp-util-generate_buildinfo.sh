--- hphp/util/generate_buildinfo.sh.orig	2013-07-22 20:32:44.836745592 +0200
+++ hphp/util/generate_buildinfo.sh	2013-07-22 20:33:07.435450744 +0200
@@ -74,7 +74,7 @@
     # As with COMPILER_ID above, we're not in git so we have to
     # use a fallback state where we assume to repo is constantly
     # changing by using the system time
-    HHVM_REPO_SCHEMA=$(date +%N.%s)
+    HHVM_REPO_SCHEMA=$(date +%N_%s)
   fi
 fi
 
