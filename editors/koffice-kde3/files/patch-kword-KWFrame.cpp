--- kword/KWFrame.cpp.orig	Thu Mar 23 20:59:46 2006
+++ kword/KWFrame.cpp	Sat Apr  8 13:25:08 2006
@@ -671,7 +671,8 @@
     // This attribute isn't part of the OASIS spec. Doesn't matter since it doesn't affect rendering
     // of existing documents, only editing (and only KWord has this kind of option until now).
     NewFrameBehavior defaultNfb = frameSet()->isHeaderOrFooter() ? Copy : NoFollowup;
-    if ( m_newFrameBehavior != defaultNfb ) {
+    NewFrameBehavior temp_newFrameBehavior = m_newFrameBehavior;
+    if ( temp_newFrameBehavior != defaultNfb ) {
         const char* value = "none";
         if ( m_newFrameBehavior == Reconnect )
             value = "followup";
