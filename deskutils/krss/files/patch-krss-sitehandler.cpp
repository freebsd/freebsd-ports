--- krss/sitehandler.cpp.orig	Wed Feb 20 13:38:38 2002
+++ krss/sitehandler.cpp	Wed May 21 10:38:31 2003
@@ -35,6 +35,8 @@
 #include "mychannelbar.h"
 #include "editfeedlistviewitem.h"
 
+using namespace std;
+
 SiteHandler::SiteHandler()
 {
 	mReadingSites = mReadingSite = mReadingName = mReadingUsed = false;
