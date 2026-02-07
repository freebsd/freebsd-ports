--- mpdm/config.sh.orig	2020-10-11 16:50:34 UTC
+++ mpdm/config.sh
@@ -192,8 +192,8 @@ echo -n "Testing for regular expressions... "
 
 if [ "$WITH_PCRE" = 1 ] ; then
     # try first the pcre library
-    TMP_CFLAGS="-I/usr/local/include"
-    TMP_LDFLAGS="-L/usr/local/lib -lpcre -lpcreposix"
+    TMP_CFLAGS="-I$LOCALBASE/include"
+    TMP_LDFLAGS="-L$LOCALBASE/lib -lpcre -lpcreposix"
     echo "#include <pcreposix.h>" > .tmp.c
     echo "int main(void) { regex_t r; regmatch_t m; regcomp(&r,\".*\",REG_EXTENDED|REG_ICASE); return 0; }" >> .tmp.c
 
@@ -397,13 +397,15 @@ else
         echo "#define CONFOPT_GETTEXT 1" >> config.h
     else
         # try now with -lintl
-        TMP_LDFLAGS="-lintl"
+        TMP_CFLAGS="-I$LOCALBASE/include"
+        TMP_LDFLAGS="-L$LOCALBASE/lib -lintl"
 
-        $CC $CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
+        $CC $CFLAGS $TMP_CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
 
         if [ $? = 0 ] ; then
             echo "OK (libintl needed)"
             echo "#define CONFOPT_GETTEXT 1" >> config.h
+            echo "$TMP_CFLAGS" >> config.cflags
             echo "$TMP_LDFLAGS" >> config.ldflags
             LDFLAGS="$LDFLAGS $TMP_LDFLAGS"
         else
@@ -431,13 +433,15 @@ else
         echo "#define CONFOPT_ICONV 1" >> config.h
     else
         # try now with -liconv
-        TMP_LDFLAGS="-liconv"
+        TMP_CFLAGS="-I$ICONV_PREFIX/include"
+        TMP_LDFLAGS="-L$ICONV_PREFIX/lib $ICONV_LIB"
 
-        $CC $CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
+        $CC $CFLAGS $TMP_CFLAGS .tmp.c $TMP_LDFLAGS -o .tmp.o 2>> .config.log
 
         if [ $? = 0 ] ; then
             echo "OK (libiconv needed)"
             echo "#define CONFOPT_ICONV 1" >> config.h
+            echo "$TMP_CFLAGS" >> config.cflags
             echo "$TMP_LDFLAGS" >> config.ldflags
             LDFLAGS="$LDFLAGS $TMP_LDFLAGS"
         else
@@ -628,7 +632,7 @@ fi
 
 # test for mp_doccer
 echo -n "Testing if mp_doccer is installed... "
-MP_DOCCER=$(which mp_doccer > /dev/null 2>&1||which mp-doccer > /dev/null 2>&1)
+MP_DOCCER=$(which mp_doccer)
 
 if [ $? = 0 ] ; then
 
