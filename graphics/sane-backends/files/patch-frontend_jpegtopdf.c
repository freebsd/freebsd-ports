--- frontend/jpegtopdf.c.orig	2022-01-19 16:38:00 UTC
+++ frontend/jpegtopdf.c
@@ -201,7 +201,11 @@ static SANE_Int _get_current_time( struct tm *pt, SANE
 		goto EXIT;
 	}
 	/* get time difference ( OHH'mm' ) */
+#ifdef __FreeBSD__
+	tz = -pt->tm_gmtoff;
+#else
 	tz = timezone;
+#endif
 	if ( tz > 0 ) {
 		*sign_c = '-';
 	}
