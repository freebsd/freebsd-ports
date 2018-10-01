--- src/MemoryX.h.orig	2018-10-01 14:07:33 UTC
+++ src/MemoryX.h
@@ -1,6 +1,7 @@
 #ifndef __AUDACITY_MEMORY_X_H__
 #define __AUDACITY_MEMORY_X_H__
 
+#include <stdlib.h>
 // C++ standard header <memory> with a few extensions
 #include <memory>
 #include <cstdlib> // Needed for free.
@@ -706,7 +707,7 @@ make_value_transform_iterator(const Iterator &iterator
 // For using std::unordered_map on wxString
 namespace std
 {
-   template<typename T> struct hash;
+   //template<typename T> struct hash;
    template<> struct hash< wxString > {
       size_t operator () (const wxString &str) const // noexcept
       {
