--- src/dbsd.c.orig	Sun Jun  7 19:23:26 1998
+++ src/dbsd.c	Sat Sep 18 17:19:36 1999
@@ -51,6 +51,9 @@
 
 #define DBSD
 
+#ifdef HAVE_SYS_PARAM_H
+#include <sys/param.h>
+#endif
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -80,7 +83,7 @@
 #include <sys/fcntl.h>
 #endif
 
-#if !defined(bsdi)
+#if (!defined(BSD) || (BSD < 199306))
 #include <malloc.h>
 #endif
 
@@ -1002,8 +1005,13 @@
 	    d[i].snd_max      = htonl((int)rt.d[i].td_cb.snd_max);
 	    d[i].snd_cwnd     = htonl((int)rt.d[i].td_cb.snd_cwnd);
 	    d[i].snd_ssthresh = htonl((int)rt.d[i].td_cb.snd_ssthresh);
+#if !defined(__FreeBSD_version) || (__FreeBSD_version < 400009)
 	    d[i].t_idle       = htonl((int)rt.d[i].td_cb.t_idle);
 	    d[i].t_rtt        = htonl((int)rt.d[i].td_cb.t_rtt);
+#else
+	    d[i].t_idle       = htonl((int)rt.d[i].td_cb.t_rcvtime);
+	    d[i].t_rtt        = htonl((int)rt.d[i].td_cb.t_rtttime);
+#endif
 	    d[i].t_rtseq      = htonl((int)rt.d[i].td_cb.t_rtseq);
 	    d[i].t_srtt       = htonl((int)rt.d[i].td_cb.t_srtt);
 	    d[i].t_rttvar     = htonl((int)rt.d[i].td_cb.t_rttvar);
