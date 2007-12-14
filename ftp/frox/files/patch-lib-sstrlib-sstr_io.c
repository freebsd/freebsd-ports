--- lib/sstrlib/sstr_io.c.orig	2005-02-04 13:24:55.000000000 +0300
+++ lib/sstrlib/sstr_io.c	2007-12-14 18:07:15.000000000 +0300
@@ -26,6 +26,7 @@
 #include <sys/ioctl.h>
 #include <unistd.h>
 #include <ctype.h>
+#include <sys/stat.h>
 
 #include "sstr.h"
 #include "sstr_private.h"
@@ -61,8 +62,14 @@
 int sstr_append_read(int fd, sstr * p, int cnt)
 {
 	int i;
-	if(ioctl(fd, FIONREAD, &i) == -1)
-		return (-1);
+	struct stat mystat;
+
+	if(ioctl(fd, FIONREAD, &i) == -1) {
+		fstat(fd,&mystat);
+		if (mystat.st_mode & S_IFREG == 0)
+			return (-1);
+		i=mystat.st_blksize;
+	}
 	if(i == 0)
 		return (0);
 
