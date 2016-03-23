--- autogen.sh.orig	2016-01-20 21:31:42 UTC
+++ autogen.sh
@@ -6,14 +6,6 @@ if test $? -ne 0; then
   exit 1
 fi
 
-GIT=`which git 2>/dev/null`
-if test $? -ne 0; then
-  echo "No 'git' found. You must install the git package."
-  exit 1
-fi
-
-$GIT submodule init
-$GIT submodule update
 
 # create m4 before autoreconf
 mkdir m4 2>/dev/null
