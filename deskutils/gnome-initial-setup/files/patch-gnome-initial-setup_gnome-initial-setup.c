Disable NetworkManager.

Index: gnome-initial-setup/gnome-initial-setup.c
--- gnome-initial-setup/gnome-initial-setup.c.orig	2022-12-02 15:11:34 UTC
+++ gnome-initial-setup/gnome-initial-setup.c
@@ -32,7 +32,6 @@
 #include "pages/welcome/gis-welcome-page.h"
 #include "pages/language/gis-language-page.h"
 #include "pages/keyboard/gis-keyboard-page.h"
-#include "pages/network/gis-network-page.h"
 #include "pages/timezone/gis-timezone-page.h"
 #include "pages/privacy/gis-privacy-page.h"
 #include "pages/software/gis-software-page.h"
@@ -65,7 +64,6 @@ static PageData page_table[] = {
   PAGE (welcome, FALSE),
   PAGE (language, FALSE),
   PAGE (keyboard, FALSE),
-  PAGE (network,  FALSE),
   PAGE (privacy,  FALSE),
   PAGE (timezone, TRUE),
   PAGE (software, TRUE),
