--- rules.mk.orig	Wed Aug 18 01:56:28 2004
+++ rules.mk	Tue Aug 31 16:13:51 2004
@@ -26,7 +26,7 @@
 endif
 
 define installprogs
-    ${INSTALL_PROGRAM} analyzer immsremote immstool ${PREFIX}
+    ${INSTALL_PROGRAM} analyzer immsremote immstool ${PREFIX}/bin
 endef
 
 system-message:
