--- libdjvu/GString.h.orig	Tue Dec  2 04:57:40 2003
+++ libdjvu/GString.h	Fri Oct  1 13:52:39 2004
@@ -1558,7 +1558,7 @@
 inline
 GNativeString::GNativeString(const GNativeString &fmt, va_list &args)
 {
-  init(fmt.ptr?fmt->vformat(args):fmt);
+  init(fmt.ptr?fmt->vformat(args):(GNativeString &)fmt);
 }
 
 inline GNativeString
