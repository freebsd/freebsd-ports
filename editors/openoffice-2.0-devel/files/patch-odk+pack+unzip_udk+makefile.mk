--- ../odk/pack/unzip_udk/makefile.mk.orig	Thu Aug  8 09:28:10 2002
+++ ../odk/pack/unzip_udk/makefile.mk	Fri Oct 18 20:14:46 2002
@@ -44,9 +44,15 @@
 .ELSE
 	$(GNUCOPY) -p $(UDKPATH) .
 	$(GNUCOPY) -p $(ODKDOCPATH) .
+.IF "$(OS)"=="FREEBSD"
+	tar -xzf $(UDKZIPPREFIX).tar.gz
+	+-$(RENAME) $(UDKNAME) $(ODKNAME)
+	tar -xzf $(ODKDOCNAME).tar.gz
+.ELSE
 	gzip -df < $(UDKZIPPREFIX).tar.gz | tar -xvf -
 	+-$(RENAME) $(UDKNAME) $(ODKNAME)
 	gzip -df < $(ODKDOCNAME).tar.gz | tar -xvf -
+.ENDIF
 .ENDIF
 .IF "$(BUILD_SOSL)"!=""
 # for OpenOffice build rename to PRODUCT_NAME
