--- boost/archive/iterators/wchar_from_mb.hpp.orig	2026-04-15 14:39:00 UTC
+++ boost/archive/iterators/wchar_from_mb.hpp
@@ -94,7 +94,7 @@ class wchar_from_mb
 
     template<typename T>
     struct sliding_buffer {
-        boost::array<T, 32> m_buffer;
+        boost::array<T, 32> m_buffer = {};
         typename boost::array<T, 32>::const_iterator m_next_available;
         typename boost::array<T, 32>::iterator m_next;
         bool m_done;
