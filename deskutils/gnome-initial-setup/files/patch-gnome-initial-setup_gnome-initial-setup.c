$OpenBSD: patch-gnome-initial-setup_gnome-initial-setup_c,v 1.11 2021/05/14 10:29:31 ajacoutot Exp $

Disable NetworkManager.

Index: gnome-initial-setup/gnome-initial-setup.c
--- gnome-initial-setup/gnome-initial-setup.c.orig
+++ gnome-initial-setup/gnome-initial-setup.c
@@ -35,7 +35,6 @@
 #include "pages/welcome/gis-welcome-page.h"
 #include "pages/language/gis-language-page.h"
 #include "pages/keyboard/gis-keyboard-page.h"
-#include "pages/network/gis-network-page.h"
 #include "pages/timezone/gis-timezone-page.h"
 #include "pages/privacy/gis-privacy-page.h"
 #include "pages/goa/gis-goa-page.h"
@@ -67,7 +66,6 @@ static PageData page_table[] = {
   PAGE (welcome, FALSE),
   PAGE (language, FALSE),
   PAGE (keyboard, FALSE),
-  PAGE (network,  FALSE),
   PAGE (privacy,  FALSE),
   PAGE (timezone, TRUE),
   PAGE (goa,      FALSE),
