--- ../xmlhelp/util/makefile.mk.orig	Fri Nov 23 14:59:19 2001
+++ ../xmlhelp/util/makefile.mk	Wed Apr  3 01:21:02 2002
@@ -97,7 +97,9 @@
 SHL1TARGET=$(TARGET)$(UCP_VERSION)
 SHL1DEF=$(MISC)$/$(SHL1TARGET).def
 SHL1IMPLIB=i$(TARGET)
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP=exports.map
+.ENDIF
 
 # Add additional libs here.
 SHL1STDLIBS=                     \
