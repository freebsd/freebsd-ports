--- ucb/source/ucp/webdav/makefile.mk.orig	Wed Jun 12 01:04:43 2002
+++ ucb/source/ucp/webdav/makefile.mk	Wed Jun 12 01:04:53 2002
@@ -120,7 +120,7 @@
 
 SHL1TARGET=$(TARGET)$(UCP_VERSION)
 SHL1IMPLIB=i$(TARGET)
-.IF "$(OS)"=="MACOSX" || "$(OS)"=="FREEBSD"
+.IF "$(OS)"=="MACOSX"
 .ELSE
 SHL1VERSIONMAP=exports.map
 .ENDIF
