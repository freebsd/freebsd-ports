--- src/exception.h.orig	Mon Apr 15 22:00:03 2002
+++ src/exception.h	Wed Aug 20 19:01:50 2003
@@ -37,56 +37,56 @@
 	char* msg_buf;
 public:
 	UsogresException(const char* fn, int ln);
-	virtual ~UsogresException();
+	virtual ~UsogresException() throw();
 	virtual const char* where();
 };
 
 class ImcompletedValueException : public UsogresException {
 public:
 	ImcompletedValueException(const char* fn, int ln) : UsogresException(fn, ln)  {}
-	virtual const char* what() const { return "ImcompletedValueException"; }
+	virtual const char* what() const throw() { return "ImcompletedValueException"; }
 };
 
 class MemoryException : public UsogresException {
 public:
   MemoryException(const char* fn, int ln) : UsogresException(fn, ln) {}
-  virtual const char* what() const { return "MemoryException"; }
+  virtual const char* what() const throw() { return "MemoryException"; }
 };
 
 class FileException : public UsogresException {
 public:
   FileException(const char* fn, int ln) : UsogresException(fn, ln) {}
-  virtual const char* what() const { return "FileException"; }
+  virtual const char* what() const throw() { return "FileException"; }
 };
 
 class EnvException : public UsogresException {
 public:
   EnvException(const char* fn, int ln) : UsogresException(fn, ln) {}
-  virtual const char* what() const { return "EnvException"; }
+  virtual const char* what() const throw() { return "EnvException"; }
 };
 
 class FileFormatException : public UsogresException {
 public:
   FileFormatException(const char* fn, int ln) : UsogresException(fn, ln) {}
-  virtual const char* what() const { return "FileFormatException"; }
+  virtual const char* what() const throw() { return "FileFormatException"; }
 };
 
 class TokenFormatException : public UsogresException {
 public:
   TokenFormatException(const char* fn, int ln) : UsogresException(fn, ln) {}
-  virtual const char* what() const { return "TokenFormatException"; }
+  virtual const char* what() const throw() { return "TokenFormatException"; }
 };
 
 class LogicalException : public UsogresException {
 public:
   LogicalException(const char* fn, int ln) : UsogresException(fn, ln) {}
-  virtual const char* what() const { return "LogicalException"; }
+  virtual const char* what() const throw() { return "LogicalException"; }
 };
 
 class InvalidProtocolException : public UsogresException {
 public:
   InvalidProtocolException(const char* fn, int ln) : UsogresException(fn, ln) {}
-  virtual const char* what() const { return "InvalidProtocolException"; }
+  virtual const char* what() const throw() { return "InvalidProtocolException"; }
 };
 
 #endif
