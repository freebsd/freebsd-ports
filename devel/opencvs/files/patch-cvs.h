--- cvs.h.orig	2015-05-04 09:15:45 UTC
+++ cvs.h
@@ -29,6 +29,10 @@
 
 #include <signal.h>
 
+/* For building on FreeBSD */
+#include <time.h>
+#define	__dead
+
 #include "config.h"
 #include "file.h"
 #include "log.h"
@@ -189,7 +193,7 @@ struct cvs_var {
 	TAILQ_ENTRY(cvs_var) cv_link;
 };
 
-TAILQ_HEAD(, cvs_var) cvs_variables;
+TAILQ_HEAD(cvs_var_head, cvs_var);
 
 #define CVS_ROOT_CONNECTED	0x01
 
