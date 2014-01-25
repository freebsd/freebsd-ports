+++ libmpc8xx/lptbdm.c.orig	Sat Jun 24 12:47:47 2006
--- libmpc8xx/lptbdm.c	Sat Jun 24 12:50:21 2006
@@ -22,7 +22,7 @@
 #include <unistd.h>
 #include <sys/types.h>
 #include <string.h>
-#include <sys/io.h>
+#include <machine/sysarch.h>
 #include <time.h>
 
 static int lptbdm_read( void );
@@ -52,8 +52,9 @@
 
 static uid_t lptbdm_euid = -1;
 
-#define INB(x,port)	asm volatile("inb %1, %0" : "=a" (x) : "d" (port))
-#define OUTB(x,port)	asm volatile("outb %0, %1" : : "a" (x), "d" (port))
+#include <machine/cpufunc.h>
+#define INB(x,port)	x = inb(port)
+#define OUTB(x,port)	outb(port,x)
 
 /* in case of asm trouble (red hat 7.0?) try the code below and compile with -O option */
 /*#include <asm/io.h>
@@ -252,7 +253,7 @@
 		}
 	}
 
-	nResult = ioperm( lptbdm_port.DATAAddr, 3, 1 );
+	nResult = sysarch( I386_SET_IOPERM, (void *) ( lptbdm_port.DATAAddr, 3, 1 ) );
 
 	seteuid( getuid() );
 
