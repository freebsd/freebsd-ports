--- src/mkinclud.mak.orig	Mon Oct  9 18:00:00 2006
+++ src/mkinclud.mak	Sat Oct 21 13:51:41 2006
@@ -469,8 +469,7 @@
 	mkdir -p $(lrundir)
 	/bin/cp -pr ../usrshare/*/ $(lrundir)
 	mkdir -p $(lmandir)/man1
-	$(INSTALL) ../man/*.1 $(lmandir)/man1
-	if (ls $(lmandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(lmandir)/man1/mined.1; fi
+	$(BSD_INSTALL_MAN) ../man/*.1 $(lmandir)/man1
 	$(extrainstall)
 
 # /opt installation:
