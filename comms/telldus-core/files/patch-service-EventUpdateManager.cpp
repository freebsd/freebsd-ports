--- service/EventUpdateManager.cpp
+++ service/EventUpdateManager.cpp
@@ -33,6 +33,10 @@
 #include "service/ConnectionListener.h"
 #include "service/Log.h"
 
+#ifdef __FreeBSD__
+extern char **environ;
+#endif
+
 typedef std::list<TelldusCore::Socket *> SocketList;
 typedef std::list<std::string> StringList;
 
