--- deps/rapidjson-1.1.0/rapidjson/document.h.orig	2022-12-08 07:44:48 UTC
+++ deps/rapidjson-1.1.0/rapidjson/document.h
@@ -316,8 +316,6 @@ struct GenericStringRef {
 
     GenericStringRef(const GenericStringRef& rhs) : s(rhs.s), length(rhs.length) {}
 
-    GenericStringRef& operator=(const GenericStringRef& rhs) { s = rhs.s; length = rhs.length; }
-
     //! implicit conversion to plain CharType pointer
     operator const Ch *() const { return s; }
 
