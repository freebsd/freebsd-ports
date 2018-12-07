--- src/Makefile.inc.orig	2018-10-26 15:43:47 UTC
+++ src/Makefile.inc
@@ -294,7 +294,7 @@ install: all
 ifneq ($(LIBRARY_NAME),)
 	$(INSTALL) -d $(LIBS_DESTDIR)
 	$(INSTALL) -p -m 0755 $(TARGET_LIBS) $(LIBS_DESTDIR)
-	$(CP) -d $(TARGET_LINKS) $(LIBS_DESTDIR)
+	$(CP) -a $(TARGET_LINKS) $(LIBS_DESTDIR)
 endif
 
 uninstall:
