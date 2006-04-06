--- src/mkinclud.mak.orig	Wed Apr  5 11:24:36 2006
+++ src/mkinclud.mak	Thu Apr  6 19:13:32 2006
@@ -443,8 +443,7 @@
 	mkdir -p $(lrundir)
 	/bin/cp -pr ../usrshare/* $(lrundir)
 	mkdir -p $(lmandir)/man1
-	$(INSTALL) --mode=+r,u+w ../man/*.1 $(lmandir)/man1
-	if (ls $(lmandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(lmandir)/man1/mined.1; fi
+	$(BSD_INSTALL_MAN) ../man/*.1 $(lmandir)/man1
 	$(extrainstall)
 
 # /opt installation:
