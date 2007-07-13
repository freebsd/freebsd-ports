--- arpc/rpctypes.h.orig	2005-11-22 17:42:29.000000000 +0000
+++ arpc/rpctypes.h	2007-07-12 22:38:43.000000000 +0000
@@ -271,9 +271,9 @@
   using rpc_vec<char, n>::base;
   using rpc_vec<char, n>::size;
 
-  void setstrmem (const str &s) { set (s.cstr (), s.len ()); }
+  void setstrmem (const str &s) { rpc_vec<char, n>::set (s.cstr, s.len ()); }
   rpc_bytes &operator= (const str &s)
-    { setsize (s.len ()); memcpy (base (), s.cstr (), size ()); return *this; }
+    { rpc_vec<char, n>::setsize (s.len ()); memcpy (base (), s.cstr (), size ()); return *this; }
   template<size_t m> rpc_bytes &operator= (const rpc_vec<char, m> &v)
     { rpc_vec<char, n>::operator= (v); return *this; }
   template<size_t m> rpc_bytes &operator= (const array<char, m> &v)
