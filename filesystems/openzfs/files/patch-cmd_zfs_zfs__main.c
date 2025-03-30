--- cmd/zfs/zfs_main.c.orig	2025-03-30 00:09:17 UTC
+++ cmd/zfs/zfs_main.c
@@ -6845,7 +6845,11 @@ print_holds(boolean_t scripted, int nwidth, int tagwid
 
 			if (scripted) {
 				if (parsable) {
+#if defined(__FreeBSD__) && defined(__i386__)
+					(void) printf("%s\t%s\t%d\n", zname,
+#else
 					(void) printf("%s\t%s\t%ld\n", zname,
+#endif
 					    tagname, time);
 				} else {
 					(void) printf("%s\t%s\t%s\n", zname,
@@ -6853,7 +6857,11 @@ print_holds(boolean_t scripted, int nwidth, int tagwid
 				}
 			} else {
 				if (parsable) {
+#if defined(__FreeBSD__) && defined(__i386__)
+					(void) printf("%-*s  %-*s  %d\n",
+#else
 					(void) printf("%-*s  %-*s  %ld\n",
+#endif
 					    nwidth, zname, tagwidth,
 					    tagname, time);
 				} else {
