--- TrustedQSL-1.11/crqwiz.cpp.orig	Fri Mar 11 07:47:06 2005
+++ TrustedQSL-1.11/crqwiz.cpp	Fri May 11 12:23:38 2007
@@ -9,6 +9,7 @@
  ***************************************************************************/
 
 #include <ctype.h>
+#include <stdint.h>
 #include "crqwiz.h"
 #include "dxcc.h"
 #include "util.h"
@@ -104,7 +105,7 @@
 CRQ_ProviderPage::DoUpdateInfo() {
 	int sel = tc_provider->GetSelection();
 	if (sel >= 0) {
-		int idx = (int)(tc_provider->GetClientData(sel));
+		int idx = (int)((intptr_t)(tc_provider->GetClientData(sel)));
 		if (idx >=0 && idx < (int)providers.size()) {
 			Parent()->provider = providers[idx];
 			wxString info;
@@ -521,7 +522,7 @@
 		}
 		ok = (ok && havealpha && havenumeric);
 	}
-	Parent()->dxcc = (int)(tc_dxcc->GetClientData(tc_dxcc->GetSelection()));
+	Parent()->dxcc = (int)((intptr_t)(tc_dxcc->GetClientData(tc_dxcc->GetSelection())));
 	if (Parent()->dxcc < 0) {
 		msg = wxT("You must select a DXCC entity.");
 		ok = false;
