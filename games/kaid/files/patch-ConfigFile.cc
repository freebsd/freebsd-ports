--- ConfigFile.cc	Sun Feb  6 16:43:31 2005
--- ConfigFile.cc	Wed Mar  2 08:58:22 2005
@@ -3,6 +3,9 @@
 #ifdef OPENWRT
 #include <utility>
 #else
+#ifdef PLATFORM_freebsd
+#include <sys/types.h>
+#endif
 #include <sys/socket.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>
@@ -44,6 +47,9 @@
 	
 	OrbPort = 34525;
 	UseIPv6 = false;
+#ifdef PLATFORM_freebsd
+	User = "";
+#endif
 	
 	UIBind = "";
 	UIIP = "";
@@ -175,6 +181,10 @@
 		{
 			XBoxHomebrew = ((val == "1") || (val == "on") || (val == "true") ||
 			(val == "yes") || (val == "yay") || (val == "foshizzle"));
+		}
+		else if (fld == "user")
+		{
+			User = m_vsValues[i];
 		}
 		else
 		{
