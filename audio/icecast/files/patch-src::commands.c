--- src/commands.c
+++ src/commands.c
@@ -84,8 +84,8 @@
 #include "interpreter.h"
 
 #include <time.h>
+#include <errno.h>
 
-extern int errno;
 extern int running;
 extern server_info_t info;
 extern mutex_t library_mutex;
@@ -2884,8 +2884,11 @@
 	time_t before = 0;
 
 	if (!arg || !arg[0])
+	{
 		admin_write_line (req, ADMIN_SHOW_PING_INVALID_SYNTAX, PING_SYNTAX);
-	
+		return 0;
+	}
+		
 	host[0] = '\0';
 
 	if (splitc (host, arg, ':') != NULL)
