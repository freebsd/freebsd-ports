--- sal/textenc/textenc.c.orig	Mon Feb 24 17:46:29 2003
+++ sal/textenc/textenc.c	Tue Feb 25 16:51:28 2003
@@ -254,7 +254,8 @@
             &aImplJISX0212TextEncodingData, /* JIS_X_0212 */
             &aImplMS1361TextEncodingData, /* MS_1361 */
             &aImplGb18030TextEncodingData, /* GB_18030 */
-            &aImplBig5HkscsTextEncodingData }; /* BIG5_HKSCS */
+            &aImplBig5HkscsTextEncodingData, /* BIG5_HKSCS */
+            &aImplKOI8UTextEncodingData }; /* KOI8_U */
     OSL_ENSURE(nEncoding >= RTL_TEXTENCODING_DONTKNOW
                && nEncoding <= RTL_TEXTENCODING_UNICODE,
                "specification violation");
