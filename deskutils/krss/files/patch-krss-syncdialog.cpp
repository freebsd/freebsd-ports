--- krss/syncdialog.cpp.orig	Tue Sep 11 01:23:37 2001
+++ krss/syncdialog.cpp	Wed May 21 10:30:45 2003
@@ -27,6 +27,8 @@
 
 #include <klocale.h>
 
+using namespace std;
+
 SyncDialog::SyncDialog(KConfig *config, QWidget *parent, const char *name )
 : KDialogBase(parent,name,true,i18n("Sharing Feeds"),User1|Close,Close,true,i18n("Skip"))
 {
