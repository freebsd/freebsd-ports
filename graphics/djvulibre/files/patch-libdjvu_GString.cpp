--- libdjvu/GString.cpp.orig	Tue Dec  2 04:57:39 2003
+++ libdjvu/GString.cpp	Fri Oct  1 14:05:22 2004
@@ -2666,7 +2666,7 @@
 { init(GStringRep::UTF8::create(&dat,0,1)); }
 
 GUTF8String::GUTF8String(const GUTF8String &fmt, va_list &args)
-{ init(fmt.ptr?fmt->vformat(args):fmt); }
+{ init(fmt.ptr?fmt->vformat(args):(GUTF8String &)fmt); }
 
 GUTF8String::GUTF8String(const char *str)
 { init(GStringRep::UTF8::create(str)); }
@@ -2712,7 +2712,7 @@
 GNativeString::operator+(const GUTF8String &s2) const
 {
   return GStringRep::UTF8::create(
-    ptr?(*this)->toUTF8(true):(*this),s2);
+    ptr?(*this)->toUTF8(true):(GP<GStringRep>)(*this),s2);
 }
 #endif
 
