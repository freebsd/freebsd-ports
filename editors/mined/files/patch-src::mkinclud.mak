--- ./src/mkinclud.mak.orig	Tue Feb  8 11:19:14 2005
+++ ./src/mkinclud.mak	Thu Feb 10 19:47:33 2005
@@ -307,8 +307,7 @@
 	mkdir -p $(lhlpdir)
 	$(INSTALL) ../usrshare/* $(lhlpdir)
 	mkdir -p $(lmandir)/man1
-	$(INSTALL) --mode=+r,u+w ../man/mined.1 $(lmandir)/man1
-	if (ls $(lmandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(lmandir)/man1/mined.1; fi
+	$(BSD_INSTALL_MAN) ../man/mined.1 $(lmandir)/man1
 
 # /opt installation:
 optinstall:	mined help man ${INSTALLTARGET}
