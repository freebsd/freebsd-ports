--- modules/src/oscinmodule/oscinmodule.cpp.orig
+++ modules/src/oscinmodule/oscinmodule.cpp
@@ -4,12 +4,13 @@
 #include <vector>
 #include <stdexcept>
 
-#include <sys/socket.h>
 #include <sys/types.h>
+#include <sys/socket.h>
 #include <netinet/in.h>
 #include <errno.h>
 #include <netdb.h>
 #include <fcntl.h>
+#include <unistd.h>
 
 static logT s_log;
 
