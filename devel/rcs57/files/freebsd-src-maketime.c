--- src/maketime.c
+++ freebsd/gnu/usr.bin/rcs/lib/maketime.c	1999-08-28 03:37:10.000000000 +0400
@@ -335,7 +335,7 @@ main(argc, argv) int argc; char **argv;
 	time_t default_time = time((time_t *)0);
 	long default_zone = argv[1] ? atol(argv[1]) : 0;
 	char buf[1000];
-	while (gets(buf)) {
+	while (fgets(buf, 1000, stdin)) {
 		time_t t = str2time(buf, default_time, default_zone);
 		printf("%s", asctime(gmtime(&t)));
 	}
