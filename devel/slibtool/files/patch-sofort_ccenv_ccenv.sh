--- sofort/ccenv/ccenv.sh.orig	2020-08-16 18:04:05 UTC
+++ sofort/ccenv/ccenv.sh
@@ -1254,7 +1254,7 @@ ccenv_output_defs()
 		ccenv_tmp=$(mktemp ./tmp_XXXXXXXXXXXXXXXX)
 
 		sed                             \
-				-e 's/^\s*$/@/g' \
+				-e 's/^[:space:]*$/@/g' \
 				-e 's/^/NATIVE_/' \
 				-e 's/NATIVE_@//g' \
 				-e 's/NATIVE_#/#/g' \
