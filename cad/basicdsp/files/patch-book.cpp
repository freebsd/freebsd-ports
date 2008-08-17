--- book.cpp.orig	2008-08-16 23:28:51.000000000 -0400
+++ book.cpp	2008-08-16 23:31:02.000000000 -0400
@@ -30,6 +30,11 @@
 {
 }
 
+int wxBook::ChangeSelection(size_t n)
+{
+  return n;
+}
+
 int wxBook::SetSelection(size_t n)
 {
   int old_selected = m_selected;
