--- autogen.sh.orig	2016-01-20 21:31:42 UTC
+++ autogen.sh
@@ -12,8 +12,6 @@ if test $? -ne 0; then
   exit 1
 fi
 
-$GIT submodule init
-$GIT submodule update
 
 # create m4 before autoreconf
 mkdir m4 2>/dev/null
