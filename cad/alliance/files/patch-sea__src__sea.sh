--- sea/src/sea.sh.orig	Sun May  9 03:42:49 2004
+++ sea/src/sea.sh	Sun May  9 03:43:32 2004
@@ -376,11 +376,11 @@
    exit 1
  fi
 
- if [ "`uname`" != "SunOS" ]; then
-   echo "sea.sh:error: Must be run only under Solaris OS."
-   echo "              (current OS : \"$ALLIANCE_OS\")"
-   exit 1
- fi
+ #if [ "`uname`" != "SunOS" ]; then
+ #  echo "sea.sh:error: Must be run only under Solaris OS."
+ #  echo "              (current OS : \"$ALLIANCE_OS\")"
+ #  exit 1
+ #fi
 
 
  if [ "$devel" = "y" ]; then
