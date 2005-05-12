$FreeBSD$

--- ../../j2se/src/solaris/native/java/util/TimeZone_md.c	3 Jan 2005 18:32:01 -0000	1.3
+++ ../../j2se/src/solaris/native/java/util/TimeZone_md.c	19 Apr 2005 19:32:06 -0000
@@ -38,7 +38,7 @@
 #endif
 
 static const char *zoneinfo_dir = "/usr/share/zoneinfo";
-static const char *defailt_zoneinfo_file = "/etc/localtime";
+static const char *default_zoneinfo_file = "/etc/localtime";
 
 /*
  * Returns a point to the zone ID portion of the given zoneinfo file
@@ -181,6 +181,7 @@
     int fd;
     char *buf;
     size_t size;
+    char zoneinfo_file[PATH_MAX+1];
 
 #ifdef __linux__
     /*
@@ -242,11 +243,13 @@
     /*
      * Next, try /etc/localtime to find the zone ID.
      */
-    if (lstat(defailt_zoneinfo_file, &statbuf) == -1) {
+    if (lstat(default_zoneinfo_file, &statbuf) == -1) {
 	return NULL;
     }
 
-#ifdef __linux__
+    strlcpy(zoneinfo_file, default_zoneinfo_file, PATH_MAX+1);
+
+#if defined(__linux__) || defined(_ALLBSD_SOURCE)
     /*
      * If it's a symlink, get the link name and its zone ID part. (The
      * older versions of timeconfig created a symlink as described in
@@ -255,22 +258,25 @@
      * from /etc/localtime.)
      */
     if (S_ISLNK(statbuf.st_mode)) {
-	char linkbuf[PATH_MAX+1];
 	int len;
 
-	if ((len = readlink(defailt_zoneinfo_file, linkbuf, sizeof(linkbuf)-1)) == -1) {
+	if ((len = readlink(default_zoneinfo_file, zoneinfo_file, sizeof(zoneinfo_file)-1)) == -1) {
 	    jio_fprintf(stderr, (const char *) "can't get a symlink of %s\n",
-			defailt_zoneinfo_file);
+			default_zoneinfo_file);
 	    return NULL;
 	}
-	linkbuf[len] = '\0';
-	tz = getZoneName(linkbuf);
+	zoneinfo_file[len] = '\0';
+	tz = getZoneName(zoneinfo_file);
 	if (tz != NULL) {
 	    tz = strdup(tz);
+	    return tz;
+	} else {
+	    if (lstat(zoneinfo_file, &statbuf) == -1) {
+		return NULL;
+	    }
 	}
-	return tz;
     }
-#endif /* __linux__ */
+#endif /* __linux__ || _ALLBSD_SOURCE */
 
     /*
      * If it's a regular file, we need to find out the same zoneinfo file
@@ -281,7 +287,7 @@
     if (buf == NULL) {
 	return NULL;
     }
-    if ((fd = open(defailt_zoneinfo_file, O_RDONLY)) == -1) {
+    if ((fd = open(zoneinfo_file, O_RDONLY)) == -1) {
 	free((void *) buf);
 	return NULL;
     }
@@ -558,17 +564,16 @@
 	return strdup("GMT");
     }
 
-    /* Note that the time offset direction is opposite. */
 #if defined(_ALLBSD_SOURCE)
     clock = time(NULL);
     tzset();
     local_tm = localtime(&clock);
-    if (local_tm->tm_gmtoff > 0) {
+    if (local_tm->tm_gmtoff >= 0) {
 	offset = (time_t) local_tm->tm_gmtoff;
-	sign = "-";
+	sign = "+";
     } else {
 	offset = (time_t) -local_tm->tm_gmtoff;
-	sign = "+";
+	sign = "-";
     }
 #else
     if (timezone > 0) {
