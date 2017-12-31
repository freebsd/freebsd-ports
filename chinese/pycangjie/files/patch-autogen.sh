--- autogen.sh.orig	2017-11-04 15:37:55 UTC
+++ autogen.sh
@@ -8,4 +8,3 @@ aclocal -I m4
 autoheader
 automake --add-missing --copy
 autoconf
-./configure $*
