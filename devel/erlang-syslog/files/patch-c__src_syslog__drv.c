--- c_src/syslog_drv.c.orig	2015-05-24 12:12:35 UTC
+++ c_src/syslog_drv.c
@@ -25,6 +25,7 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
 #include <syslog.h>
 #include <stdarg.h>
 #include <string.h>
+#include <netinet/in.h>
 
 #include <ei.h>
 #include <erl_driver.h>
