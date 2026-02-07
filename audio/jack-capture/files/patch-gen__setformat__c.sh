--- gen_setformat_c.sh.orig	2022-11-04 20:56:46 UTC
+++ gen_setformat_c.sh
@@ -63,7 +63,7 @@ for a in $ai;do
     esac
     echo "main(){return $format;}" >>temp.c
     echo >>temp.c
-    if gcc temp.c 2>/dev/null; then
+    if gcc $CFLAGS $LDFLAGS temp.c 2>/dev/null; then
 	echo "    (!strcasecmp(\""$a"\",soundfile_format)) ? $format :"
     fi
 done
