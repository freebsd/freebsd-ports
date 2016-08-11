--- tests/build/header-sanity/test.sh.orig	2016-06-25 02:19:12 UTC
+++ tests/build/header-sanity/test.sh
@@ -5,12 +5,12 @@ for i in $HEADERS/*.h; do
     case $i in
     */rtapi_app.h) continue ;;
     esac
-    gcc -DULAPI -I$HEADERS -E -x c $i > /dev/null
+    cc -DULAPI -I$HEADERS -I/usr/local/include -E -x c $i > /dev/null
 done
 for i in $HEADERS/*.h $HEADERS/*.hh; do
     case $i in
     */rtapi_app.h) continue ;;
     */interp_internal.hh) continue ;;
     esac
-    g++ -DULAPI -I$HEADERS -E -x c++ $i > /dev/null
+    c++ -DULAPI -I$HEADERS -I/usr/local/include -E -x c++ $i > /dev/null
 done
