--- src/exception.cc.orig	Wed Aug 20 19:02:22 2003
+++ src/exception.cc	Wed Aug 20 19:02:25 2003
@@ -32,7 +32,7 @@
 {
 }
 
-UsogresException::~UsogresException()
+UsogresException::~UsogresException() throw()
 {
 	delete [] msg_buf;
 }
