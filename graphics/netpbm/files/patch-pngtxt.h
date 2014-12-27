$OpenBSD: patch-converter_other_pngtxt_h,v 1.1 2011/07/08 20:36:09 naddy Exp $

Fix build with png-1.5.

--- converter/other/pngtxt.h.orig	Fri Aug 18 21:12:28 2006
+++ converter/other/pngtxt.h	Mon Jul  4 14:21:23 2011
@@ -5,7 +5,8 @@
 #include <png.h>
 
 void 
-pnmpng_read_text (png_info * const info_ptr, 
+pnmpng_read_text (png_struct * png_ptr,
+                  png_info * const info_ptr, 
                   FILE *     const tfp, 
                   bool const ztxt,
                   bool const verbose);
