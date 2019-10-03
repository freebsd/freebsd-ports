--- CImg.h.orig	2019-09-24 20:44:55 UTC
+++ CImg.h
@@ -6737,7 +6737,7 @@ namespace cimg_library_suffixed {
     }
 
     //! Return \c true if input character is blank (space, tab, or non-printable character).
-    inline bool is_blank(const char c) {
+    inline bool is_blank(const signed char c) {
       return c>=0 && c<=' ';
     }
 
