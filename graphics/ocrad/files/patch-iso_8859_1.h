--- iso_8859_1.h.orig	Wed Dec  3 12:12:01 2003
+++ iso_8859_1.h	Tue Dec 30 17:12:05 2003
@@ -100,6 +100,12 @@
   static unsigned char base_letter( unsigned char ch ) throw();
   static unsigned char compose( unsigned char base_letter,
                                 unsigned char accent ) throw();
+#undef isalnum
+#undef isalpha
+#undef islower
+#undef isupper
+#undef isvowel
+#undef toupper
   static bool isalnum( unsigned char ch ) throw();
   static bool isalpha( unsigned char ch ) throw();
   static bool islower( unsigned char ch ) throw();
