--- ../registry/util/makefile.mk.orig	Sat Mar  2 22:28:13 2002
+++ ../registry/util/makefile.mk	Sat Mar  2 22:28:07 2002
@@ -95,7 +95,9 @@
 	$(STORELIB) \
 	$(LIBCIMT)
 
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP=	$(TARGET).map
+.ENDIF
 
 SHL1LIBS= $(LIB1TARGET)	
 SHL1DEPN= $(LIB1TARGET)
