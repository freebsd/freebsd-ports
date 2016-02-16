--- src/pfs/pfs.cpp.orig	2010-07-14 09:44:27 UTC
+++ src/pfs/pfs.cpp
@@ -71,7 +71,7 @@ const char *PFSFILEID="PFS1\x0a";
 // TagContainer implementation  
 //------------------------------------------------------------------------------
 
-typedef list<string> TagList;
+typedef std::list<string> TagList;
 
 class TagIteratorImpl: public TagIterator
 {
@@ -570,7 +570,7 @@ public:
 
     //Read channel IDs and tags
     //       FrameImpl::ChannelID *channelID = new FrameImpl::ChannelID[channelCount];
-    list<ChannelImpl*> orderedChannel;
+    std::list<ChannelImpl*> orderedChannel;
     for( int i = 0; i < channelCount; i++ ) {
       char channelName[MAX_CHANNEL_NAME+1], *rs;
       rs = fgets( channelName, MAX_CHANNEL_NAME, inputStream );
@@ -592,7 +592,7 @@ public:
     
 
     //Read channels
-    list<ChannelImpl*>::iterator it;
+    std::list<ChannelImpl*>::iterator it;
     for( it = orderedChannel.begin(); it != orderedChannel.end(); it++ ) {
       ChannelImpl *ch = *it;
       int size = frame->getWidth()*frame->getHeight();
