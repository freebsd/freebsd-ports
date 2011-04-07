--- ./pinedit/fileutil.h.orig	2003-03-30 22:44:13.000000000 +0400
+++ ./pinedit/fileutil.h	2011-04-07 10:30:29.996841054 +0400
@@ -36,14 +36,14 @@
   int writeGroup(QTextStream & file, Group * Group);
   int writeShape(QTextStream & file, Shape3D * shape);
   int writeBehavior(QTextStream & file, Behavior * beh);
-  inline void FileUtil::incIndent() {
+  inline void incIndent() {
     ++m_iIndent;
   };
-  inline void FileUtil::decIndent() {
+  inline void decIndent() {
     --m_iIndent;
     if (m_iIndent < 0) m_iIndent = 0;
   };
-  inline void FileUtil::resetIndent() {
+  inline void resetIndent() {
     m_iIndent = 0;
   };
   PinEditDoc * p_Doc;
