--- wxOil/errors.cpp.orig	Thu Mar 23 20:23:57 2006
+++ wxOil/errors.cpp	Thu Mar 23 20:24:13 2006
@@ -1558,7 +1558,7 @@
 
 ********************************************************************************************/
 
-#ifndef __WXMAC__
+#if !defined(__WXMAC__) && !defined(__FreeBSD__)
 void Error::StackWalker::OnStackFrame(const wxStackFrame & frame)
 {
 #ifdef _DEBUG
