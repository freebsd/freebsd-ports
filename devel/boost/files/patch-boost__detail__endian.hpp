--- boost/detail/endian.hpp.orig      2009-04-08 16:12:11.000000000 +0200
+++ boost/detail/endian.hpp   2009-04-08 16:13:28.000000000 +0200
@@ -42,6 +42,18 @@
 #  error Unknown machine endianness detected.
 # endif
 # define BOOST_BYTE_ORDER __BYTE_ORDER
+#elif defined (__FreeBSD__)
+# include <machine/endian.h>
+# if (_BYTE_ORDER == _LITTLE_ENDIAN)
+#  define BOOST_LITTLE_ENDIAN
+# elif (_BYTE_ORDER == _BIG_ENDIAN)
+#  define BOOST_BIG_ENDIAN
+# elif (_BYTE_ORDER == _PDP_ENDIAN)
+#  define BOOST_PDP_ENDIAN
+# else
+#  error Unknown machine endianness detected.
+# endif
+# define BOOST_BYTE_ORDER _BYTE_ORDER
 #elif defined(_BIG_ENDIAN)
 # define BOOST_BIG_ENDIAN
 # define BOOST_BYTE_ORDER 4321
