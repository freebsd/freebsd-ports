--- source/ChannelList.C.orig	Sat Nov 23 21:40:56 2002
+++ source/ChannelList.C	Sat Nov 23 21:41:04 2002
@@ -41,7 +41,7 @@
 }
 
 void
-ChannelList::addChannel(ServerConnection *cnx, String name, String wantedModes = "")
+ChannelList::addChannel(ServerConnection *cnx, String name, String wantedModes)
 {
   name = name.toLower();
   list[name] = new Channel(cnx, name, wantedModes);
