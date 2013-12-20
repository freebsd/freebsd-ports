--- utils/Value.hpp.orig	2013-11-30 21:16:05.000000000 +0900
+++ utils/Value.hpp	2013-11-30 21:16:35.000000000 +0900
@@ -15,7 +15,8 @@
 #ifndef _Value_hpp_
 #define _Value_hpp_
 
-#include <stdio.h>
+#include <cstdio>
+#include <cstdlib>
 #include <string>
 
 #include <Trace.hpp>
