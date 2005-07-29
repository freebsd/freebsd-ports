--- ucb/source/ucp/hierarchy/makefile.mk.orig	Wed Jun 12 01:34:50 2002
+++ ucb/source/ucp/hierarchy/makefile.mk	Wed Jun 12 01:34:52 2002
@@ -96,7 +96,7 @@
 
 SHL1TARGET=$(TARGET)$(UCPHIER_MAJOR)
 SHL1IMPLIB=i$(TARGET)
-.IF "$(OS)"=="MACOSX"||"$(OS)"=="FREEBSD"
+.IF "$(OS)"=="MACOSX"
 .ELSE
 SHL1VERSIONMAP=	$(TARGET).map
 .ENDIF
