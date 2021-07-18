Unbreak on FreeBSD after https://git.sr.ht/~kennylevinsen/wlsunset/commit/111181106e41
See also https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=24590

main.c:710:47: error: use of undeclared identifier 'timezone'
        *time = tm.tm_hour * 3600 + tm.tm_min * 60 + timezone;

--- main.c.orig	2021-04-25 20:56:30 UTC
+++ main.c
@@ -707,7 +707,7 @@ static int parse_time_of_day(const char *s, time_t *ti
 	if (strptime(s, "%H:%M", &tm) == NULL) {
 		return -1;
 	}
-	*time = tm.tm_hour * 3600 + tm.tm_min * 60 + timezone;
+	*time = tm.tm_hour * 3600 + tm.tm_min * 60 + tm.tm_gmtoff;
 	return 0;
 }
 
