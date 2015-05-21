--- rip_music_unix.cpp.orig	2015-03-19 18:36:34 UTC
+++ rip_music_unix.cpp
@@ -39,7 +39,12 @@
 #include <unistd.h>
 #include <libgen.h>
 
-#include <mntent.h>
+#if defined(__linux__)
+#	include <mntent.h>
+#elif defined(__FreeBSD__)
+#	include <sys/param.h>
+#	include <sys/mount.h>
+#endif
 
 #include "rip_music.h"
 
@@ -140,6 +145,7 @@ static char * find_mnt_dir(const char * 
 
 static char * find_dev(const char * mnt_dir) {
 
+#if defined(__linux__)
 	struct mntent * mnt;
 	char * dev = NULL;
 	FILE * file;
@@ -167,6 +173,20 @@ static char * find_dev(const char * mnt_
 	endmntent(file);
 
 	return dev;
+#elif defined(__FreeBSD__)
+	struct statfs sfs;
+
+	if ( statfs(mnt_dir, &sfs) != 0 ) {
+
+		fprintf(stderr, "Error: Cannot get mounted device: %s\n", strerror(errno));
+		return NULL;
+
+	}
+
+	return strdup(sfs.f_mntfromname);
+#else
+	return NULL;
+#endif
 
 }
 
