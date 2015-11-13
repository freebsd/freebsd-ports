--- build-outputs.mk.orig	2013-06-13 13:08:06.000000000 +0400
+++ build-outputs.mk	2013-06-20 00:53:54.000000000 +0400
@@ -1136,9 +1136,9 @@
 
 install-tools: tools/diff/diff$(EXEEXT) tools/diff/diff3$(EXEEXT) tools/diff/diff4$(EXEEXT) tools/dev/fsfs-access-map$(EXEEXT) tools/dev/fsfs-reorg$(EXEEXT) tools/server-side/fsfs-stats$(EXEEXT) tools/server-side/mod_dontdothat/mod_dontdothat.la tools/client-side/svn-bench/svn-bench$(EXEEXT) tools/server-side/svn-populate-node-origins-index$(EXEEXT) tools/server-side/svn-rep-sharing-stats$(EXEEXT) tools/server-side/svnauthz$(EXEEXT) tools/server-side/svnauthz-validate$(EXEEXT) tools/dev/svnraisetreeconflict/svnraisetreeconflict$(EXEEXT)
 	$(MKDIR) $(DESTDIR)$(toolsdir)
-	cd tools/diff ; $(INSTALL_TOOLS) diff$(EXEEXT) $(DESTDIR)$(toolsdir)/diff$(EXEEXT)
-	cd tools/diff ; $(INSTALL_TOOLS) diff3$(EXEEXT) $(DESTDIR)$(toolsdir)/diff3$(EXEEXT)
-	cd tools/diff ; $(INSTALL_TOOLS) diff4$(EXEEXT) $(DESTDIR)$(toolsdir)/diff4$(EXEEXT)
+	cd tools/diff ; $(INSTALL_TOOLS) diff$(EXEEXT) $(DESTDIR)$(toolsdir)/svndiff$(EXEEXT)
+	cd tools/diff ; $(INSTALL_TOOLS) diff3$(EXEEXT) $(DESTDIR)$(toolsdir)/svndiff3$(EXEEXT)
+	cd tools/diff ; $(INSTALL_TOOLS) diff4$(EXEEXT) $(DESTDIR)$(toolsdir)/svndiff4$(EXEEXT)
 	cd tools/dev ; $(INSTALL_TOOLS) fsfs-access-map$(EXEEXT) $(DESTDIR)$(toolsdir)/fsfs-access-map$(EXEEXT)
 	cd tools/dev ; $(INSTALL_TOOLS) fsfs-reorg$(EXEEXT) $(DESTDIR)$(toolsdir)/fsfs-reorg$(EXEEXT)
 	cd tools/server-side ; $(INSTALL_TOOLS) fsfs-stats$(EXEEXT) $(DESTDIR)$(toolsdir)/fsfs-stats$(EXEEXT)
