--- wxOil/errors.h.orig	Thu Mar 23 18:38:06 2006
+++ wxOil/errors.h	Thu Mar 23 18:39:20 2006
@@ -106,7 +106,8 @@
 #ifndef INC_ERRORS
 #define INC_ERRORS
 
-#ifndef __WXMAC__
+// FreeBSD does not provide backtrace()
+#if !defined(__WXMAC__) && !defined(__FreeBSD__)
 #include <wx/stackwalk.h>
 #endif
 
@@ -594,7 +595,8 @@
 public:
 	static void DumpStack(UINT32 frames=0);
 
-#ifndef __WXMAC__
+// FreeBSD does not provide backtrace()
+#if !defined(__WXMAC__) && !defined(__FreeBSD__)
 	class StackWalker : public wxStackWalker
 	{
 		public:
