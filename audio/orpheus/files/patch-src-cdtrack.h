--- src/cdtrack.h	Sat Oct 18 14:51:26 2003
+++ src/cdtrack.h	Sun Dec 12 18:40:09 2004
@@ -5,7 +5,7 @@
 
 #include <string>
 
-#include <linux/cdrom.h>
+#include <sys/cdio.h>
 #include <sys/ioctl.h>
 #include <sys/types.h>
 #include <sys/stat.h>
@@ -15,7 +15,7 @@
 class cdtrack : public track {
     private:
 	int length, number;
-	struct cdrom_tocentry toc;
+	struct ioc_read_toc_single_entry toc;
 	string title;
 	bool paused;
 
