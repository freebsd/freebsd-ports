--- ./build/iconv.m4.orig	2010-05-26 23:19:28.011405098 -0400
+++ ./build/iconv.m4	2010-05-26 23:19:37.002271826 -0400
@@ -44,7 +44,7 @@
       if test -f "$apu_iconv_dir/include/iconv.h"; then
         have_iconv="1"
         APR_ADDTO(CPPFLAGS,[-I$apu_iconv_dir/include])
-        APR_ADDTO(LDFLAGS,[-L$apu_iconv_dir/lib])
+        APR_ADDTO(LDFLAGS,[-L$apu_iconv_dir/lib -liconv])
       fi
     fi
   ])
