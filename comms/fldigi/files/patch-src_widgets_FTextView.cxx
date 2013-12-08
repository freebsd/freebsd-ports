--- src/widgets/FTextView.cxx.orig	2013-11-18 20:35:57.882739310 -0500
+++ src/widgets/FTextView.cxx	2013-11-18 20:36:33.141869869 -0500
@@ -133,7 +133,7 @@
 ///
 void FTextBase::add(unsigned char c, int attr)
 {
-	char s[] = { FTEXT_DEF + attr, '\0' };
+	char s[] = { static_cast<char>(FTEXT_DEF + attr), '\0' };
 	sbuf->replace(insert_position(), insert_position() + 1, s);
 
 	s[0] = c;
