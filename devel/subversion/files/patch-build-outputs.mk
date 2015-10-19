--- build-outputs.mk.orig	2015-10-15 01:24:35.493881000 +0300
+++ build-outputs.mk	2015-10-15 01:25:35.653321000 +0300
@@ -1316,11 +1316,11 @@
 
 install-tools: tools/diff/diff$(EXEEXT) tools/diff/diff3$(EXEEXT) tools/diff/diff4$(EXEEXT) tools/dev/fsfs-access-map$(EXEEXT) tools/server-side/mod_dontdothat/mod_dontdothat.la tools/server-side/svn-populate-node-origins-index$(EXEEXT) tools/server-side/svnauthz$(EXEEXT) tools/server-side/svnauthz-validate$(EXEEXT) tools/dev/svnraisetreeconflict/svnraisetreeconflict$(EXEEXT) tools/dev/x509-parser$(EXEEXT)
 	$(MKDIR) $(DESTDIR)$(toolsdir)
-	cd tools/diff ; $(INSTALL_TOOLS) diff$(EXEEXT) $(DESTDIR)$(toolsdir)/diff$(EXEEXT)
+	cd tools/diff ; $(INSTALL_TOOLS) diff$(EXEEXT) $(DESTDIR)$(toolsdir)/svndiff$(EXEEXT)
 	
-	cd tools/diff ; $(INSTALL_TOOLS) diff3$(EXEEXT) $(DESTDIR)$(toolsdir)/diff3$(EXEEXT)
+	cd tools/diff ; $(INSTALL_TOOLS) diff3$(EXEEXT) $(DESTDIR)$(toolsdir)/svndiff3$(EXEEXT)
 	
-	cd tools/diff ; $(INSTALL_TOOLS) diff4$(EXEEXT) $(DESTDIR)$(toolsdir)/diff4$(EXEEXT)
+	cd tools/diff ; $(INSTALL_TOOLS) diff4$(EXEEXT) $(DESTDIR)$(toolsdir)/svndiff4$(EXEEXT)
 	
 	cd tools/dev ; $(INSTALL_TOOLS) fsfs-access-map$(EXEEXT) $(DESTDIR)$(toolsdir)/fsfs-access-map$(EXEEXT)
 	
