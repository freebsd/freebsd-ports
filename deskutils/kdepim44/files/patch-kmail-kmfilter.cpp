--- kmail/kmfilter.cpp.orig	Sun Nov 30 10:49:22 2003
+++ kmail/kmfilter.cpp	Thu Feb  5 13:33:53 2004
@@ -147,9 +147,18 @@
   // that the pattern is purified.
   mPattern.readConfig(config);
 
-  if (bPopFilter)
+  if (bPopFilter) {
     // get the action description...
-    mAction = (KMPopFilterAction) config->readNumEntry( "action" );
+    QString action = config->readEntry( "action" );
+    if ( action == "down" )
+      mAction = Down;
+    else if ( action == "later" )
+      mAction = Later;
+    else if ( action == "delete" )
+      mAction = Delete;
+    else
+      mAction = NoAction;
+  }
   else {
     QStringList sets = config->readListEntry("apply-on");
     if ( sets.isEmpty() && !config->hasKey("apply-on") ) {
@@ -210,7 +219,19 @@
   mPattern.writeConfig(config);
 
   if (bPopFilter) {
-    config->writeEntry( "action", mAction );
+    switch ( mAction ) {
+    case Down:
+      config->writeEntry( "action", "down" );
+      break;
+    case Later:
+      config->writeEntry( "action", "later" );
+      break;
+    case Delete:
+      config->writeEntry( "action", "delete" );
+      break;
+    default:
+      config->writeEntry( "action", "" );
+    }
   } else {
     QStringList sets;
     if ( bApplyOnInbound )
