--- flameshot.pro.orig	2017-12-20 13:41:48 UTC
+++ flameshot.pro
@@ -177,27 +177,27 @@ unix: {
     packaging {
         USRPATH = /usr
     } else {
-        USRPATH = /usr/local
+        USRPATH = %%LOCALBASE%%
     }
 
     target.path = $${BASEDIR}$${USRPATH}/bin/
 
-    qmfile.path = $${BASEDIR}/usr/share/flameshot/translations/
+    qmfile.path = $${BASEDIR}$${USRPATH}/share/flameshot/translations/
     qmfile.files = $${TRANSLATIONS_FILES}
 
-    dbus.path = $${BASEDIR}/usr/share/dbus-1/interfaces/
+    dbus.path = $${BASEDIR}$${USRPATH}/share/dbus-1/interfaces/
     dbus.files = dbus/org.dharkael.Flameshot.xml
     
     icon.path = $${BASEDIR}$${USRPATH}/share/icons/
     icon.files = img/flameshot.png
 
-    completion.path = /usr/share/bash-completion/completions/
+    completion.path = $${BASEDIR}$${USRPATH}/share/bash-completion/completions/
     completion.files = docs/bash-completion/flameshot
 
     desktopentry.path = $${BASEDIR}$${USRPATH}/share/applications
     desktopentryinit.path = $${BASEDIR}$${USRPATH}/share/applications
     desktopentryconfig.path = $${BASEDIR}$${USRPATH}/share/applications
-    servicedbus.path = $${BASEDIR}/usr/share/dbus-1/services/
+    servicedbus.path = $${BASEDIR}$${USRPATH}/share/dbus-1/services/
 
     packaging {
         desktopentry.files = docs/desktopEntry/package/flameshot.desktop
