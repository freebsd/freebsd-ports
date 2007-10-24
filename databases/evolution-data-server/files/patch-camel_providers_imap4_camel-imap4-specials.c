--- camel/providers/imap4/camel-imap4-specials.c.orig	Thu May 17 18:11:10 2007
+++ camel/providers/imap4/camel-imap4-specials.c	Thu May 17 18:11:17 2007
@@ -22,6 +22,7 @@
 #include <config.h>
 #endif
 
+#include <glib.h>
 #include <string.h>
 
 #include "camel-imap4-specials.h"
