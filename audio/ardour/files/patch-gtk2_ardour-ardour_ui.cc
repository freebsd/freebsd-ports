--- gtk2_ardour/ardour_ui.cc.orig
+++ gtk2_ardour/ardour_ui.cc
@@ -31,6 +31,8 @@
 #include <iostream>
 
 #include <sys/resource.h>
+#include <sys/types.h>
+#include <sys/sysctl.h>
 
 #include <gtkmm/messagedialog.h>
 #include <gtkmm/accelmap.h>
@@ -696,8 +698,11 @@ ARDOUR_UI::check_memory_locking ()
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
@@ -716,7 +721,7 @@ ARDOUR_UI::check_memory_locking ()
 								     "This might cause %1 to run out of memory before your system "
 								     "runs out of memory. \n\n"
 								     "You can view the memory limit with 'ulimit -l', "
-								     "and it is normally controlled by /etc/security/limits.conf"), PROGRAM_NAME));
+								     "and it is normally controlled by /etc/login.conf"), PROGRAM_NAME));
 						   
 				VBox* vbox = msg.get_vbox();
 				HBox hbox;
@@ -1964,7 +1969,7 @@ ARDOUR_UI::name_io_setup (AudioEngine& engine, 
 
 		const char **connections = io.input(0)->get_connections();
 		
-		if (connections == 0 || connections[0] == '\0') {
+		if (connections == 0 || *connections[0] == '\0') {
 			buf = _("off");
 		} else {
 			buf = connections[0];
@@ -1983,7 +1988,7 @@ ARDOUR_UI::name_io_setup (AudioEngine& engine, 
 
 		const char **connections = io.output(0)->get_connections();
 		
-		if (connections == 0 || connections[0] == '\0') {
+		if (connections == 0 || *connections[0] == '\0') {
 			buf = _("off");
 		} else {
 			buf = connections[0];
