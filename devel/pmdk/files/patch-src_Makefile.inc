--- src/Makefile.inc.orig	2019-08-27 15:43:26 UTC
+++ src/Makefile.inc
@@ -300,7 +300,7 @@ install: all
 ifneq ($(LIBRARY_NAME),)
 	$(INSTALL) -d $(LIBS_DESTDIR)
 	$(INSTALL) -p -m 0755 $(TARGET_LIBS) $(LIBS_DESTDIR)
-	$(CP) -d $(TARGET_LINKS) $(LIBS_DESTDIR)
+	$(CP) -a $(TARGET_LINKS) $(LIBS_DESTDIR)
 endif
 
 uninstall:
