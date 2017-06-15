--- duration.cpp.orig	2016-06-30 09:41:58.000000000 +0000
+++ duration.cpp	2016-10-18 20:09:09.173611133 +0000
@@ -1,5 +1,3 @@
-using namespace std;
-
 #include <stdlib.h>
 
 #include "duration.h"
@@ -20,6 +18,8 @@
 #endif
 #endif
 
+using namespace std;
+
 Duration_Base::Duration_Base()
  : m_start(0.0)
  , m_max(0.0)
