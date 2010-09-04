--- bsnes/nall/function.hpp.orig	2010-09-02 13:10:15.000000000 +0200
+++ bsnes/nall/function.hpp	2010-09-02 13:10:34.000000000 +0200
@@ -1,7 +1,11 @@
 #ifndef NALL_FUNCTION_HPP
 #define NALL_FUNCTION_HPP
 
-#include <malloc.h>
+#ifdef __FreeBSD__
+# include <stdlib.h>
+#else
+# include <malloc.h>
+#endif
 #include <functional>
 #include <type_traits>
 
