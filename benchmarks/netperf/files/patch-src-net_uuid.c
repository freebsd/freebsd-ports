--- src/net_uuid.c~	2008-10-25 08:13:44.000000000 +0900
+++ src/net_uuid.c	2009-06-16 15:37:55.000000000 +0900
@@ -38,7 +38,6 @@
 #else
 #include <sys/types.h>
 #include <sys/time.h>
-#include <sys/sysinfo.h>
 #endif
 
 /* system dependent call to get the current system time. Returned as
