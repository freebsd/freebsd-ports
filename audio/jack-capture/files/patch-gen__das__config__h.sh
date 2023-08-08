--- gen_das_config_h.sh.orig	2022-11-04 16:32:42 UTC
+++ gen_das_config_h.sh
@@ -16,7 +16,7 @@
 echo "#include <sndfile.h>" >temp$$.c
 echo "main(){return SF_FORMAT_OGG;}" >>temp$$.c
 echo >>temp$$.c
-if gcc temp$$.c 2>/dev/null; then
+if gcc $CFLAGS $LDFLAGS temp$$.c 2>/dev/null; then
     echo "#define HAVE_OGG 1"
 else
     echo "#define HAVE_OGG 0"
@@ -26,7 +26,7 @@ fi
 echo "#include <lame/lame.h>" >temp$$.c
 echo "main(){return 0;}" >>temp$$.c
 echo >>temp$$.c
-if gcc temp$$.c -lmp3lame 2>/dev/null; then
+if gcc $CFLAGS $LDFLAGS temp$$.c -lmp3lame 2>/dev/null; then
     echo "#define HAVE_LAME 1"
     echo "//COMPILEFLAGS -lmp3lame"
 else
@@ -37,7 +37,7 @@ fi
 echo "#include <lo/lo.h>" >temp$$.c
 echo "main(){return 0;}" >>temp$$.c
 echo >>temp$$.c
-if pkg-config --cflags --libs liblo >/dev/null 2>/dev/null && gcc temp$$.c `pkg-config --cflags --libs liblo` 2>/dev/null ; then
+if pkg-config --cflags --libs liblo >/dev/null 2>/dev/null && gcc $CFLAGS $LDFLAGS temp$$.c `pkg-config --cflags --libs liblo` 2>/dev/null ; then
     echo "#define HAVE_LIBLO 1"
     echo "//COMPILEFLAGS " `pkg-config --cflags --libs liblo`
 else
@@ -48,7 +48,7 @@ fi
 echo "#include <jack/jack.h>" >temp$$.c
 echo "main(){return (int)jack_port_get_latency_range;}" >>temp$$.c
 echo >>temp$$.c
-if gcc temp$$.c -ljack 2>/dev/null ; then
+if gcc $CFLAGS $LDFLAGS temp$$.c -ljack 2>/dev/null ; then
     echo "#define NEW_JACK_LATENCY_API 1"
 else
     echo "#define NEW_JACK_LATENCY_API 0"
