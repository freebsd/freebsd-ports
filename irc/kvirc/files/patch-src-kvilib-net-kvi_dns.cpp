--- src/kvilib/net/kvi_dns.cpp.orig	Mon Jan  5 21:54:02 2004
+++ src/kvilib/net/kvi_dns.cpp	Mon Jan  5 22:04:18 2004
@@ -39,6 +39,12 @@
 	#include <sys/types.h>
 	#include <sys/socket.h>
 	#include <netdb.h>
+	#if __FreeBSD__
+		#include <osreldate.h>
+		#if __FreeBSD_version >= 500037
+			#define	EAI_ADDRFAMILY	 1
+		#endif
+	#endif
 #endif
 
 
@@ -101,7 +107,9 @@
 #ifndef COMPILE_ON_WINDOWS
 		case EAI_ADDRFAMILY: return KviError_unsupportedAddressFamily; break;
 #endif
+#if __FreeBSD_version <= 500037
 		case EAI_NODATA:     return KviError_validNameButNoIpAddress; break;
+#endif
 		case EAI_FAIL:       return KviError_unrecoverableNameserverError; break;
 		case EAI_AGAIN:      return KviError_dnsTemporaneousFault; break;
 		// this should never happen
