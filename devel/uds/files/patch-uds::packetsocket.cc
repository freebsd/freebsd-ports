--- uds/packetsocket.cc.orig	Thu Sep  5 02:36:31 2002
+++ uds/packetsocket.cc	Thu Sep  5 02:37:03 2002
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
 	
 	if ( he )
 	{
