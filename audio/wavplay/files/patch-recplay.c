--- recplay.c.orig	1999-12-04 00:06:42 UTC
+++ recplay.c
@@ -52,12 +52,18 @@ static const char rcsid[] = "@(#)recplay
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
 
@@ -184,7 +190,7 @@ wavrecd(WavPlayOpts *wavopts,char *Pathn
 		wfile = svr.wfile;		/* And the file is already opened */
 	}
 
-	if ( (dfile = OpenDSP(wfile,O_RDWR,v_erf)) == NULL )
+	if ( (dfile = OpenDSP(wfile,O_RDONLY,v_erf)) == NULL )
 		goto errxit;
 
 	if ( RecordDSP(dfile,wfile,samples,svr_work_proc,v_erf) )
