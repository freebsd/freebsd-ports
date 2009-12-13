--- unittests/bfc-testsuite.cpp.orig	2009-12-13 11:26:20.000000000 +0800
+++ unittests/bfc-testsuite.cpp	2009-12-13 11:27:02.000000000 +0800
@@ -11,6 +11,8 @@
 
 /* #include "../src/config.h"    - not an integral part of hamster but rather the, ah, 'platform independent' BFC */
 
+#define __USE_BSD 1
+
 #include <stdexcept>
 
 #include "bfc-testsuite.hpp"
