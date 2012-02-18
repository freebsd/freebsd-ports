--- opennurbs_array_defs.h.orig	2012-01-20 20:18:46.000000000 +0100
+++ opennurbs_array_defs.h	2012-01-20 20:18:20.000000000 +0100
@@ -1459,7 +1459,7 @@
 #else
   // for lamer 64 bit compilers
   return found ? ((int)((((ON__UINT64)found) - ((ON__UINT64)m_a))/sizeof(T))) : -1;
-#endif#endif
+#endif
 }
 
 template <class T>
@@ -1476,7 +1476,7 @@
 #else
   // for lamer 64 bit compilers
   return found ? ((int)((((ON__UINT64)found) - ((ON__UINT64)m_a))/sizeof(T))) : -1;
-#endif#endif
+#endif
 }
 
 template <class T>
