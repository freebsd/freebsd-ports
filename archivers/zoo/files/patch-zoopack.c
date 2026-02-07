--- zoopack.c.orig	1993-05-01 03:59:21 UTC
+++ zoopack.c
@@ -139,7 +139,11 @@ if (zoo_file == NOFILE)
 /* Read the header of the old archive. */
 frd_zooh(&old_zoo_header, zoo_file);
 
+#ifdef __LP64__
+if ((int)(old_zoo_header.zoo_start + old_zoo_header.zoo_minus) != 0) {
+#else
 if ((old_zoo_header.zoo_start + old_zoo_header.zoo_minus) != 0L) {
+#endif
    prterror ('w', failed_consistency);
    ++bad_header;                    /* remember for future error message */
 }
