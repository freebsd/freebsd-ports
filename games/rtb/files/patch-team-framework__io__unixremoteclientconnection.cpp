--- team-framework/io/unixremoteclientconnection.cpp.orig
+++ team-framework/io/unixremoteclientconnection.cpp
@@ -36,6 +36,7 @@
 #include <iostream>
 #include <sstream>
 #include <ios>
+#include <unistd.h>
 
 /**
  * Namespace
