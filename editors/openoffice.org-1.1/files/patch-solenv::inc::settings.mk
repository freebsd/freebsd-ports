--- ../solenv/inc/settings.mk.orig	Wed Mar 13 20:44:42 2002
+++ ../solenv/inc/settings.mk	Wed Mar 13 20:45:05 2002
@@ -173,7 +173,6 @@
 CDEFSOPT=
 HDEFS=
 
-CC=
 .IF "$(add_cflags)"!=""
 ENVCFLAGS+=$(add_cflags)
 .ENDIF
@@ -271,8 +270,6 @@
 AS=
 BC=
 COBOL=
-CPP=
-CXX=
 FOR=
 PASCAL=
 
@@ -1499,4 +1496,3 @@
 .INCLUDE : $(MISC)$/$(COMP9TYPELIST).mk
 $(COMP9TYPELIST)_XML2CMPTYPES:=$(shell xml2cmp -types stdout $(MISC)$/$(COMP9TYPELIST)$($(WINVERSIONNAMES)_MAJOR).xml)
 .ENDIF
-
