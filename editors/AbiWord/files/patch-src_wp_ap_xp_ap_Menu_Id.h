--- src/wp/ap/xp/ap_Menu_Id.h.orig	Tue Aug 19 12:24:28 2003
+++ src/wp/ap/xp/ap_Menu_Id.h	Tue Aug 19 12:26:39 2003
@@ -34,6 +34,7 @@
 /* the following Id's must start at zero and be contiguous */
 
 #define menuitem(id)			AP_MENU_ID_##id,
+#define lastmenuitem(id)		AP_MENU_ID_##id
 
 enum _Ap_Menu_Id
 {
