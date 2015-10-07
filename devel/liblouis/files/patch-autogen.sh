--- autogen.sh.orig	2015-08-31 14:19:59 UTC
+++ autogen.sh
@@ -28,8 +28,8 @@ set -e
 
 # Refresh GNU autotools toolchain.
 echo Cleaning autotools files...
-find -type d -name autom4te.cache -print0 | xargs -0 rm -rf \;
-find -type f \( -name missing -o -name install-sh -o -name mkinstalldirs \
+find . -type d -name autom4te.cache -print0 | xargs -0 rm -rf \;
+find . -type f \( -name missing -o -name install-sh -o -name mkinstalldirs \
 	-o -name depcomp -o -name ltmain.sh -o -name configure \
 	-o -name config.sub -o -name config.guess -o -name config.h.in \
         -o -name mdate-sh -o -name texinfo.tex \
