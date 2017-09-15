--- source/lobby/XmppClient.cpp.orig	2017-06-18 18:48:18 UTC
+++ source/lobby/XmppClient.cpp
@@ -25,10 +25,6 @@
 
 #include "i18n/L10n.h"
 
-#if OS_WIN
-#include "lib/sysdep/os/win/wposix/wtime.h"
-#endif
-
 #include "lib/external_libraries/enet.h"
 #include "lib/utf8.h"
 #include "network/NetServer.h"
@@ -948,14 +944,8 @@ std::time_t XmppClient::ComputeTimestamp(const glooxwr
 	if (!msg.when())
 		return std::time(nullptr);
 
-	glooxwrapper::string timestampStr = msg.when()->stamp();
-	struct tm timestamp = {0};
-
-	// See http://xmpp.org/extensions/xep-0082.html#sect-idp285136 for format
-	if (!strptime(timestampStr.c_str(), "%Y-%m-%dT%H:%M:%SZ", &timestamp))
-		LOGERROR("Received delayed message with corrupted timestamp %s", timestampStr.to_string());
-
-	return std::mktime(&timestamp) - timezone;
+	// See XEP-0082 for the date format
+	return g_L10n.ParseDateTime(msg.when()->stamp().to_string(), "Y-M-d'T'H:m:sZ", Locale::getUS()) / 1000.0;
 }
 
 /**
