--- imsp/dispatch.h	2003/04/03 13:38:05	1.1
+++ imsp/dispatch.h	2003/04/03 13:38:26
@@ -42,7 +42,7 @@
  * Start Date: 2/22/93
  */
 
-#define MAX_BUF 4096
+#define MAX_BUF (4096 * 1024)
 
 #include <sasl/sasl.h>
 
