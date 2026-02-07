--- cmd/zfs/zfs_main.c.orig	2025-12-18 17:41:34 UTC
+++ cmd/zfs/zfs_main.c
@@ -6884,17 +6884,28 @@ print_holds(boolean_t scripted, int nwidth, int tagwid
 
 			if (scripted) {
 				if (parsable) {
+#if defined(__FreeBSD__) && defined(__i386__)
+					(void) printf("%s\t%s\t%d\n", zname,
+					    tagname, time);
+#else
 					(void) printf("%s\t%s\t%lld\n", zname,
 					    tagname, (long long)time);
+#endif
 				} else {
 					(void) printf("%s\t%s\t%s\n", zname,
 					    tagname, tsbuf);
 				}
 			} else {
 				if (parsable) {
+#if defined(__FreeBSD__) && defined(__i386__)
+					(void) printf("%-*s  %-*s  %d\n",
+					    nwidth, zname, tagwidth,
+					    tagname, time);
+#else
 					(void) printf("%-*s  %-*s  %lld\n",
 					    nwidth, zname, tagwidth,
 					    tagname, (long long)time);
+#endif
 				} else {
 					(void) printf("%-*s  %-*s  %s\n",
 					    nwidth, zname, tagwidth,
