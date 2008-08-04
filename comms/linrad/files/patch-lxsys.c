--- lxsys.c.orig	2008-07-29 12:39:53.000000000 -0400
+++ lxsys.c	2008-08-04 11:46:11.000000000 -0400
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
@@ -18,7 +20,8 @@
 #include "hwaredef.h"
 
 struct termios old_options;
-char serport_name[]="/dev/ttyS?";
+char serport_name[]="/dev/ttyd?";
+extern int saved_euid;
 
 void perseus_input(void){};
 
@@ -220,15 +223,13 @@
 
 int lir_parport_permission(void)
 {
-int i;
+int i=0;
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
@@ -385,11 +386,9 @@
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
@@ -402,11 +401,9 @@
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
