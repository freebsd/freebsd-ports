--- iso_8859_1.h.orig	Sun Nov 16 17:14:19 2003
+++ iso_8859_1.h	Sun Nov 16 17:33:51 2003
@@ -100,6 +100,11 @@
   static unsigned char base_letter( unsigned char ch ) throw();
   static unsigned char compose( unsigned char base_letter,
                                 unsigned char accent ) throw();
+#undef isalnum
+#undef isalpha
+#undef isupper
+#undef isvowel
+#undef toupper
   static bool isalnum( unsigned char ch ) throw();
   static bool isalpha( unsigned char ch ) throw();
   static bool isupper( unsigned char ch ) throw();
