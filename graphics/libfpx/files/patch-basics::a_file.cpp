--- basics/a_file.cpp	Sat Dec 23 17:10:00 2000
+++ basics/a_file.cpp	Thu Jan 18 11:37:44 2001
@@ -29,4 +29,4 @@
 #  include <sys/types.h>
+#  include <sys/uio.h>
 #  include <sys/stat.h>
-#  include <sys/statfs.h>
 #  include <sys/ioctl.h>
--- basics/filename.cpp	Sat Dec 23 17:10:00 2000
+++ basics/filename.cpp	Thu Jan 18 11:33:35 2001
@@ -39,3 +39,4 @@
 #  include <sys/stat.h>
-#  include <sys/statfs.h>
+#  include <sys/param.h>
+#  include <sys/mount.h>
 #  include <stdio.h>
@@ -424,5 +425,4 @@
   struct statfs buf;
-  int errNum=0, fstyp;
+  int errNum=0;
   /* Get file system stats */
-  fstyp=0;
-  errNum = statfs ( ".", &buf, sizeof( struct statfs ), fstyp);
+  errNum = statfs ( ".", &buf);
