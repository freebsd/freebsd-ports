--- src/server_poll/inetd.cpp.orig
+++ src/server_poll/inetd.cpp
@@ -17,7 +17,8 @@
  */
 
 #include <cassert>
-#include <glib/gmain.h>
+#include <unistd.h>
+#include <glib.h>
 
 #include "inetd.h"
 #include "irc/irc.h"
