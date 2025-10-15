--- src/efisecdb.c.orig	2024-01-31 20:08:46 UTC
+++ src/efisecdb.c
@@ -93,7 +93,7 @@ secdb_warnx(const char * const fmt, ...)
 	int errnum = errno;
 
 	fflush(stdout);
-	fprintf(stderr, "%s: ", program_invocation_short_name);
+	fprintf(stderr, "%s: ", getprogname());
 	va_start(ap, fmt);
 	vfprintf(stderr, fmt, ap);
 	va_end(ap);
@@ -109,7 +109,7 @@ secdb_err(int status, const char * const fmt, ...)
 	int errnum = errno;
 
 	fflush(stdout);
-	fprintf(stderr, "%s: ", program_invocation_short_name);
+	fprintf(stderr, "%s: ", getprogname());
 	va_start(ap, fmt);
 	vfprintf(stderr, fmt, ap);
 	va_end(ap);
@@ -126,7 +126,7 @@ secdb_errx(int status, const char * const fmt, ...)
 	int errnum = errno;
 
 	fflush(stdout);
-	fprintf(stderr, "%s: ", program_invocation_short_name);
+	fprintf(stderr, "%s: ", getprogname());
 	va_start(ap, fmt);
 	errno = errnum;
 	vfprintf(stderr, fmt, ap);
@@ -149,7 +149,7 @@ usage(int status)
 		"  -t, --type=<hash-type>    hash type to add (\"help\" lists options)\n"
 		"  -c, --certificate=<file>  certificate file to add\n"
 		"  -L, --list-guids          list well known guids\n",
-		program_invocation_short_name);
+		getprogname());
 	exit(status);
 }
 
