--- src/MemoryX.h.orig	2018-02-22 14:12:04.240599000 -0800
+++ src/MemoryX.h	2018-02-22 14:01:53.685861000 -0800
@@ -1,6 +1,7 @@
 #ifndef __AUDACITY_MEMORY_X_H__
 #define __AUDACITY_MEMORY_X_H__
 
+#include <stdlib.h>
 // C++ standard header <memory> with a few extensions
 #include <memory>
 #ifndef safenew
@@ -1171,7 +1172,7 @@
    namespace tr1
    {
 #endif
-      template<typename T> struct hash;
+      //template<typename T> struct hash;
       template<> struct hash< wxString > {
          size_t operator () (const wxString &str) const // noexcept
          {
