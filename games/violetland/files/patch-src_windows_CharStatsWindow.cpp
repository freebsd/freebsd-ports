--- src/windows/CharStatsWindow.cpp.orig	2016-01-04 20:15:21 UTC
+++ src/windows/CharStatsWindow.cpp
@@ -1,5 +1,6 @@
 #include <boost/format.hpp>
 #include <boost/math/special_functions/round.hpp>
+#include <boost/type_traits/integral_constant.hpp>
 #include <libintl.h>
 #include <locale.h>
 #include "CharStatsWindow.h"
