--- dist.mk.orig	Sat Mar  1 06:20:47 2003
+++ dist.mk	Mon Jun 14 23:17:43 2004
@@ -35,7 +35,9 @@
 	rm -rf $(PACKAGE)-$(VERSION)
 	rm -f $(MP_SRC_DIST)
 	mkdir $(PACKAGE)-$(VERSION)
-	tar -cf - -X mp-dist.ex $(EXTRA_DIST) -C .. . | \
+	tar -cf - -X mp-dist.ex $(EXTRA_DIST) | \
+	  tar -xf - -C $(PACKAGE)-$(VERSION)
+	tar -cf - -X mp-dist.ex -C .. . | \
 	  tar -xf - -C $(PACKAGE)-$(VERSION)
 	if [ -n "$(MP_BUNDLE)" -a -r "$(MAKEPLUS_HOME)/makeplus.tar.gz" ]; \
 	then \
