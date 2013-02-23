--- liblangtag/lt-ext-module.c	2012-11-06 09:15:59.000000000 -0600
+++ liblangtag/lt-ext-module.c	2012-11-06 09:30:31.000000000 -0600
@@ -399,7 +399,8 @@
 
 			if (len > suffix_len &&
 			    lt_strcmp0(&filename[prefix_len + len - suffix_len], "." LT_MODULE_SUFFIX) == 0) {
-				module = strndup(&filename[prefix_len], len - suffix_len);
+				module = malloc((len-suffix_len) + 1);
+				strncpy(module, &filename[prefix_len], len-suffix_len);
 				module[len - suffix_len] = 0;
 			}
 		}
