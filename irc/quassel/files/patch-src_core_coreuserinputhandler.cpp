Fix CVE-2015-8547
--- src/core/coreuserinputhandler.cpp.orig	2015-04-23 20:47:17 UTC
+++ src/core/coreuserinputhandler.cpp
@@ -228,7 +228,7 @@ void CoreUserInputHandler::doMode(const 
     if (!isNumber || maxModes == 0) maxModes = 1;
 
     QStringList nickList;
-    if (nicks == "*") { // All users in channel
+    if (nicks == "*" && bufferInfo.type() == BufferInfo::ChannelBuffer) { // All users in channel
         const QList<IrcUser*> users = network()->ircChannel(bufferInfo.bufferName())->ircUsers();
         foreach(IrcUser *user, users) {
             if ((addOrRemove == '+' && !network()->ircChannel(bufferInfo.bufferName())->userModes(user).contains(mode))
