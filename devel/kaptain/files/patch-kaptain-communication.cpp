--- kaptain/communication.cpp.orig	Wed Aug 14 12:13:13 2002
+++ kaptain/communication.cpp	Fri Dec 20 16:14:31 2002
@@ -8,7 +8,7 @@
 #include <sys/stat.h>
 #include <netdb.h>
 #include <fcntl.h>
-#include <iostream.h>
+#include <iostream>
 #include <sstream>
 #include "global.h"
 #include "tools.h"
@@ -16,6 +16,8 @@
 #include "grammar.h"
 
 #define NO_MORE_IO "At most one i/o channel is allowed.\n"
+
+using namespace std;
 
 extern Grammar * yygrammar;
 
