--- uds/packetsocket.cc.orig	Wed May  9 15:24:10 2001
+++ uds/packetsocket.cc	Thu May 10 19:52:41 2001
@@ -22,6 +22,7 @@
 
 // includes
 
+#include <sys/types.h>
 #include <netinet/in.h>
 #include <sys/socket.h>
 #include <uds/packetsocket.hh>
@@ -163,7 +164,7 @@
 								  &si_len ) );
 	d.assign( msg, sz );
 
-	hostent* he = gethostbyaddr( &si.sin_addr, sizeof( si.sin_addr ), AF_INET );
+	hostent* he = gethostbyaddr( (const char *)&si.sin_addr, sizeof( si.sin_addr ), AF_INET );
 	clog<<he<<endl;
 	
 	if ( he )
