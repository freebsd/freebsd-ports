--- krss/amphetadeskinport.cpp.orig	Wed Feb 20 15:46:11 2002
+++ krss/amphetadeskinport.cpp	Wed May 21 10:21:02 2003
@@ -38,6 +38,8 @@
 
 #include "sitehandler.h"
 
+using namespace std;
+
 
 AmphetaDeskInport::AmphetaDeskInport(KApplication *app, SiteHandler *sitehandler, QWidget *parent, const char *name )
 : KDialogBase(parent,name,true,i18n("Import Sites from AmphetaDesk"),Details|User1|Close,Close,true,i18n("Import")), QXmlDefaultHandler()
