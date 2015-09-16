
$FreeBSD$

--- eglib/src/gfile-posix.c.orig
+++ eglib/src/gfile-posix.c
@@ -170,7 +170,7 @@
 	do {
 		buffer = g_realloc (buffer, s);
 		r = getcwd (buffer, s);
-		fail = (r == NULL && errno == ERANGE);
+		fail = (r == NULL && (errno == ERANGE || errno == 0));
 		if (fail) {
 			s <<= 1;
 		}
