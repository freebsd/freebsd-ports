--- picport.cc.orig	Tue Nov 19 12:32:20 2002
+++ picport.cc	Tue Nov 19 12:33:13 2002
@@ -28,7 +28,7 @@
 
 */
 
-#include <iostream.h>
+#include <iostream>
 #include <sys/ioctl.h>
 #include <fcntl.h>
 #include <errno.h>
@@ -47,7 +47,7 @@
 {
   if (0 > (fd = open (tty, O_RDWR))) {
     int e = errno;
-    cerr << "Unable to open tty " << tty << ":" << strerror (e) << "\n";
+    std::cerr << "Unable to open tty " << tty << ":" << strerror (e) << "\n";
     exit (EX_IOERR);
   }
   tcgetattr (fd, &saved);
@@ -67,7 +67,7 @@
       || 0 > ioctl (fd, TIOCMBIC, &picport::dtr_bit)) {
     int e = errno;
     tcsetattr (fd, TCSANOW, &saved);
-    cerr << "Unable to clear RTS/DTR on tty " << tty << ":" << strerror (e) << "\n";
+    std::cerr << "Unable to clear RTS/DTR on tty " << tty << ":" << strerror (e) << "\n";
     exit (EX_IOERR);
   }
   usleep (50000);
@@ -75,7 +75,7 @@
     int e = errno;
     ioctl (fd, TIOCCBRK, 0);
     tcsetattr (fd, TCSANOW, &saved);
-    cerr << "Unable to start break on tty " << tty << ":" << strerror (e) << "\n";
+    std::cerr << "Unable to start break on tty " << tty << ":" << strerror (e) << "\n";
     exit (EX_IOERR);
   }
   usleep (1);
@@ -182,7 +182,7 @@
 
 // -1 == error, no programmer present
 
-int picport::command (enum commands comm, int data = 0)
+int picport::command (enum commands comm, int data)
 {
   int tmp1, tmp2;
 
@@ -216,11 +216,11 @@
     // This detects if the programmer is not connected to the port.
 
     if (!tmp1 || !tmp2) {
-      cerr << portname << ":PIC programmer or chip fault\n";
+      std::cerr << portname << ":PIC programmer or chip fault\n";
       return -1;
     }
     if (data_from_data == comm && (shift & 0x3f00) != 0x3f00) {
-      cerr << portname
+      std::cerr << portname
 	   << ":PIC programmer or chip fault\n"
 	"Is code protection enabled?  "
 	"Use --erase option to disable code protection.\n";
