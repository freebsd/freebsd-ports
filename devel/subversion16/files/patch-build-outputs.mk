--- ./build-outputs.mk.orig	2013-11-05 22:37:50.000000000 +0100
+++ ./build-outputs.mk	2013-11-05 22:38:41.000000000 +0100
@@ -895,9 +895,9 @@
 
 install-tools: tools/diff/diff$(EXEEXT) tools/diff/diff3$(EXEEXT) tools/diff/diff4$(EXEEXT) tools/server-side/svn-populate-node-origins-index$(EXEEXT) tools/server-side/svnauthz-validate$(EXEEXT) tools/client-side/svnmucc/svnmucc$(EXEEXT)
 	$(MKDIR) $(DESTDIR)$(toolsdir)
-	cd tools/diff ; $(INSTALL_TOOLS) diff$(EXEEXT) $(DESTDIR)$(toolsdir)/diff$(EXEEXT)
-	cd tools/diff ; $(INSTALL_TOOLS) diff3$(EXEEXT) $(DESTDIR)$(toolsdir)/diff3$(EXEEXT)
-	cd tools/diff ; $(INSTALL_TOOLS) diff4$(EXEEXT) $(DESTDIR)$(toolsdir)/diff4$(EXEEXT)
+#	cd tools/diff ; $(INSTALL_TOOLS) diff$(EXEEXT) $(DESTDIR)$(toolsdir)/diff$(EXEEXT)
+#	cd tools/diff ; $(INSTALL_TOOLS) diff3$(EXEEXT) $(DESTDIR)$(toolsdir)/diff3$(EXEEXT)
+#	cd tools/diff ; $(INSTALL_TOOLS) diff4$(EXEEXT) $(DESTDIR)$(toolsdir)/diff4$(EXEEXT)
 	cd tools/server-side ; $(INSTALL_TOOLS) svn-populate-node-origins-index$(EXEEXT) $(DESTDIR)$(toolsdir)/svn-populate-node-origins-index$(EXEEXT)
 	cd tools/server-side ; $(INSTALL_TOOLS) svnauthz-validate$(EXEEXT) $(DESTDIR)$(toolsdir)/svnauthz-validate$(EXEEXT)
 	cd tools/client-side/svnmucc ; $(INSTALL_TOOLS) svnmucc$(EXEEXT) $(DESTDIR)$(toolsdir)/svnmucc$(EXEEXT)
