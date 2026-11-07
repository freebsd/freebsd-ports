--- src/runtime/src/coreclr/pal/src/include/pal/stackstring.hpp.orig	2026-10-22 19:21:32 UTC
+++ src/runtime/src/coreclr/pal/src/include/pal/stackstring.hpp
@@ -110,6 +110,7 @@ class StackString (public)
     StackString()
         : m_buffer(m_innerBuffer), m_size(STACKCOUNT+1), m_count(0)
     {
+        NullTerminate();
     }
 
 
