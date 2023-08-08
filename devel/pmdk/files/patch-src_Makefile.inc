--- src/Makefile.inc.orig	2023-05-31 11:28:01 UTC
+++ src/Makefile.inc
@@ -268,7 +268,7 @@ install: all
 ifneq ($(LIBRARY_NAME),)
 	$(INSTALL) -d $(LIBS_DESTDIR)
 	$(INSTALL) -p -m 0755 $(TARGET_LIBS) $(LIBS_DESTDIR)
-	$(CP) -d $(TARGET_LINKS) $(LIBS_DESTDIR)
+	$(CP) -a $(TARGET_LINKS) $(LIBS_DESTDIR)
 endif
 
 uninstall:
