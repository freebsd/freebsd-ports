--- boost/python/detail/config.hpp.orig	Tue Dec 14 14:17:42 2004
+++ boost/python/detail/config.hpp	Tue Dec 14 14:19:36 2004
@@ -110,7 +110,11 @@
 # define BOOST_PYTHON_OFFSETOF(s_name, s_member) \
         ((size_t)__INTADDR__(&(((s_name *)0)->s_member)))
 #else
-# define BOOST_PYTHON_OFFSETOF offsetof
+// workaround from http://www.freebsd.org/cgi/query-pr.cgi?pr=72307
+#define BOOST_PYTHON_OFFSETOF(TYPE, MEMBER)\
+  (__offsetof__ (reinterpret_cast <size_t>\
+                 (&reinterpret_cast <const volatile char &>\
+                  (static_cast<TYPE *> (0)->MEMBER))))
 #endif
 
 #endif // CONFIG_DWA052200_H_
