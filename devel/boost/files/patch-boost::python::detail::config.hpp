--- boost/python/detail/config.hpp.orig	Tue Nov 29 23:27:18 2005
+++ boost/python/detail/config.hpp	Sun Dec 17 13:24:16 2006
@@ -111,7 +111,15 @@
 # define BOOST_PYTHON_OFFSETOF(s_name, s_member) \
         ((size_t)__INTADDR__(&(((s_name *)0)->s_member)))
 #else
-# define BOOST_PYTHON_OFFSETOF offsetof
+// workaround from http://www.freebsd.org/cgi/query-pr.cgi?pr=72307
+#if __GNUC__ <= 3
+#define BOOST_PYTHON_OFFSETOF(TYPE, MEMBER)\
+  (__offsetof__ (reinterpret_cast <size_t>\
+                 (&reinterpret_cast <const volatile char &>\
+                  (static_cast<TYPE *> (0)->MEMBER))))
+#else
+#define BOOST_PYTHON_OFFSETOF offsetof
+#endif
 #endif
 
 #endif // CONFIG_DWA052200_H_
