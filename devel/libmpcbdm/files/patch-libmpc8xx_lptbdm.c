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
@@ -252,7 +252,7 @@
 		}
 	}
 
-	nResult = ioperm( lptbdm_port.DATAAddr, 3, 1 );
+	nResult = i386_set_ioperm( lptbdm_port.DATAAddr, 3, 1 );
 
 	seteuid( getuid() );
 
