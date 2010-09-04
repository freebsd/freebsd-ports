--- pylib/gyp/generator/make.py.org	2010-09-03 18:36:39.151835296 +0900
+++ pylib/gyp/generator/make.py	2010-09-03 18:55:43.973773838 +0900
@@ -177,14 +177,14 @@
 r"""
 define fixup_dep
 # Fixup path as in (1).
-sed -e "s|^$(notdir $@)|$@|" $(depfile).raw >> $(depfile)
+gsed -e "s|^$(notdir $@)|$@|" $(depfile).raw >> $(depfile)
 # Add extra rules as in (2).
 # We remove slashes and replace spaces with new lines;
 # remove blank lines;
 # delete the first line and append a colon to the remaining lines.
-sed -e 's|\\||' -e 's| |\n|g' $(depfile).raw |\
-  grep -v '^$$'                              |\
-  sed -e 1d -e 's|$$|:|'                      \
+gsed -e 's|\\||' -e 's| |\n|g' $(depfile).raw |\
+  @@LOCALBASE@@/bin/grep -E -v '^$$'          |\
+  gsed -e 1d -e 's|$$|:|'                      \
     >> $(depfile)
 rm $(depfile).raw
 endef
