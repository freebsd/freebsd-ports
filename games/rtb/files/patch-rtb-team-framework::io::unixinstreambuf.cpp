--- rtb-team-framework/io/unixinstreambuf.cpp.orig	Wed Nov  3 05:09:04 2004
+++ rtb-team-framework/io/unixinstreambuf.cpp	Fri Dec 17 01:33:22 2004
@@ -29,6 +29,7 @@
 #include "../exceptions/keynotfoundexception.h"
 #include "../exceptions/confignotloadedexception.h"
 #include <sstream>
+#include <cerrno>
 
 /**
  * Namespace
