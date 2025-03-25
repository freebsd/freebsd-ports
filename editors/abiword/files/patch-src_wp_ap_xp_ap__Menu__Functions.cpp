--- src/wp/ap/xp/ap_Menu_Functions.cpp.orig	2021-07-03 15:46:07 UTC
+++ src/wp/ap/xp/ap_Menu_Functions.cpp
@@ -744,7 +744,7 @@ Defun_EV_GetMenuItemComputedLabel_Fn(ap_GetLabel_Sugge
 	UT_UCSChar *p = pView->getContextSuggest(ndx);
 	gchar * c = NULL;
 	if (p && *p) {
-		c = g_ucs4_to_utf8(p, -1, NULL, NULL, NULL);
+		c = g_ucs4_to_utf8(reinterpret_cast<const gunichar *>(p), -1, NULL, NULL, NULL);
 	}
 	else if (ndx == 1)
 	{
