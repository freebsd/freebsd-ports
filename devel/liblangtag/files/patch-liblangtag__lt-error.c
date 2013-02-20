--- liblangtag/lt-error.c	2012-11-06 09:15:59.000000000 -0600
+++ liblangtag/lt-error.c	2012-11-06 09:18:23.000000000 -0600
@@ -14,7 +14,6 @@
 #include "config.h"
 #endif
 
-#include <execinfo.h>
 #include <stdlib.h>
 #include "lt-list.h"
 #include "lt-mem.h"
@@ -98,9 +97,7 @@
 	     ...)
 {
 	va_list ap;
-	void *traces[1024];
 	lt_error_data_t *d = lt_mem_alloc_object(sizeof (lt_error_data_t));
-	int size;
 	lt_bool_t allocated;
 
 	lt_return_val_if_fail (error != NULL, NULL);
@@ -117,13 +114,9 @@
 	d->message = lt_strdup_vprintf(message, ap);
 	va_end(ap);
 
-	size = backtrace(traces, 1024);
-	if (size > 0)
-		d->traces = backtrace_symbols(traces, size);
-	d->stack_size = size;
+	d->stack_size = 0;
 
 	lt_mem_add_ref(&d->parent, d->message, free);
-	lt_mem_add_ref(&d->parent, d->traces, free);
 
 	allocated = (*error)->data == NULL;
 	(*error)->data = lt_list_append((*error)->data, d, (lt_destroy_func_t)lt_mem_unref);
