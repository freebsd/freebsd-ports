- fix the error: ./include/base64.h:24:2: error: reference to 'byte' is ambiguous
- the alternative 'byte' definition is std::byte

--- src/include/base64.h.orig	2023-07-16 16:44:53 UTC
+++ src/include/base64.h
@@ -21,8 +21,8 @@ class base64 { (private)
 	size_t iolen;
 	size_t iocp;
 	bool ateof;
-	byte dtable[256];
-	byte etable[256];
+	::byte dtable[256];
+	::byte etable[256];
 	int linelength;
 	bool crlf;
 	void init();
