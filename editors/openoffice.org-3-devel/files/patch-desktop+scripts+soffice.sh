--- ../desktop/scripts/soffice.sh.orig	Wed Sep 17 05:21:54 2003
+++ ../desktop/scripts/soffice.sh	Wed Sep 17 05:24:59 2003
@@ -233,6 +233,8 @@
 PATH="$sd_prog":$PATH
 export PATH
 
+. $sd_prog/freebsd-local.sh
+
 # execute soffice binary
 exec "$sd_prog/$sd_binary" "$@"
 
