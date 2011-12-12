--- pylib/gyp/generator/make.py.orig	2010-06-26 08:55:39.000000000 +0900
+++ pylib/gyp/generator/make.py	2011-12-11 22:54:34.000000000 +0900
@@ -182,7 +182,7 @@
 # We remove slashes and replace spaces with new lines;
 # remove blank lines;
 # delete the first line and append a colon to the remaining lines.
-sed -e 's|\\||' -e 's| |\n|g' $(depfile).raw |\
+env NL=`printf "\n"` sed -e 's|\\||' -e 's| |${NL}|g' $(depfile).raw |\
   grep -v '^$$'                              |\
   sed -e 1d -e 's|$$|:|'                      \
     >> $(depfile)
