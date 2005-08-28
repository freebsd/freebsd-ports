--- src/mkinclud.mak.orig	Thu Jun 23 00:00:00 2005
+++ src/mkinclud.mak	Wed Aug  3 18:25:22 2005
@@ -226,7 +226,7 @@
 # generate makefile to deal with variable list of targets,
 # invoke it to generate and compile character mapping tables:
 mkcharmaps:
-	CC=$(CC) OPT=$(OPT) ./mkmakchr > charmaps/makefile
+	CC=$(CC) OPT="$(OPT)" ./mkmakchr > charmaps/makefile
 	$(MAKE) -f charmaps/makefile
 
 
@@ -239,7 +239,7 @@
 
 # define generic rule to generate and compile character mapping tables:
 charmaps/%.o: charmaps/%.map mkchrtab charmaps.h
-	CC=$(CC) OPT=$(OPT) ./mkchrtab $<
+	CC=$(CC) OPT="$(OPT)" ./mkchrtab $<
 
 
 #############################################################################
@@ -356,8 +356,7 @@
 	mkdir -p $(lrundir)
 	$(INSTALL) ../usrshare/* $(lrundir)
 	mkdir -p $(lmandir)/man1
-	$(INSTALL) --mode=+r,u+w ../man/mined.1 $(lmandir)/man1
-	if (ls $(lmandir)/man1/*.gz && type gzip) > /dev/null 2>&1; then gzip -f $(lmandir)/man1/mined.1; fi
+	$(BSD_INSTALL_MAN) ../man/mined.1 $(lmandir)/man1
 
 # /opt installation:
 optinstall:	mined help man ${INSTALLTARGET}
