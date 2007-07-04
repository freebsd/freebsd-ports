--- boost/detail/atomic_count_gcc.hpp.orig	2005/04/02 11:37:53	1.5
+++ boost/detail/atomic_count_gcc.hpp	2007/05/21 01:34:43	1.5.8.1
@@ -17,7 +17,11 @@
 //  http://www.boost.org/LICENSE_1_0.txt)
 //
 
-#include <bits/atomicity.h>
+#if (__GNUC__ > 4) || ((__GNUC__ == 4) && (__GNUC_MINOR__ >= 2))
+# include <ext/atomicity.h>
+#else
+# include <bits/atomicity.h>
+#endif
 
 namespace boost
 {
