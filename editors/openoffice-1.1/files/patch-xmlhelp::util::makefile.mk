--- ../xmlhelp/util/makefile.mk.orig	Sun Mar  3 01:49:15 2002
+++ ../xmlhelp/util/makefile.mk	Sun Mar  3 01:49:19 2002
@@ -94,7 +94,9 @@
 SHL1TARGET=$(TARGET)$(UCP_VERSION)
 SHL1DEF=$(MISC)$/$(SHL1TARGET).def
 SHL1IMPLIB=i$(TARGET)
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP=exports.map
+.ENDIF
 
 # Add additional libs here.
 SHL1STDLIBS=                     \
