
$FreeBSD$

--- plm/metadata/id3v2/io_strings.h.orig	Thu Jun 20 08:41:07 2002
+++ plm/metadata/id3v2/io_strings.h	Sat Dec 21 17:30:55 2002
@@ -63,7 +63,7 @@
       }
       virtual size_type readChars(char_type buf[], size_type len)
       {
-        size_type size = min(len, _string.size() - _cur);
+        size_type size = min((unsigned int)len, (unsigned int)(_string.size() - _cur));
         _string.copy(reinterpret_cast<String::value_type *>(buf), size, _cur);
         _cur += size;
         return size;
@@ -100,7 +100,7 @@
 
       virtual size_type skipChars(size_type len)
       {
-        size_type size = min(len, _string.size() - _cur);
+        size_type size = min((unsigned int)len, (unsigned int)(_string.size() - _cur));
         _cur += size;
         return size;
       }
@@ -133,7 +133,7 @@
       }
       virtual size_type readChars(char_type buf[], size_type len)
       {
-        size_type size = min(len, _string.size() - _cur);
+        size_type size = min((unsigned int)len, (unsigned int)(_string.size() - _cur));
         _string.copy(reinterpret_cast<BString::value_type *>(buf), size, _cur);
         _cur += size;
         return size;
@@ -170,7 +170,7 @@
 
       virtual size_type skipChars(size_type len)
       {
-        size_type size = min(len, _string.size() - _cur);
+        size_type size = min((unsigned int)len,(unsigned int)( _string.size() - _cur));
         _cur += size;
         return size;
       }
