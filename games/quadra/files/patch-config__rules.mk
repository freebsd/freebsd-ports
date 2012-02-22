--- ./config/rules.mk.orig	2009-06-19 04:36:47.000000000 +0000
+++ ./config/rules.mk	2012-02-17 20:57:40.683844559 +0000
@@ -41,7 +41,6 @@
 
 installdirs:
 	mkdir -p $(DESTDIR)$(bindir)
-	mkdir -p $(DESTDIR)$(libgamesdir)
 	mkdir -p $(DESTDIR)$(datagamesdir)
 	mkdir -p $(DESTDIR)$(datadir)/pixmaps
 
