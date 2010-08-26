--- m4/zlib.m4~
+++ m4/zlib.m4
@@ -16,11 +16,9 @@ fi
 AC_MSG_CHECKING([for zlib location])
 if test x"$zlib_prefix" = x ; then
   zlib_header_found="no"
-  for dir in /usr/local /usr ; do
+  for dir in /usr ; do
   if test -f "$dir/include/zlib.h" ; then
     zlib_header_found="yes"
-    ZLIB_CFLAGS="-I$dir/include"
-    ZLIB_LDFLAGS="-L$dir/lib"
     break
   fi
   done
