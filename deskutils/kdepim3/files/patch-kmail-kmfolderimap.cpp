--- kmail/kmfolderimap.cpp.orig	Sat Jan 17 13:55:08 2004
+++ kmail/kmfolderimap.cpp	Thu Feb  5 13:33:38 2004
@@ -1207,7 +1207,16 @@
 {
   KURL url = mAccount->getUrl();
   KMFolderImap *msg_parent = static_cast<KMFolderImap*>(msg->parent());
-  url.setPath(msg_parent->imapPath() + ";UID=" + msg->headerField("X-UID"));
+  QString uid = msg->headerField("X-UID");
+  /* If the uid is empty the delete job below will nuke all mail in the 
+     folder, so we better safeguard against that. See ::expungeFolder, as
+     to why. :( */
+  if ( uid.isEmpty() ) {
+     kdDebug( 5006 ) << "KMFolderImap::deleteMessage: Attempt to delete "
+                        "an empty UID. Aborting."  << endl;
+     return;
+  }
+  url.setPath(msg_parent->imapPath() + ";UID=" + uid );
   if ( mAccount->makeConnection() != ImapAccountBase::Connected )
     return;
   KIO::SimpleJob *job = KIO::file_delete(url, FALSE);
@@ -1228,7 +1237,11 @@
   KMFolderImap *msg_parent = static_cast<KMFolderImap*>(msgList.first()->parent());
   for ( QStringList::Iterator it = sets.begin(); it != sets.end(); ++it )
   {
-    url.setPath(msg_parent->imapPath() + ";UID=" + *it);
+    QString uid = *it;
+    // Don't delete with no uid, that nukes the folder. Should not happen, but
+    // better safe than sorry.
+    if ( uid.isEmpty() ) continue;
+    url.setPath(msg_parent->imapPath() + ";UID=" + uid);
     if ( mAccount->makeConnection() != ImapAccountBase::Connected )
       return;
     KIO::SimpleJob *job = KIO::file_delete(url, FALSE);
