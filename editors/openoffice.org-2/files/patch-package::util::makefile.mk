--- ../package/util/makefile.mk.orig	Sat Mar  2 22:06:28 2002
+++ ../package/util/makefile.mk	Sat Mar  2 22:06:31 2002
@@ -88,7 +88,9 @@
 
 SHL1TARGET=$(TARGET)$(MAJOR_VERSION)
 SHL1IMPLIB=i$(TARGET)
+.IF "$(OS)"!="FREEBSD"
 SHL1VERSIONMAP=$(SOLARENV)$/src$/component.map
+.ENDIF
 
 SHL1STDLIBS=\
 	$(CPPULIB)		\
