--- libs/pbd/pbd/stl_delete.h.orig
+++ libs/pbd/pbd/stl_delete.h
@@ -24,7 +24,7 @@
 /* To actually use any of these deletion functions, you need to
    first include the revelant container type header.
 */
-#if defined(_CPP_VECTOR) || defined(_GLIBCXX_VECTOR) || defined(__SGI_STL_VECTOR)
+#if defined(_LIBCPP_VECTOR) || defined(_GLIBCXX_VECTOR) || defined(__SGI_STL_VECTOR)
 template<class T> void vector_delete (std::vector<T *> *vec) 
 {
 	typename std::vector<T *>::iterator i;
@@ -34,7 +34,7 @@
 	}
 	vec->clear ();
 }
-#endif // _CPP_VECTOR || _GLIBCXX_VECTOR || __SGI_STL_VECTOR
+#endif // _LIBCPP_VECTOR || _GLIBCXX_VECTOR || __SGI_STL_VECTOR
 
 #if defined(_CPP_MAP) || defined(_GLIBCXX_MAP) || defined(__SGI_STL_MAP)
 template<class K, class T> void map_delete (std::map<K, T *> *m) 
