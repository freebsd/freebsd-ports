--- cpp/src/IceGrid/ServerI.cpp.orig	2016-11-15 12:22:54.201742997 +0100
+++ cpp/src/IceGrid/ServerI.cpp	2016-11-15 12:48:01.409625996 +0100
@@ -341,7 +341,22 @@
         {
             assert(_p->first.find("config_") == 0);
             const string service = _p->first.substr(7);
-            facet = "IceBox.Service." + service + ".Properties";
+            bool useSharedCommunicator = false;
+            for (PropertyDescriptorSeq::const_iterator d = _properties.at("config").begin(); d != _properties.at("config").end(); ++d)
+            {
+                if (d->name == "IceBox.UseSharedCommunicator." + service)
+                {
+                   useSharedCommunicator = (atoi(d->value.c_str()) > 0);
+                }
+            }
+            if (useSharedCommunicator)
+            {
+                facet = "IceBox.SharedCommunicator.Properties";
+            }
+            else
+            {
+                facet = "IceBox.Service." + service + ".Properties";
+            }
             if(_traceLevels->server > 1)
             {
                 const string id = _server->getId();
