--- source/lobby/XmppClient.cpp.orig	2017-07-28 19:57:26 UTC
+++ source/lobby/XmppClient.cpp
@@ -955,7 +955,7 @@ std::time_t XmppClient::ComputeTimestamp(const glooxwr
 	if (!strptime(timestampStr.c_str(), "%Y-%m-%dT%H:%M:%SZ", &timestamp))
 		LOGERROR("Received delayed message with corrupted timestamp %s", timestampStr.to_string());
 
-	return std::mktime(&timestamp) - timezone;
+	return std::mktime(&timestamp);
 }
 
 /**
