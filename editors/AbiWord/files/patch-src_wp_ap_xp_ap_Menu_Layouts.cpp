--- src/wp/ap/xp/ap_Menu_Layouts.cpp.orig	Fri Aug 29 17:25:41 2003
+++ src/wp/ap/xp/ap_Menu_Layouts.cpp	Fri Aug 29 17:28:04 2003
@@ -443,6 +443,7 @@
 			m_pLabelSet->setLabel( (AP_MENU_ID_##id),	\
 								    pSS->getValue(AP_STRING_ID_MENU_LABEL_##id), \
 								    pSS->getValue(AP_STRING_ID_MENU_STATUSLINE_##id) );
+		#define lastmenuitem(id) menuitem(id)
 			#include "ap_Menu_Id_List.h"
 		#undef menuitem
 		return true;
