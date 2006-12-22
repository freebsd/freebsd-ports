--- common/plpngdec.h.orig	Fri Dec 22 17:53:56 2006
+++ common/plpngdec.h	Fri Dec 22 17:59:29 2006
@@ -49,12 +49,12 @@
 
 private:
 
-  static void PLPNGDecoder::user_error_fn
+  static void user_error_fn
     ( png_structp png_ptr,
       png_const_charp error_msg
     );
 
-  static void PLPNGDecoder::user_warning_fn
+  static void user_warning_fn
     ( png_structp png_ptr,
       png_const_charp warning_msg
     );
