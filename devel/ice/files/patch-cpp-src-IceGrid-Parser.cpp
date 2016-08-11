--- cpp/src/IceGrid/Parser.cpp.orig	2016-05-16 22:49:28.132976967 +0200
+++ cpp/src/IceGrid/Parser.cpp	2016-05-16 23:15:17.589867966 +0200
@@ -1912,10 +1912,24 @@
             return;
         }
 
+
         Ice::ObjectPrx admin = _admin->getServerAdmin(server);
         Ice::PropertiesAdminPrx propAdmin = 
             Ice::PropertiesAdminPrx::uncheckedCast(admin, "IceBox.Service." + service + ".Properties");
 
+        try
+        {
+            propAdmin->ice_ping();
+        }
+        catch(const Ice::ObjectNotExistException&)
+        {
+            Ice::PropertiesAdminPrx serverPropAdmin = Ice::PropertiesAdminPrx::uncheckedCast(admin, "Properties");
+            if (atoi(serverPropAdmin->getProperty("IceBox.UseSharedCommunicator." + service).c_str()))
+            {
+                propAdmin = Ice::PropertiesAdminPrx::uncheckedCast(admin, "IceBox.SharedCommunicator.Properties");
+            }
+        }
+
         if(single)
         {
             string val = propAdmin->getProperty(property);
