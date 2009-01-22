--- ../kmail/accountmanager.h	2009/01/20 11:56:48	914004
+++ ../kmail/accountmanager.h	2009/01/20 12:11:59	914005
@@ -80,13 +80,6 @@
     KMAccount *find( const uint id ) const;
 
     /**
-      @return true if account with ID @p id is enabled. 
-      Accounts can be disabled by setting "enabled" flag to false 
-      in "Account #" groups of kmailrc.
-    */
-    bool isEnabled( const uint id ) const { return !mDisabledAccounts.contains(id); }
-
-    /**
       Physically remove account. Also deletes the given account object !
       Returns false and does nothing if the account cannot be removed.
     */
@@ -163,6 +156,12 @@
      */
     uint createId();
 
+    /**
+     * Return a list of config group names of all config groups that store
+     * receiving accounts.
+     */
+    QStringList accountGroups() const;
+
     AccountList   mAcctList;
     AccountList::Iterator mPtrListInterfaceProxyIterator;
     AccountList   mAcctChecking;
@@ -176,9 +175,6 @@
 
     // if a summary should be displayed
     bool mDisplaySummary;
-
-    // IDs of disabled accounts, used in AccountManager::writeConfig()
-    QSet<uint> mDisabledAccounts;
 };
 
 } // namespace KMail
