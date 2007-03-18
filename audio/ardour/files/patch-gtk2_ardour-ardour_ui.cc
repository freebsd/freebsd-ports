--- gtk2_ardour/ardour_ui.cc.orig	Sat Mar 17 02:55:45 2007
+++ gtk2_ardour/ardour_ui.cc	Sun Mar 18 14:44:03 2007
@@ -28,6 +28,8 @@
 #include <iostream>
 
 #include <sys/resource.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 
 #include <gtkmm/messagedialog.h>
 #include <gtkmm/accelmap.h>
@@ -456,8 +458,11 @@
 		struct rlimit limits;
 		int64_t ram;
 		long pages, page_size;
+		size_t pages_len=sizeof(pages);
+
+		if ((page_size = getpagesize()) < 0 ||
+			sysctlbyname("hw.availpages", &pages, &pages_len, NULL, 0)) {
 
-		if ((page_size = sysconf (_SC_PAGESIZE)) < 0 ||(pages = sysconf (_SC_PHYS_PAGES)) < 0) {
 			ram = 0;
 		} else {
 			ram = (int64_t) pages * (int64_t) page_size;
@@ -476,7 +481,7 @@
 						     "This might cause Ardour to run out of memory before your system "
 						     "runs out of memory. \n\n"
 						     "You can view the memory limit with 'ulimit -l', "
-						     "and it is normally controlled by /etc/security/limits.conf"));
+						     "and it is normally controlled by /etc/login.conf"));
 				
 				VBox* vbox = msg.get_vbox();
 				HBox hbox;
