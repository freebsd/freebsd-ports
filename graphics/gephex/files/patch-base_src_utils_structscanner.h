--- base/src/utils/structscanner.h.orig	Fri Dec 22 15:31:34 2006
+++ base/src/utils/structscanner.h	Fri Dec 22 15:32:09 2006
@@ -40,11 +40,11 @@
 {
  IStructTokenListener& m_listener;
   
-  void StructScanner::divideNameFromContent(const std::string& text,
+  void divideNameFromContent(const std::string& text,
 					    std::string& name,
 					    std::string& content) const;
-  void StructScanner::processName(const std::string& name) const;
-  void StructScanner::processContent(const std::string& content) const;
+  void processName(const std::string& name) const;
+  void processContent(const std::string& content) const;
   std::string::size_type
   findNextClosingBracket(const std::string& content,
 			 std::string::size_type n) const;
