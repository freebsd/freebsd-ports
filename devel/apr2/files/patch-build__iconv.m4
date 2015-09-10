--- build/iconv.m4.orig	2015-01-02 17:14:32 UTC
+++ build/iconv.m4
@@ -44,7 +44,7 @@ AC_ARG_WITH(iconv,[  --with-iconv[=DIR] 
       if test -f "$apu_iconv_dir/include/iconv.h"; then
         have_iconv="1"
         APR_ADDTO(CPPFLAGS,[-I$apu_iconv_dir/include])
-        APR_ADDTO(LDFLAGS,[-L$apu_iconv_dir/lib])
+        APR_ADDTO(LDFLAGS,[-L$apu_iconv_dir/lib -liconv])
       fi
     fi
   ])
