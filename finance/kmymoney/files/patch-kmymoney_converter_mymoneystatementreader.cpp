kmymoney/converter/mymoneystatementreader.cpp:1555:19: error: no member named 'abs' in namespace 'std'; did you mean 'labs'?
  const int gap = std::abs(matchedSchedule.transaction().postDate().toJulianDay() - importedTransaction.postDate().toJulianDay());
                  ^~~~~~~~
                  labs

--- kmymoney/converter/mymoneystatementreader.cpp.orig	2018-04-17 04:30:23 UTC
+++ kmymoney/converter/mymoneystatementreader.cpp
@@ -23,6 +23,7 @@
 
 #include "mymoneystatementreader.h"
 #include <typeinfo>
+#include <cstdlib>
 
 // ----------------------------------------------------------------------------
 // QT Headers
