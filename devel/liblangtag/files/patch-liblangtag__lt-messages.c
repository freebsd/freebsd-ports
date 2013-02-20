--- liblangtag/lt-messages.c	2012-11-06 09:15:59.000000000 -0600
+++ liblangtag/lt-messages.c	2012-11-06 09:20:58.000000000 -0600
@@ -17,7 +17,6 @@
 #include "config.h"
 #endif
 
-#include <execinfo.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -98,27 +97,6 @@
 static void
 _lt_message_stacktrace(void)
 {
-	void *traces[1024];
-	char **strings;
-	int size, i;
-
-	size = backtrace(traces, 1024);
-	if (size > 0) {
-		strings = backtrace_symbols(traces, size);
-		lt_debug(LT_MSGCAT_TRACE, "Stacktrace:");
-		/*
-		 * XXX:
-		 * 0.. here.
-		 * 1.. _lt_message_default_handler
-		 * 2.. lt_message_vprintf
-		 * 3.. lt_message_printf
-		 * 4.. lt_* macros
-		 */
-		for (i = 4; i < size; i++) {
-			lt_debug(LT_MSGCAT_TRACE, "  %d. %s", i - 3, strings[i]);
-		}
-		free(strings);
-	}
 }
 
 static void
