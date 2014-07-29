--- sea/src/seroute.sh.orig	Sun May  9 03:43:37 2004
+++ sea/src/seroute.sh	Sun May  9 03:43:53 2004
@@ -226,10 +226,10 @@
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
