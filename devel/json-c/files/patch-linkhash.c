Obtained from:	https://github.com/json-c/json-c/commit/31243e4d1204ef78be34b0fcae73221eee6b83be
		https://github.com/json-c/json-c/commit/519dfe1591d85432986f9762d41d1a883198c157

--- linkhash.c.orig	2020-04-19 03:36:00 UTC
+++ linkhash.c
@@ -12,6 +12,7 @@
 
 #include "config.h"
 
+#include <assert.h>
 #include <limits.h>
 #include <stdarg.h>
 #include <stddef.h>
@@ -499,6 +500,8 @@ struct lh_table *lh_table_new(int size, lh_entry_free_
 	int i;
 	struct lh_table *t;
 
+	/* Allocate space for elements to avoid divisions by zero. */
+	assert(size > 0);
 	t = (struct lh_table *)calloc(1, sizeof(struct lh_table));
 	if (!t)
 		return NULL;
@@ -577,9 +580,12 @@ int lh_table_insert_w_hash(struct lh_table *t, const v
 {
 	unsigned long n;
 
-	if (t->count >= t->size * LH_LOAD_FACTOR)
-		if (lh_table_resize(t, t->size * 2) != 0)
+	if (t->count >= t->size * LH_LOAD_FACTOR) {
+		/* Avoid signed integer overflow with large tables. */
+		int new_size = (t->size > INT_MAX / 2) ? INT_MAX : (t->size * 2);
+		if (t->size == INT_MAX || lh_table_resize(t, new_size) != 0)
 			return -1;
+	}
 
 	n = h % t->size;
 
