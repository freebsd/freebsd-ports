--- src/time.c.orig	2024-01-31 20:08:46 UTC
+++ src/time.c
@@ -52,7 +52,17 @@ tm_to_efi_time(const struct tm * const s, efi_time_t *
 
 	if (tzadj) {
 		tzset();
+
+#if defined(__FreeBSD__)
+		time_t t = time(NULL);
+		struct tm lt = {0};
+
+		localtime_r(&t, &lt);
+
+		d->timezone = lt.tm_gmtoff / 60;
+#else
 		d->timezone = timezone / 60;
+#endif
 	}
 
 	return 0;
