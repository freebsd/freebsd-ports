--- src/sdk/wxscintilla/src/ScintillaWX.cpp.orig	2016-01-23 16:43:01 UTC
+++ src/sdk/wxscintilla/src/ScintillaWX.cpp
@@ -290,7 +290,7 @@ static int wxCountLines(const char* text
 
 /* C::B begin */
 // Constant ids for the timers used by every editor.
-const int timerIDs[ScintillaWX::timersCount] = { wxNewId(), wxNewId(), wxNewId(), wxNewId() };
+const int timerIDs[ScintillaWX::timersCount] = { static_cast<int>(wxNewId()), static_cast<int>(wxNewId()), static_cast<int>(wxNewId()), static_cast<int>(wxNewId()) };
 /* C::B end */
 
 //----------------------------------------------------------------------
