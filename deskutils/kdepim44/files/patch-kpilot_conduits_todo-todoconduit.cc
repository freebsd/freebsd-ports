--- ../kpilot/conduits/todo/todoconduit.cc	2009/01/24 05:11:42	915906
+++ ../kpilot/conduits/todo/todoconduit.cc	2009/01/24 05:19:21	915907
@@ -68,6 +68,7 @@
 	
 	TodoSettings::self()->readConfig();
 	d->fCollectionId = TodoSettings::akonadiCollection();
+	d->fPrevCollectionId = TodoSettings::prevAkonadiCollection();
 }
 
 bool TodoConduit::initDataProxies()
