--- lib/stdlib/extract-import-plugin.sh.orig	2012-08-02 22:02:49.000000000 -0500
+++ lib/stdlib/extract-import-plugin.sh	2012-08-02 22:03:27.000000000 -0500
@@ -4,4 +4,4 @@
 # source platform_helper (for sed)
 . ${OPA_SOURCE_DIR:-$(dirname $0)/../../}/tools/platform_helper.sh
 
-sed -n "s%^ *import-plugin  *\\(.*\\) *$%\\1%p" $1 | sed -e "s/{//" -e "s/}//" -e "s/, */\n/g"
+sed -n "s%^ *import-plugin  *\\(.*\\) *$%\\1%p" $1 | sed -e "s/{//" -e "s/}//" | tr ', ' '\n'
