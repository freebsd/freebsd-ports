--- tagmanager/parse.h.orig	Fri Feb 15 16:44:43 2002
+++ tagmanager/parse.h	Fri Feb 15 16:44:54 2002
@@ -13,6 +13,7 @@
 /*
 *   INCLUDE FILES
 */
+#include <sys/types.h>
 #include "general.h"	/* must always come first */
 
 #include "parsers.h"	/* contains list of parsers */
