--- src/VBox/Frontends/VirtualBox/src/settings/global/UIGlobalSettingsNetworkDetailsHost.cpp.orig	2017-03-08 17:19:57 UTC
+++ src/VBox/Frontends/VirtualBox/src/settings/global/UIGlobalSettingsNetworkDetailsHost.cpp
@@ -243,6 +243,6 @@ QString UIGlobalSettingsNetworkDetailsHo
         address.prepend(QString::number(uPart));
         uAddress = uAddress >> 8;
     }
-    return address.join('.');
+    return address.join(".");
 }
 
