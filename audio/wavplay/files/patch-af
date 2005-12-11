--- recplay.c.orig	Sat Dec  4 09:06:42 1999
+++ recplay.c	Sun Dec 11 12:56:34 2005
@@ -52,12 +52,18 @@
 #include <stdio.h>
 #include <stdarg.h>
 #include <stdlib.h>
+#ifndef FREEBSD
 #include <malloc.h>
+#endif
 #include <string.h>
 #include <fcntl.h>
 #include <errno.h>
 #include <sys/stat.h>
+#ifndef FREEBSD
 #include <linux/soundcard.h>
+#else
+#include <sys/soundcard.h>
+#endif
 #include "wavplay.h"
 #include "server.h"
 
@@ -184,7 +190,7 @@
 		wfile = svr.wfile;		/* And the file is already opened */
 	}
 
-	if ( (dfile = OpenDSP(wfile,O_RDWR,v_erf)) == NULL )
+	if ( (dfile = OpenDSP(wfile,O_RDONLY,v_erf)) == NULL )
 		goto errxit;
 
 	if ( RecordDSP(dfile,wfile,samples,svr_work_proc,v_erf) )
