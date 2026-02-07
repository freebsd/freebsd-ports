--- src/make-version.sh.orig	2019-12-01 11:12:07 UTC
+++ src/make-version.sh
@@ -11,7 +11,7 @@ using namespace std;
 
 #include "version.h"
 
-char Version::revision[] = "$(git log -n 1 --format='%H' || echo UNKNOWN)";
-char Version::date[] = "$(git log -n 1 --format='%ci' || echo UNKNOWN)";
+char Version::revision[] = "bd7dfac09b760b87b86158e903459a765b0acf43";
+char Version::date[] = "2019-11-04 18:42:35 +0200";
 char Version::compiled[] = "$(date +'%F %T')";
 EOF
