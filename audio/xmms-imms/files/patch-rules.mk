--- rules.mk.orig	Wed Aug 18 01:56:28 2004
+++ rules.mk	Sat Jan 22 19:49:37 2005
@@ -26,7 +26,7 @@
 endif
 
 define installprogs
-    ${INSTALL_PROGRAM} analyzer immsremote immstool ${PREFIX}
+    ${INSTALL_PROGRAM} analyzer immsremote immstool ${PREFIX}/bin
 endef
 
 system-message:
