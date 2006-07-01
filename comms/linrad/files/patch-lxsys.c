--- lxsys.c.orig	Sat May 27 07:48:22 2006
+++ lxsys.c	Mon Jun 19 23:32:08 2006
@@ -1,5 +1,7 @@
-
-#include <sys/io.h>
+#include <sys/cdefs.h>
+#include <sys/types.h>
+#include <machine/cpufunc.h>
+#include <machine/sysarch.h>
 #include <unistd.h>
 #include <sys/mman.h>
 #include <sys/resource.h>
@@ -14,6 +16,7 @@
 #include "lindef.h"
 #include "hwaredef.h"
 
+extern int saved_euid;
 
 char *locktext[6]={"*W A R N I N G*  Read z_MLOCK.txt for info.",
                    "*** mlockall can cause system crashes!! ***",
@@ -40,11 +43,9 @@
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
@@ -189,11 +190,9 @@
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
@@ -206,11 +205,9 @@
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
