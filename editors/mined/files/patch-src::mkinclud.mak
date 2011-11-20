--- ./src/mkinclud.mak.orig	2011-11-15 00:00:00.000000000 +0100
+++ ./src/mkinclud.mak	2011-11-20 19:28:39.000000000 +0100
@@ -566,7 +566,7 @@
 	mkdir -p $(DESTDIR)$(mandir)/man1
 	$(INSTALL) ../man/*.1 $(DESTDIR)$(mandir)/man1
 	# zip man if mans are zipped in actual mandir (not DESTDIR)
-	if (ls $(mandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(DESTDIR)$(mandir)/man1/mined.1; fi
+	#if (ls $(mandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(DESTDIR)$(mandir)/man1/mined.1; fi
 	# ==== install desktop context menu item ("Open With")
 	( $(rootmenu) && $(rooticon) ) || ( $(usermenu) && $(usericon) ) || echo Could not install desktop menu entry
 	# ==== install system-specific stuff (e.g. wined, README.cygwin)
@@ -587,9 +587,9 @@
 	/bin/cp -pr ../usrshare/* $(DESTDIR)$(lrundir)
 	# ==== install manual page
 	mkdir -p $(DESTDIR)$(lmandir)/man1
-	$(INSTALL) ../man/*.1 $(DESTDIR)$(lmandir)/man1
+	$(BSD_INSTALL_MAN) ../man/*.1 $(DESTDIR)$(lmandir)/man1
 	# zip man if mans are zipped in actual mandir (not DESTDIR)
-	if (ls $(lmandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(DESTDIR)$(lmandir)/man1/mined.1; fi
+	#if (ls $(lmandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(DESTDIR)$(lmandir)/man1/mined.1; fi
 	# ==== install desktop context menu item ("Open With")
 	( $(localmenu) && $(localicon) ) || ( $(usermenu) && $(usericon) ) || echo Could not install desktop menu entry
 	# ==== install system-specific stuff (e.g. wined, README.cygwin)
