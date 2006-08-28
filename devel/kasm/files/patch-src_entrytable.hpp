--- src/entrytable.hpp.orig	Fri Jan 26 11:39:04 2001
+++ src/entrytable.hpp	Mon Aug 28 07:56:38 2006
@@ -25,6 +25,8 @@
 #ifndef __ENTRYTABLE_HPP
 #define __ENTRYTABLE_HPP
 
+#include <map>
+using namespace std;
 
 #define T_POINTER  0
 #define T_ROMPTR   1
