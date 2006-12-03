--- lxsys.c.orig	Tue Nov  7 13:45:32 2006
+++ lxsys.c	Fri Nov 24 18:02:31 2006
@@ -1,12 +1,14 @@
-
-#include <sys/io.h>
+#include <sys/cdefs.h>
+#include <sys/types.h>
+#include <machine/cpufunc.h>
+#include <machine/sysarch.h>
 #include <unistd.h>
 #include <sys/mman.h>
+#include <sys/time.h>
 #include <sys/resource.h>
 #include <semaphore.h>
 #include <pthread.h>
 #include <sched.h>
-#include <sys/time.h>
 #include <fcntl.h>
 #include <termios.h>
 #include "thrdef.h"
@@ -17,6 +19,7 @@
 #include "lindef.h"
 #include "hwaredef.h"
 
+extern int saved_euid;
 
 void lirerr(int errcod)
 {
@@ -60,11 +63,9 @@
 // Get permission to write to the parallel port
 if(ui.parport < 0x400-4)
   {
-  i=ioperm(ui.parport,4,1);
-  }
-else
-  {
-  i=iopl(3);
+  seteuid(saved_euid);
+  i=i386_set_ioperm(ui.parport,4,1);
+  seteuid(getuid());
   }
 if(i != 0)
   {
@@ -208,11 +209,9 @@
 int i;
 if(ui.parport < 0x400-4)
   {
-  i=ioperm(ui.parport,4,1);
-  }
-else
-  {
-  i=iopl(3);
+  seteuid(saved_euid);
+  i=i386_set_ioperm(ui.parport,4,1);
+  seteuid(getuid());
   }
 if(i!=0)lirerr(764921);
 i=1000;
@@ -225,11 +224,9 @@
 int i;
 if(ui.parport < 0x400-4)
   {
-  i=ioperm(ui.parport,4,1);
-  }
-else
-  {
-  i=iopl(3);
+  seteuid(saved_euid);
+  i=i386_set_ioperm(ui.parport,4,1);
+  seteuid(getuid());
   }
 if(i!=0)lirerr(764921);
 return inb(port);
