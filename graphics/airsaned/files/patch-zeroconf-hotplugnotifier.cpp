--- zeroconf/hotplugnotifier.cpp.orig	2021-10-05 12:35:03 UTC
+++ zeroconf/hotplugnotifier.cpp
@@ -20,7 +20,11 @@ along with this program.  If not, see <http://www.gnu.
 
 #include <atomic>
 #include <csignal>
+#ifdef __FreeBSD__
+#include <libusb.h>
+#else
 #include <libusb-1.0/libusb.h>
+#endif
 #include <pthread.h>
 #include <thread>
 
