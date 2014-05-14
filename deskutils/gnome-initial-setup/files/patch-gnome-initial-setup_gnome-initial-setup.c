--- gnome-initial-setup/gnome-initial-setup.c.orig	2014-05-13 17:04:40.424928151 +0000
+++ gnome-initial-setup/gnome-initial-setup.c	2014-05-13 17:05:02.560926466 +0000
@@ -40,7 +40,6 @@
 #include "pages/region/gis-region-page.h"
 #include "pages/keyboard/gis-keyboard-page.h"
 #include "pages/eulas/gis-eula-pages.h"
-#include "pages/network/gis-network-page.h"
 #include "pages/timezone/gis-timezone-page.h"
 #include "pages/goa/gis-goa-page.h"
 #include "pages/account/gis-account-pages.h"
@@ -64,7 +63,6 @@
   PAGE (region,   FALSE),
   PAGE (keyboard, FALSE),
   PAGE (eula,     FALSE),
-  PAGE (network,  FALSE),
   PAGE (timezone, TRUE),
   PAGE (goa,      FALSE),
   PAGE (account,  TRUE),
