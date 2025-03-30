--- tests/zfs-tests/tests/functional/vdev_disk/page_alignment.c.orig	2025-03-30 00:02:54 UTC
+++ tests/zfs-tests/tests/functional/vdev_disk/page_alignment.c
@@ -420,14 +420,14 @@ run_test(const page_test_t *test, bool verbose)
 		size_t take = MIN(rem, len);
 
 		if (verbose)
-			printf("  page %d [off %lx len %lx], "
-			    "rem %lx, take %lx\n",
+			printf("  page %d [off %zx len %zx], "
+			    "rem %zx, take %zx\n",
 			    i, off, len, rem, take);
 
 		if (vdev_disk_check_alignment_cb(NULL, off, take, &s)) {
 			if (verbose)
 				printf("  ABORT: misalignment detected, "
-				    "rem %lx\n", rem);
+				    "rem %zx\n", rem);
 			return (false);
 		}
 
@@ -438,7 +438,7 @@ run_test(const page_test_t *test, bool verbose)
 
 	if (rem > 0) {
 		if (verbose)
-			printf("  ABORT: ran out of pages, rem %lx\n", rem);
+			printf("  ABORT: ran out of pages, rem %zx\n", rem);
 		return (false);
 	}
 
