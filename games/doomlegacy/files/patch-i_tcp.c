--- i_tcp.c.orig	Fri Jan 17 17:26:18 2003
+++ i_tcp.c	Fri Jan 17 17:27:09 2003
@@ -219,6 +219,10 @@
 #include "doomstat.h"
 #include "mserv.h" //Hurdler: support master server
 
+// somewhere on the track between 4.5 and -current this one has disappered.
+#ifndef IPPORT_USERRESERVED
+    #define IPPORT_USERRESERVED 5000
+#endif
 #ifdef __WIN32__
     // some undifined under win32
     #define IPPORT_USERRESERVED 5000
