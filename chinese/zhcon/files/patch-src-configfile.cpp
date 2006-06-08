--- src/configfile.cpp.orig	Tue Jan 25 07:38:59 2005
+++ src/configfile.cpp	Tue Jan 25 07:41:19 2005
@@ -19,13 +19,18 @@
 #include <stdexcept>
 #include <fstream>
 #include <cstdlib>
+#include <sys/types.h>
+#include <unistd.h>
 #include "configfile.h"
 
 ConfigFile::ConfigFile(const char *fn) {
+    uid_t euid = geteuid();
+    seteuid(getuid());
     ifstream in(fn);
     if (!in)
         throw runtime_error("Could not open config file!");
     ParseFile(in);
+    seteuid(euid);
 }
 
 ConfigFile::~ConfigFile() {}
