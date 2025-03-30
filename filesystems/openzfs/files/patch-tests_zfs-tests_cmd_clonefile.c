--- tests/zfs-tests/cmd/clonefile.c.orig	2025-03-10 22:42:59 UTC
+++ tests/zfs-tests/cmd/clonefile.c
@@ -205,6 +205,7 @@ main(int argc, char **argv)
 
 	loff_t soff = 0, doff = 0;
 	size_t len = SSIZE_MAX;
+	unsigned long long len2;
 	if ((argc-optind) == 5) {
 		soff = strtoull(argv[optind+2], NULL, 10);
 		if (soff == ULLONG_MAX) {
@@ -220,8 +221,8 @@ main(int argc, char **argv)
 		    strcmp(argv[optind+4], "all") == 0) {
 			len = SSIZE_MAX;
 		} else {
-			len = strtoull(argv[optind+4], NULL, 10);
-			if (len == ULLONG_MAX) {
+			len2 = strtoull(argv[optind+4], NULL, 10);
+			if (len2 == ULLONG_MAX) {
 				fprintf(stderr, "invalid length");
 				return (1);
 			}
@@ -268,7 +269,7 @@ main(int argc, char **argv)
 		off_t dpos = lseek(dfd, 0, SEEK_CUR);
 		off_t dlen = lseek(dfd, 0, SEEK_END);
 
-		fprintf(stderr, "file offsets: src=%lu/%lu; dst=%lu/%lu\n",
+		fprintf(stderr, "file offsets: src=%jd/%jd; dst=%jd/%jd\n",
 		    spos, slen, dpos, dlen);
 	}
 
@@ -331,7 +332,7 @@ do_copyfilerange(int sfd, int dfd, loff_t soff, loff_t
 	}
 	if (copied != len) {
 		fprintf(stderr, "copy_file_range: copied less than requested: "
-		    "requested=%lu; copied=%lu\n", len, copied);
+		    "requested=%zu; copied=%zd\n", len, copied);
 		return (1);
 	}
 	return (0);
