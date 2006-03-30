--- src/mkinclud.mak.orig	Wed Mar 29 00:00:00 2006
+++ src/mkinclud.mak	Fri Mar 31 00:13:36 2006
@@ -396,7 +396,7 @@
 
 
 # Install aliases; may be suppressed with make ...install makelinks=
-makelinks=$(MAKE) links
+makelinks=$(MAKE) -f makefile.bsd links
 
 links:	$(linkdir)/xmined $(linkdir)/minmacs $(linkdir)/mpico $(linkdir)/mstar
 
@@ -441,8 +441,7 @@
 	mkdir -p $(lrundir)
 	/bin/cp -pr ../usrshare/* $(lrundir)
 	mkdir -p $(lmandir)/man1
-	$(INSTALL) --mode=+r,u+w ../man/*.1 $(lmandir)/man1
-	if (ls $(lmandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(lmandir)/man1/mined.1; fi
+	$(BSD_INSTALL_MAN) ../man/mined.1 $(lmandir)/man1
 	$(extrainstall)
 
 # /opt installation:
