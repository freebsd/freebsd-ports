--- picport.cc.orig	Thu Apr 29 00:08:10 2004
+++ picport.cc	Fri Jul  8 21:46:07 2005
@@ -40,7 +40,7 @@
 #include <unistd.h>
 #include <termios.h>
 #include <sysexits.h>
-#include <string.h>
+#include <string>
 #include <sched.h>
 
 #include "picport.h"
@@ -54,6 +54,11 @@
 unsigned int picport::tsc_1000ns = 0;
 int picport::use_nanosleep = -1;
 
+// Extra delays for long cables, in us
+int picport::t_on = 0;
+int picport::t_off = 0;
+int picport::t_edge = 0;
+
 void
 picport::set_clock_data (int rts, int dtr)
 {
@@ -102,7 +107,7 @@
   // Before first call to set_clock_data, read the modem status.
   ioctl (fd, TIOCMGET, &modembits);
   set_clock_data (0, 0);
-  usleep (50);
+  usleep (50+t_edge);
   // Check the CTS.  If it is up, even when we just lowered DTR,
   // we probably are not talking to a JDM type programmer.
   int i;
@@ -200,13 +205,13 @@
     cerr << "Unable to start break on tty " << tty << ":" << strerror (e) << endl;
     exit (EX_IOERR);
   }
-  usleep (10);
+  usleep (10+t_off);
 }
 
 picport::~picport ()
 {
   ioctl (fd, TIOCCBRK, 0);
-  usleep (1);
+  usleep (1+t_off);
   tcsetattr (fd, TCSANOW, &saved);
   close (fd);
   delete [] portname;
@@ -216,15 +221,15 @@
 {
   set_clock_data (0, 0);
   ioctl (fd, TIOCCBRK, 0);
-  usleep (50);
+  usleep (50+t_off);
   ioctl (fd, TIOCSBRK, 0);
-  usleep (10);
+  usleep (10+t_on);
   addr = 0;
 }
 
 void picport::delay (long ns)
 {
-  if (1 == use_nanosleep) {
+  if (1 == use_nanosleep && !t_edge) {
     timespec ts = {ns / 1000000000, ns % 1000000000}, ts2;
     while (nanosleep (&ts, &ts2) && EINTR == errno)
       ts = ts2;
@@ -232,7 +237,7 @@
   }
 
 #ifdef RDTSC_WORKS
-  if (tsc_1000ns > 1) {
+  if (tsc_1000ns > 1 && !t_edge) {
     unsigned long a1, d1, a2, d2;
     asm volatile("rdtsc":"=a" (a1), "=d" (d1));
     d2 = d1;
@@ -259,10 +264,10 @@
   volatile int i;
   gettimeofday (&tv1, 0);
   tv2.tv_sec = tv1.tv_sec;
-  tv2.tv_usec = 0xffffffff & (tv1.tv_usec + 1 + (ns + 999)/1000);
+  tv2.tv_usec = 0xffffffff & (tv1.tv_usec + 1 + (ns + 999)/1000+t_edge);
   if (tv2.tv_usec < tv1.tv_usec)
     tv2.tv_sec++;
-  for (i = 0; i < 10000; i++) {
+  for (i = 0; i < 10000 || t_edge; i++) {
     gettimeofday (&tv1, 0);
     if (tv1.tv_sec > tv2.tv_sec
 	|| tv1.tv_sec == tv2.tv_sec && tv1.tv_usec >= tv2.tv_usec)
