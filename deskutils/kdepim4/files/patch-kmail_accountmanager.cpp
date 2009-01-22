--- ../kmail/accountmanager.cpp	2009/01/20 11:56:48	914004
+++ ../kmail/accountmanager.cpp	2009/01/20 12:11:59	914005
@@ -39,88 +39,68 @@
   qDeleteAll(mAcctList);
 }
 
+//-----------------------------------------------------------------------------
+QStringList AccountManager::accountGroups() const
+{
+  return KMKernel::config()->groupList().filter( QRegExp( "Account \\d+" ) );
+}
 
 //-----------------------------------------------------------------------------
 void AccountManager::writeConfig( bool withSync )
 {
   KConfig* config = KMKernel::config();
 
-  // Delete all accounts for groups in the config file not having 
-  // Enabled=false flag (accountGroups) 
-  // and replace them with account groups existing in memory (mAcctList)
-  uint accounts = 0;
-  QStringList accountGroups =
-    config->groupList().filter( QRegExp( "Account \\d+" ) );
-  AccountList::ConstIterator enabledAccountIt = mAcctList.constBegin();
-  for ( QStringList::ConstIterator it = accountGroups.constBegin() ;; ) {
-    QString groupName;
-    bool appendNewGroup = false;
-    if ( it == accountGroups.constEnd() ) {
-      if ( enabledAccountIt == mAcctList.constEnd() )
-        break;
-      appendNewGroup = true;
-      groupName.sprintf( "Account %d", accounts + 1 );
-    }
-    else {
-      groupName = *it;
-      ++it;
-    }
+  QStringList accountGroupsInConfig = accountGroups();
+  QStringList accountGroupsToKeep;
 
-    KConfigGroup group(config, groupName);
-    uint id = group.readEntry( "Id", 0 );
-    if ( mDisabledAccounts.contains( id ) )
-      accounts++; // do not modify disabled account - skip
-    else {
-      if ( appendNewGroup ) {
-        (*enabledAccountIt)->writeConfig( group );
-        ++enabledAccountIt;
-        accounts++;
-      }
-      else // no such account on the list - disabled / enabled
-        config->deleteGroup( groupName );
-    }
+  // Write all account config groups to the config file and remember
+  // the config group names
+  foreach( KMAccount *account, mAcctList ) {
+    uint accountId = account->id();
+    QString groupName = QString( "Account %1" ).arg( accountId );
+    accountGroupsToKeep += groupName;
+    KConfigGroup group( config, groupName );
+    account->writeConfig( group );
   }
 
-  KConfigGroup group(config, "General");
-  group.writeEntry("accounts", accounts);
+  // Now, delete all config groups with "Account" in them which don't
+  // belong to the accounts we just saved (these are deleted accounts, then
+  // NOTE: This has to be done _after_ writing out the accounts, otherwise
+  //       there is the risk of data loss, see bug 169166
+  foreach( const QString &groupName, accountGroupsInConfig ) {
+    if ( !accountGroupsToKeep.contains( groupName ) )
+      config->deleteGroup( groupName );
+  }
 
-  if (withSync) config->sync();
+  if ( withSync )
+    config->sync();
 }
 
 
 //-----------------------------------------------------------------------------
 void AccountManager::readConfig(void)
 {
-  KConfig* config = KMKernel::config();
-  KMAccount* acct;
-  QString acctName;
-  QString groupName;
-  int i, num;
-
+  // Delete all in-memory accounts
   for ( AccountList::Iterator it( mAcctList.begin() ), end( mAcctList.end() ); it != end; ++it )
       delete *it;
   mAcctList.clear();
 
-  KConfigGroup general(config, "General");
-  num = general.readEntry( "accounts", 0 );
-
-  for (i=1; i<=num; i++)
-  {
-    groupName.sprintf("Account %d", i);
-    KConfigGroup group(config, groupName);
+  // Now loop over all account groups and load the accounts in them
+  KConfig* config = KMKernel::config();
+  QStringList accountGroupNames = accountGroups();
+  int accountNum = 1;
+  foreach( const QString &accountGroupName, accountGroupNames ) {
+    KConfigGroup group( config, accountGroupName );
     uint id = group.readEntry( "Id", 0 );
-    if ( !group.readEntry("Enabled", true) ) {
-      mDisabledAccounts += id;
-      continue;
-    }
-
     KAccount::Type acctType = KAccount::typeForName( group.readEntry( "Type" ) );
-    acctName = group.readEntry("Name");
-    if (acctName.isEmpty()) acctName = i18n("Account %1", i);
-    acct = create(acctType, acctName, id);
-    if (!acct) continue;
-    add(acct);
-    acct->readConfig(group);
+    QString accountName = group.readEntry( "Name" );
+    if ( accountName.isEmpty() )
+      accountName = i18n( "Account %1", accountNum++ );
+    KMAccount *account = create( acctType, accountName, id );
+    if ( !account )
+      continue;
+    add( account );
+    account->readConfig( group );
   }
 }
 
