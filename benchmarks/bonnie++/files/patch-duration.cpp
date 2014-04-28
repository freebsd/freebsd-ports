--- duration.cpp.orig   2009-08-21 18:45:50.068536643 +0000
+++ duration.cpp        2009-08-21 18:45:58.564755017 +0000
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
