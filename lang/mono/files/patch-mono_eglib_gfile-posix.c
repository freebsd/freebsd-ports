--- mono/eglib/gfile-posix.c.orig        2018-01-10 08:03:25 UTC
+++ mono/eglib/gfile-posix.c
@@ -161,7 +161,7 @@ g_get_current_dir (void)
 	do {
 		buffer = g_realloc (buffer, s);
 		r = getcwd (buffer, s);
-		fail = (r == NULL && errno == ERANGE);
+		fail = (r == NULL && (errno == ERANGE || errno == 0));
 		if (fail) {
 			s <<= 1;
 		}
