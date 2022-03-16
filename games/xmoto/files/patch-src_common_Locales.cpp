--- src/common/Locales.cpp.orig	2020-06-21 19:18:16 UTC
+++ src/common/Locales.cpp
@@ -25,7 +25,9 @@ Foundation, Inc., 59 Temple Place, Suite 330, Boston, 
 #include "helpers/Log.h"
 #include "helpers/VExcept.h"
 #include <iostream>
+#if USE_GETTEXT
 #include <libintl.h>
+#endif
 
 #define PACKAGE_LANG "xmoto"
 
@@ -68,10 +70,12 @@ std::pair<std::string, std::string> Locales::changeLoc
 #endif
 
   /* Make change known.  */
+#if USE_GETTEXT
   {
     extern int _nl_msg_cat_cntr;
     ++_nl_msg_cat_cntr;
   }
+#endif
 
   std::pair<std::string, std::string> locale_str(
     locale.first == NULL ? std::string("") : std::string(locale.first),
