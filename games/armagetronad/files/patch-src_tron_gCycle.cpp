This is a fix for a bug in how std::autoptr is handled.
clang complains:
gCycle.cpp:*:*: warning: reference cannot be bound to dereferenced null pointer in well-defined C++ code; pointer may be assumed to always convert to true
      [-Wundefined-bool-conversion]

--- src/tron/gCycle.cpp.orig	2011-09-11 10:41:47 UTC
+++ src/tron/gCycle.cpp
@@ -2712,7 +2712,7 @@ bool gCycle::Timestep(REAL currentTime){
             gCycleChatBot & bot = gCycleChatBot::Get( this );
             bot.Activate( currentTime );
         }
-        else if ( &(*chatBot_) )
+        else if ( chatBot_.get() )
         {
             chatBot_->nextChatAI_ = 0;
         }
