--- src/kickpimcontactview.cpp.orig	Sun Aug 15 20:02:20 2004
+++ src/kickpimcontactview.cpp	Sun Aug 15 20:02:52 2004
@@ -111,7 +111,7 @@
   setSorting(0);
   sort();
   setSorting(-1);
-};
+}
 
 void KickPimContactView::onContactsDoubleClick(QListViewItem* qitem)
 {
@@ -129,7 +129,7 @@
   KickPimContactViewItem* item = 0;
   item = new KickPimContactViewItem( this, 0, KickPIM::rep()->displayName(contact) );
   item->setContact(contact);
-};
+}
 
 void KickPimContactView::addDistributionList(DistributionList* distList)
 {
@@ -137,7 +137,7 @@
   KickPimContactViewItem* item = 0;
   item = new KickPimContactViewItem( this, lastItem(), "["+distList->name()+"]" );
   item->setDistributionList(distList);
-};
+}
 
 int KickPimContactView::preferredHeight()
 {
