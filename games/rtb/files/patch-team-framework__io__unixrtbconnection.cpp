--- team-framework/io/unixrtbconnection.cpp.orig
+++ team-framework/io/unixrtbconnection.cpp
@@ -33,6 +33,8 @@
 #include <iostream>
 #include <sstream>
 #include <ios>
+#include <sys/types.h>
+#include <unistd.h>
 
 /**
  * Namespace
