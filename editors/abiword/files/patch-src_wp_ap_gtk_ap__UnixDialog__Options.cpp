--- src/wp/ap/gtk/ap_UnixDialog_Options.cpp.orig	2021-07-03 15:46:07 UTC
+++ src/wp/ap/gtk/ap_UnixDialog_Options.cpp
@@ -959,7 +959,7 @@ void AP_UnixDialog_Options::_setupSmartQuotesCombos(  
 		wszDisplayString[1] = (gunichar)'O';
 		wszDisplayString[2] = XAP_EncodingManager::smartQuoteStyles[i].rightQuote;
 		wszDisplayString[3] = (gunichar)0;
-        gchar* szDisplayStringUTF8 = g_ucs4_to_utf8 ( wszDisplayString, -1, NULL, NULL, NULL );
+        gchar* szDisplayStringUTF8 = g_ucs4_to_utf8 ( reinterpret_cast<const gunichar*>(wszDisplayString), -1, NULL, NULL, NULL );
 		XAP_appendComboBoxTextAndInt(combo, szDisplayStringUTF8, i);
         g_free ( szDisplayStringUTF8 );
 	}
