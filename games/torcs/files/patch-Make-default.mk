--- Make-default.mk.orig	2013-01-12 14:25:08 UTC
+++ Make-default.mk
@@ -134,7 +134,7 @@ include .depend
 endif
 
 .depend:
-	$(CPP) $(INCFLAGS) $(CFLAGSD) $(COMPILFLAGS)  $(SOURCES) > .depend
+	#$(CPP) $(INCFLAGS) $(CFLAGSD) $(COMPILFLAGS)  $(SOURCES) > .depend
 
 dep:	.depend
 
@@ -181,7 +181,7 @@ win32setup: win32start exportswin32 installshipswin32 
 
 linuxconfstart:
 	@rm -f ${SETUP_LINUX}
-	@echo '#! /bin/bash' >> ${SETUP_LINUX}
+	@echo '#! /usr/local/bin/bash' >> ${SETUP_LINUX}
 	@echo '' >> ${SETUP_LINUX}
 	@echo '[ -z "$$1" ] && exit 1' >> ${SETUP_LINUX}
 	@echo '[ ! -d "$$1" ] && exit 1' >> ${SETUP_LINUX}
