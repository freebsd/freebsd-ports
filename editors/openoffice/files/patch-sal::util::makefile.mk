--- ../sal/util/makefile.mk.orig	Sun Mar 17 12:51:30 2002
+++ ../sal/util/makefile.mk	Wed Apr  3 01:04:34 2002
@@ -117,7 +117,9 @@
 SHL1TARGET= $(TARGET)
 SHL1IMPLIB= i$(TARGET)
 
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP=	$(TARGET).map
+.ENDIF
 
 .IF "$(GUI)"=="WNT"
 .IF "$(COM)"!="GCC"
