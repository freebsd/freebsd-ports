--- duration.cpp.orig	2008-12-23 22:26:42 UTC
+++ duration.cpp
@@ -1,5 +1,3 @@
-using namespace std;
-
 #include <stdlib.h>
 
 #include "duration.h"
@@ -20,6 +18,8 @@ using namespace std;
 #endif
 #endif
 
+using namespace std;
+
 Duration_Base::Duration_Base()
  : m_start(0.0)
  , m_max(0.0)
@@ -38,7 +38,7 @@ double Duration_Base::stop()
   getTime(&tv);
   double ret;
   ret = tv - m_start;
-  m_max = __max(m_max, ret);
+  m_max = max(m_max, ret);
   return ret;
 }
 
