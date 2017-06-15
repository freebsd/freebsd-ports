--- src/lhlist.c.orig	2000-10-04 14:57:38 UTC
+++ src/lhlist.c
@@ -28,9 +28,9 @@ print_size(packed_size, original_size)
 	long            packed_size, original_size;
 {
 	if (verbose_listing)
-		printf("%7d ", packed_size);
+		printf("%7ld ", packed_size);
 
-	printf("%7d ", original_size);
+	printf("%7ld ", original_size);
 
 	if (original_size == 0L)
 		printf("******");
@@ -236,25 +236,28 @@ list_one(hdr)
 
 	print_size(hdr->packed_size, hdr->original_size);
 
-	if (verbose_listing)
+	if (verbose_listing) {
 		if (hdr->has_crc)
 			printf(" %s %04x", method, hdr->crc);
 		else
 			printf(" %s ****", method);
+	}
 
 	printf(" ");
 	print_stamp(hdr->unix_last_modified_stamp);
 
-	if (!verbose)
+	if (!verbose) {
 		if ((mode & UNIX_FILE_SYMLINK) != UNIX_FILE_SYMLINK)
 			printf(" %s", hdr->name);
 		else {
 			char            buf[256], *b1, *b2;
-			strcpy(buf, hdr->name);
+			strncpy(buf, hdr->name, sizeof(buf));
+			buf[sizeof(buf)-1] = 0;
 			b1 = strtok(buf, "|");
 			b2 = strtok(NULL, "|");
 			printf(" %s -> %s", b1, b2);
 		}
+	}
 
 	if (verbose)
 		printf(" [%d]", hdr->header_level);
