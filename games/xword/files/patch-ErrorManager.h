--- src/ErrorManager.h.orig	Sat Nov  2 02:37:03 2002
+++ src/ErrorManager.h	Sat Nov  2 02:48:40 2002
@@ -77,7 +77,7 @@
 typedef ErrorManager EM;
 
 
-class file_error : public runtime_error
+class file_error : public std::runtime_error
 {
 	public:
 		file_error(const std::string& str);
