--- io.c.orig	2020-10-18 03:01:26 UTC
+++ io.c
@@ -42,7 +42,7 @@ static char sccsid[] = "@(#)calendar.c  8.3 (Berkeley)
 #endif
 
 #include <sys/cdefs.h>
-__FBSDID("$FreeBSD$");
+__FBSDID("$FreeBSD: head/usr.bin/calendar/io.c 366962 2020-10-23 09:22:23Z se $");
 
 #include <sys/param.h>
 #include <sys/stat.h>
@@ -71,7 +71,7 @@ enum {
 };
 
 const char *calendarFile = "calendar";	/* default calendar file */
-static const char *calendarHomes[] = {".calendar", _PATH_INCLUDE}; /* HOME */
+static const char *calendarHomes[] = {".calendar", _PATH_INCLUDE_LOCAL, _PATH_INCLUDE}; /* HOME */
 static const char *calendarNoMail = "nomail";/* don't sent mail if file exist */
 
 static char path[MAXPATHLEN];
