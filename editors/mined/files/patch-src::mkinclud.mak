--- ./src/mkinclud.mak.orig	2010-02-22 00:00:00.000000000 +0100
+++ ./src/mkinclud.mak	2010-07-14 11:58:28.209069303 +0200
@@ -538,9 +538,8 @@
 	mkdir -p $(DESTDIR)$(lrundir)
 	/bin/cp -pr ../usrshare/*/ $(DESTDIR)$(lrundir)
 	mkdir -p $(DESTDIR)$(lmandir)/man1
-	$(INSTALL) ../man/*.1 $(DESTDIR)$(lmandir)/man1
+	$(BSD_INSTALL_MAN) ../man/*.1 $(DESTDIR)$(lmandir)/man1
 	# zip man if mans are zipped in actual mandir (not DESTDIR)
-	if (ls $(lmandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(DESTDIR)$(lmandir)/man1/mined.1; fi
 	$(extrainstall)
 
 # /opt installation:
