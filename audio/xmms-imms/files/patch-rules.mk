--- rules.mk.orig	Sun Jan 25 16:55:21 2004
+++ rules.mk	Wed Feb 11 18:43:22 2004
@@ -57,7 +57,7 @@
 	$(warning Use 'make install-user' to install for the current user only.)
 
 install-system: libimms.so
-	${INSTALL_PROGRAM} libimms.so ${DESTDIR}`xmms-config --visualization-plugin-dir`
+	${INSTALL_PROGRAM} libimms.so `xmms-config --visualization-plugin-dir`
 
 user-message:
 	$(warning Defaulting to installing for current user only.)
