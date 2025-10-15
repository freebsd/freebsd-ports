--- src/efivar.c.orig	2024-01-31 20:08:46 UTC
+++ src/efivar.c
@@ -20,6 +20,10 @@
 #include <string.h>
 #include <limits.h>
 
+#if defined(__FreeBSD__)
+#  undef LIST_HEAD
+#endif
+
 extern char *optarg;
 extern int optind, opterr, optopt;
 
@@ -408,7 +412,7 @@ prepare_data(const char *filename, uint8_t **data, siz
 		goto err;
 
 	buflen = statbuf.st_size;
-	buf = mmap(NULL, buflen, PROT_READ, MAP_PRIVATE|MAP_POPULATE, fd, 0);
+	buf = mmap(NULL, buflen, PROT_READ, MAP_PRIVATE, fd, 0);
 	if (buf == MAP_FAILED)
 		goto err;
 
@@ -447,7 +451,7 @@ usage(int ret)
 		"Help options:\n"
 		"  -?, --help                        Show this help message\n"
 		"      --usage                       Display brief usage message\n",
-		program_invocation_short_name);
+		getprogname());
 	exit(ret);
 }
 
