--- libtest/timer.hpp.orig	2019-04-09 09:38:58 UTC
+++ libtest/timer.hpp
@@ -39,6 +39,9 @@
 #include <cstdlib>
 #include <ctime>
 #include <iostream>
+#ifdef __FreeBSD__
+#include <stdint.h>
+#endif
 
 
 namespace libtest {
