--- gsmlib/gsm_unix_serial.cc.orig	Sun Sep 22 20:51:10 2002
+++ gsmlib/gsm_unix_serial.cc	Wed Aug 18 01:27:08 2004
@@ -20,6 +20,7 @@
 #include <fcntl.h>
 #include <iostream>
 #include <strstream>
+#include <cassert>
 #include <errno.h>
 #include <stdio.h>
 #include <unistd.h>
@@ -178,11 +179,15 @@
 
   // switch off non-blocking mode
   int fdFlags;
-  if ((fdFlags = fcntl(_fd, F_GETFL)) == -1)
+  if ((fdFlags = fcntl(_fd, F_GETFL)) == -1) {
+    close(_fd);
     throwModemException(_("getting file status flags failed"));
+  }
   fdFlags &= ~O_NONBLOCK;
-  if (fcntl(_fd, F_SETFL, fdFlags) == -1)
+  if (fcntl(_fd, F_SETFL, fdFlags) == -1) {
+    close(_fd);
     throwModemException(_("switching of non-blocking mode failed"));
+  }
 
   long int saveTimeoutVal = _timeoutVal;
   _timeoutVal = 3;
@@ -194,17 +199,22 @@
 
     // toggle DTR to reset modem
     int mctl = TIOCM_DTR;
-    if (ioctl(_fd, TIOCMBIC, &mctl) < 0)
+    if (ioctl(_fd, TIOCMBIC, &mctl) < 0) {
+      close(_fd);
       throwModemException(_("clearing DTR failed"));
+    }
     // the waiting time for DTR toggling is increased with each loop
     usleep(holdoff[initTries]);
-    if (ioctl(_fd, TIOCMBIS, &mctl) < 0)
+    if (ioctl(_fd, TIOCMBIS, &mctl) < 0) {
+      close(_fd);
       throwModemException(_("setting DTR failed"));
-  
+    }
     // get line modes
-    if (tcgetattr(_fd, &t) < 0)
+    if (tcgetattr(_fd, &t) < 0) {
+      close(_fd);
       throwModemException(stringPrintf(_("tcgetattr device '%s'"),
                                        device.c_str()));
+    }
 
     // set line speed
     cfsetispeed(&t, lineSpeed);
@@ -229,9 +239,11 @@
     t.c_cc[VSUSP] = 0;
 
     // write back
-    if(tcsetattr (_fd, TCSANOW, &t) < 0)
+    if(tcsetattr (_fd, TCSANOW, &t) < 0) {
+      close(_fd);
       throwModemException(stringPrintf(_("tcsetattr device '%s'"),
                                        device.c_str()));
+    }
     // the waiting time for writing to the ME/TA is increased with each loop
     usleep(holdoff[initTries]);
 
@@ -279,11 +291,14 @@
     catch (GsmException &e)
     {
       _timeoutVal = saveTimeoutVal;
-      if (initTries == 0)
+      if (initTries == 0) {
+        close(_fd);
         throw e;
+      }
     }
   }
   // no response after 3 tries
+  close(_fd);
   throw GsmException(stringPrintf(_("reset modem failed '%s'"),
                                   device.c_str()), OtherError);
 }
