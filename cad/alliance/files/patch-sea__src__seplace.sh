--- sea/src/seplace.sh.orig	Sun May  9 07:29:32 2004
+++ sea/src/seplace.sh	Sun May  9 07:29:49 2004
@@ -225,10 +225,10 @@
  title
 
 
- if [ "`uname`" != "SunOS" ]; then
-   echo "seplace.sh:error: This progam must be run under Solaris."
-   exit 1
- fi
+ #if [ "`uname`" != "SunOS" ]; then
+ #  echo "seplace.sh:error: This progam must be run under Solaris."
+ #  exit 1
+ #fi
 
 
 # --------------------------------------------------------------------
