--- src/wp/ap/xp/ap_Menu_Functions.cpp.orig	Wed Jun  2 12:47:46 2004
+++ src/wp/ap/xp/ap_Menu_Functions.cpp	Wed Jun  2 12:47:49 2004
@@ -62,92 +62,94 @@
 	const char * c = NULL;
 
 	const XAP_StringSet * pss = pApp->getStringSet();
-	c = pss->getValueUTF8(AP_STRING_ID_DLG_Spell_NoSuggestions).utf8_str();
+	static UT_UTF8String s;
 
 	switch (id)
 	  {
 	  case AP_MENU_ID_AUTOTEXT_ATTN_1:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_ATTN_1).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_ATTN_1); break;
 	  case AP_MENU_ID_AUTOTEXT_ATTN_2:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_ATTN_2).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_ATTN_2); break;
 
 	  case AP_MENU_ID_AUTOTEXT_CLOSING_1:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_1).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_1); break;
 	  case AP_MENU_ID_AUTOTEXT_CLOSING_2:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_2).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_2); break;
 	  case AP_MENU_ID_AUTOTEXT_CLOSING_3:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_3).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_3); break;
 	  case AP_MENU_ID_AUTOTEXT_CLOSING_4:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_4).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_4); break;
 	  case AP_MENU_ID_AUTOTEXT_CLOSING_5:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_5).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_5); break;
 	  case AP_MENU_ID_AUTOTEXT_CLOSING_6:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_6).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_6); break;
 	  case AP_MENU_ID_AUTOTEXT_CLOSING_7:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_7).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_7); break;
 	  case AP_MENU_ID_AUTOTEXT_CLOSING_8:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_8).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_8); break;
 	  case AP_MENU_ID_AUTOTEXT_CLOSING_9:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_9).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_9); break;
 	  case AP_MENU_ID_AUTOTEXT_CLOSING_10:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_10).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_10); break;
 	  case AP_MENU_ID_AUTOTEXT_CLOSING_11:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_11).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_11); break;
 	  case AP_MENU_ID_AUTOTEXT_CLOSING_12:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_12).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_CLOSING_12); break;
 
 	  case AP_MENU_ID_AUTOTEXT_MAIL_1:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_1).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_1); break;
 	  case AP_MENU_ID_AUTOTEXT_MAIL_2:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_2).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_2); break;
 	  case AP_MENU_ID_AUTOTEXT_MAIL_3:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_3).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_3); break;
 	  case AP_MENU_ID_AUTOTEXT_MAIL_4:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_4).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_4); break;
 	  case AP_MENU_ID_AUTOTEXT_MAIL_5:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_5).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_5); break;
 	  case AP_MENU_ID_AUTOTEXT_MAIL_6:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_6).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_6); break;
 	  case AP_MENU_ID_AUTOTEXT_MAIL_7:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_7).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_7); break;
 	  case AP_MENU_ID_AUTOTEXT_MAIL_8:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_8).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_MAIL_8); break;
 
 	  case AP_MENU_ID_AUTOTEXT_REFERENCE_1:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_REFERENCE_1).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_REFERENCE_1); break;
 	  case AP_MENU_ID_AUTOTEXT_REFERENCE_2:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_REFERENCE_2).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_REFERENCE_2); break;
 	  case AP_MENU_ID_AUTOTEXT_REFERENCE_3:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_REFERENCE_3).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_REFERENCE_3); break;
 
 	  case AP_MENU_ID_AUTOTEXT_SALUTATION_1:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_SALUTATION_1).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_SALUTATION_1); break;
 	  case AP_MENU_ID_AUTOTEXT_SALUTATION_2:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_SALUTATION_2).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_SALUTATION_2); break;
 	  case AP_MENU_ID_AUTOTEXT_SALUTATION_3:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_SALUTATION_3).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_SALUTATION_3); break;
 	  case AP_MENU_ID_AUTOTEXT_SALUTATION_4:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_SALUTATION_4).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_SALUTATION_4); break;
 
 	  case AP_MENU_ID_AUTOTEXT_SUBJECT_1:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_SUBJECT_1).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_SUBJECT_1); break;
 
 	  case AP_MENU_ID_AUTOTEXT_EMAIL_1:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_EMAIL_1).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_EMAIL_1); break;
 	  case AP_MENU_ID_AUTOTEXT_EMAIL_2:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_EMAIL_2).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_EMAIL_2); break;
 	  case AP_MENU_ID_AUTOTEXT_EMAIL_3:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_EMAIL_3).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_EMAIL_3); break;
 	  case AP_MENU_ID_AUTOTEXT_EMAIL_4:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_EMAIL_4).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_EMAIL_4); break;
 	  case AP_MENU_ID_AUTOTEXT_EMAIL_5:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_EMAIL_5).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_EMAIL_5); break;
 	  case AP_MENU_ID_AUTOTEXT_EMAIL_6:
-	    c = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_EMAIL_6).utf8_str(); break;
+	    s = pss->getValueUTF8(AP_STRING_ID_AUTOTEXT_EMAIL_6); break;
 
 	  default:
-	    c = "No clue"; break;
+	    s = pss->getValueUTF8(AP_STRING_ID_DLG_Spell_NoSuggestions); break;
 	  }
+
+	c = s.utf8_str();
 
 	return c;
 }
