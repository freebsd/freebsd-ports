--- sdext/source/pdfimport/makefile.mk.orig	2014-09-19 18:16:25 UTC
+++ sdext/source/pdfimport/makefile.mk
@@ -70,6 +70,10 @@ SHL1STDLIBS=\
 	$(CPPULIB)			\
 	$(SALLIB)
 
+.IF "$(SYSTEM_BOOST)" == "YES"
+    SHL1STDLIBS+=-lboost_system
+.ENDIF
+
 .IF "$(GUI)" == "UNX"
     SHL1STDLIBS+=-lbasegfx_s
 .ELSE
