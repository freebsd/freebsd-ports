--- ../kmail/kmkernel.cpp	2009/01/20 11:56:48	914004
+++ ../kmail/kmkernel.cpp	2009/01/20 12:11:59	914005
@@ -1480,8 +1480,7 @@
   {
     KMFolderNode *node = *it;
     if (node->isDir() || ((acct = the_acctMgr->find(node->id()))
-                          && ( acct->type() == KAccount::Imap ))
-                      || !the_acctMgr->isEnabled( node->id() ))
+                          && ( acct->type() == KAccount::Imap )))
     {
       ++it;
     } else {
