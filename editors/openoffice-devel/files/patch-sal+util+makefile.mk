--- ../sal/util/makefile.mk.orig	Wed Mar 12 23:57:03 2003
+++ ../sal/util/makefile.mk	Wed Mar 12 23:56:54 2003
@@ -120,6 +120,8 @@
 
 .IF "$(OS)"=="LINUX"
 SHL1VERSIONMAP=	gcc3_linux_intel.map
+.ELIF "$(OS)"=="FREEBSD"
+SHL1VERSIONMAP=	gcc3_linux_intel.map
 .ELSE
 SHL1VERSIONMAP=	$(TARGET).map
 .ENDIF
