--- ./runkit.c.orig	2006-06-06 17:06:08.000000000 -0400
+++ ./runkit.c	2010-04-13 00:04:47.000000000 -0400
@@ -58,8 +58,8 @@
 	addr_len = spprintf(&addr, 0, "0x%0lx", (long)value);
 	add_assoc_stringl(return_value, "address", addr, addr_len, 0);
 
-	add_assoc_long(return_value, "refcount", value->refcount);
-	add_assoc_bool(return_value, "is_ref", value->is_ref);
+	add_assoc_long(return_value, "refcount", Z_REFCOUNT_P(value));
+	add_assoc_bool(return_value, "is_ref", Z_ISREF_P(value));
 	add_assoc_long(return_value, "type", value->type);
 }
 /* }}} */
