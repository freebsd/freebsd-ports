--- pylib/gyp/generator/make.py.orig	2016-05-10 14:06:56 UTC
+++ pylib/gyp/generator/make.py
@@ -342,7 +342,7 @@ sed -e "s|^$(notdir $@)|$@|" $(depfile).
 # We remove slashes and replace spaces with new lines;
 # remove blank lines;
 # delete the first line and append a colon to the remaining lines.
-sed -e 's|\\||' -e 'y| |\n|' $(depfile).raw |\
+env NL=`printf "\n"` sed -e 's|\\||' -e 'y| |\n|' $(depfile).raw |\
   grep -v '^$$'                             |\
   sed -e 1d -e 's|$$|:|'                     \
     >> $(depfile)
