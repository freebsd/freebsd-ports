--- src/ListNavigationPanel.h.orig     2023-04-27 07:55:48 UTC
+++ src/ListNavigationPanel.h
@@ -13,7 +13,7 @@
 #include <wx/window.h>
 #include <wx/containr.h>
 
-extern template class WXDLLIMPEXP_CORE wxNavigationEnabled<wxWindow>;
+//extern template class WXDLLIMPEXP_CORE wxNavigationEnabled<wxWindow>;
 
 #include "ListNavigationEnabled.h"
 
