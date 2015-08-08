--- include/isl/ctx.h.orig	2015-08-07 18:18:01 UTC
+++ include/isl/ctx.h
@@ -80,7 +80,7 @@ enum isl_error {
 };
 typedef enum {
 	isl_stat_error = -1,
-	isl_stat_ok = 0,
+	isl_stat_ok = 0
 } isl_stat;
 typedef enum {
 	isl_bool_error = -1,
