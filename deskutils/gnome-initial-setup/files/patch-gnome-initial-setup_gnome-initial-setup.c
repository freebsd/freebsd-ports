--- gnome-initial-setup/gnome-initial-setup.c.orig	2015-03-04 22:30:52.000000000 +0100
+++ gnome-initial-setup/gnome-initial-setup.c	2015-05-14 07:43:32.295991000 +0200
@@ -40,7 +40,6 @@
 #include "pages/region/gis-region-page.h"
 #include "pages/keyboard/gis-keyboard-page.h"
 #include "pages/eulas/gis-eula-pages.h"
-#include "pages/network/gis-network-page.h"
 #include "pages/timezone/gis-timezone-page.h"
 #include "pages/privacy/gis-privacy-page.h"
 #include "pages/goa/gis-goa-page.h"
@@ -65,7 +64,7 @@
   /* PAGE (region,   FALSE), */
   PAGE (keyboard, FALSE),
   PAGE (eula,     FALSE),
-  PAGE (network,  FALSE),
+  /* PAGE (network,  FALSE), */
   PAGE (privacy,  FALSE),
   PAGE (timezone, TRUE),
   PAGE (goa,      FALSE),
