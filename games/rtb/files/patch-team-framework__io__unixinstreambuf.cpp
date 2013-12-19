--- team-framework/io/unixinstreambuf.cpp.orig
+++ team-framework/io/unixinstreambuf.cpp
@@ -33,6 +33,8 @@
 #include "../exceptions/confignotloadedexception.h"
 #include <sstream>
 #include <errno.h>
+#include <sys/types.h>
+#include <unistd.h>
 
 /**
  * Namespace
