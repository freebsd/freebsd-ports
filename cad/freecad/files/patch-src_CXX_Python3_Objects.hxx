--- src/CXX/Python3/Objects.hxx.orig	2024-11-18 16:48:00 UTC
+++ src/CXX/Python3/Objects.hxx
@@ -1787,7 +1787,7 @@ namespace Py
     typedef std::basic_string<Py_UNICODE> unicodestring;
     extern Py_UNICODE unicode_null_string[1];
 #endif
-    typedef std::basic_string<Py_UCS4> ucs4string;
+    typedef std::basic_string<char32_t> ucs4string;
     extern Py_UCS4 ucs4_null_string[1];
 
     class PYCXX_EXPORT Byte: public Object
@@ -2237,7 +2237,7 @@ namespace Py
             {
                 ifPyErrorThrowCxxException();
             }
-            ucs4string ucs4( buf, size() );
+            ucs4string ucs4( reinterpret_cast<const char32_t*>(buf), size() );
             delete[] buf;
 
             return ucs4;
