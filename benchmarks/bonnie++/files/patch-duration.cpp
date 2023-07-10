--- duration.cpp.orig	2016-06-30 09:41:58 UTC
+++ duration.cpp
@@ -1,5 +1,3 @@
-using namespace std;
-
 #include <stdlib.h>
 
 #include "duration.h"
@@ -19,6 +17,8 @@ using namespace std;
 #include <algo.h>
 #endif
 #endif
+
+using namespace std;
 
 Duration_Base::Duration_Base()
  : m_start(0.0)
