--- ./src/mkinclud.mak.orig	Thu Jan 27 15:08:56 2005
+++ ./src/mkinclud.mak	Sat Feb  5 22:41:41 2005
@@ -307,8 +307,7 @@
 	mkdir -p $(lhlpdir)
 	$(INSTALL) ../usrshare/* $(lhlpdir)
 	mkdir -p $(lmandir)/man1
-	$(INSTALL) --mode=+r,u+w ../man/mined.1 $(lmandir)/man1
-	(ls $(lmandir)/man1/*.gz && type gzip) > /dev/null 2>&1 && gzip -f $(lmandir)/man1/mined.1
+	$(BSD_INSTALL_MAN) ../man/mined.1 $(lmandir)/man1
 
 # /opt installation:
 optinstall:	mined help man ${INSTALLTARGET}
