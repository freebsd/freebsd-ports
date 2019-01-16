--- libs/locale/src/util/iconv.hpp.orig	2017-09-02 09:56:14 UTC
+++ libs/locale/src/util/iconv.hpp
@@ -12,27 +12,7 @@
 
 namespace boost {
     namespace locale {
-#if defined(__ICONV_F_HIDE_INVALID) && defined(__FreeBSD__)
         extern "C" {
-            typedef size_t (*const_iconv_ptr_type)(iconv_t d,char const **in,size_t *insize,char **out,size_t *outsize,uint32_t,size_t *);
-            typedef size_t (*nonconst_iconv_ptr_type)(iconv_t d,char **in,size_t *insize,char **out,size_t *outsize,uint32_t,size_t *);
-        }
-        inline size_t do_iconv(const_iconv_ptr_type ptr,iconv_t d,char **in,size_t *insize,char **out,size_t *outsize)
-        {
-            char const **rin = const_cast<char const **>(in);
-            return ptr(d,rin,insize,out,outsize,__ICONV_F_HIDE_INVALID,0);
-        }
-        inline size_t do_iconv(nonconst_iconv_ptr_type ptr,iconv_t d,char **in,size_t *insize,char **out,size_t *outsize)
-        {
-            return ptr(d,in,insize,out,outsize,__ICONV_F_HIDE_INVALID,0);
-        }
-        inline size_t call_iconv(iconv_t d,char **in,size_t *insize,char **out,size_t *outsize)
-        {
-            char const **rin = const_cast<char const **>(in);
-            return do_iconv(__iconv, d, in,insize,out,outsize);
-        }
-#else
-        extern "C" {
             typedef size_t (*gnu_iconv_ptr_type)(iconv_t d,char const **in,size_t *insize,char **out,size_t *outsize);
             typedef size_t (*posix_iconv_ptr_type)(iconv_t d,char **in,size_t *insize,char **out,size_t *outsize);
         }
@@ -49,8 +29,17 @@ namespace boost {
         {
             return do_iconv( iconv, d, in,insize,out,outsize);
         }
+        inline iconv_t call_iconv_open(char const *to,char const *from)
+        {
+            iconv_t d = iconv_open(to,from);
+#if defined(ICONV_SET_ILSEQ_INVALID) && defined(__FreeBSD__)
+            if(d != (iconv_t)(-1)) {
+                int ilseq_invalid = 1;
+                iconvctl(d,ICONV_SET_ILSEQ_INVALID,&ilseq_invalid);
+            }
 #endif
-
+            return d;
+        }
     } // locale 
 } // boost
 
