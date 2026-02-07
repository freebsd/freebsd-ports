--- io.c.orig	2020-11-07 11:15:40 UTC
+++ io.c
@@ -119,8 +119,6 @@ cal_fopen(const char *file)
 	FILE *fp;
 	char *home = getenv("HOME");
 	unsigned int i;
-	struct stat sb;
-	static bool warned = false;
 
 	if (home == NULL || *home == '\0') {
 		warnx("Cannot get home directory");
@@ -145,10 +143,6 @@ cal_fopen(const char *file)
 	}
 
 	warnx("can't open calendar file \"%s\"", file);
-	if (!warned && stat(_PATH_INCLUDE_LOCAL, &sb) != 0) {
-		warnx("calendar data files now provided by calendar-data pkg.");
-		warned = true;
-	}
 
 	return (NULL);
 }
