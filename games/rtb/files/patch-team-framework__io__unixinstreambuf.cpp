--- team-framework/io/unixinstreambuf.cpp.orig	2005-01-06 17:59:28 UTC
+++ team-framework/io/unixinstreambuf.cpp
@@ -28,11 +28,14 @@
 #include <common.h>
 
 #include "unixinstreambuf.h"
+#include <cstring>
 #include "../rtbglobal/masterresourcecontrol.h"
 #include "../exceptions/keynotfoundexception.h"
 #include "../exceptions/confignotloadedexception.h"
 #include <sstream>
 #include <errno.h>
+#include <sys/types.h>
+#include <unistd.h>
 
 /**
  * Namespace
