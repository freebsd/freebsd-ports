--- src/af/ev/gtk/ev_UnixKeyboard.cpp.orig	2021-07-03 15:46:07 UTC
+++ src/af/ev/gtk/ev_UnixKeyboard.cpp
@@ -130,7 +130,7 @@ bool ev_UnixKeyboard::keyPressEvent(AV_View* pView, Gd
 	  {
 	    // TODO: is this necessary?
 	    charData = gdk_keyval_to_unicode (charData);
-	    UT_UTF8String utf8 (static_cast<const UT_UCS4Char *>(&charData), 1);
+	    UT_UTF8String utf8 (reinterpret_cast<const UT_UCS4Char *>(&charData), 1);
 	    return charDataEvent (pView, state, utf8.utf8_str(), utf8.byteLength());
 	  }
 
