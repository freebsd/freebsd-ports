--- PktSnifferThread.cc	Wed Feb  9 13:29:04 2005
--- PktSnifferThread.cc	Sun Feb 27 06:17:28 2005
@@ -2,6 +2,12 @@
 #include <iostream>
 
 #include <unistd.h>
+#ifdef PLATFORM_freebsd
+#include <sys/time.h>
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <net/bpf.h>
+#endif
 #include "libpcap/pcap.h"
 #include "libpcap/pcap-bpf.h"
 #include "PktSnifferThread.h"
@@ -111,6 +117,14 @@
 		
 		if(!m_ptHandle)
 			throw errInvalidDevice;
+
+#ifdef PLATFORM_freebsd
+		int one = 1;
+		if(ioctl(pcap_fileno(m_ptHandle), BIOCSHDRCMPLT, &one) == -1) {
+			pcap_close(m_ptHandle);
+			throw errFatalError;
+		}
+#endif
 		
 		#ifdef PLATFORM_macosx_jaguar
 		injectFD = openRawSocket(&mySocket);
