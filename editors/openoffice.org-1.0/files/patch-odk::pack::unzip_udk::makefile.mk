--- ../odk/pack/unzip_udk/makefile.mk.orig	Tue Mar  5 15:35:31 2002
+++ ../odk/pack/unzip_udk/makefile.mk	Tue Mar  5 15:36:15 2002
@@ -30,7 +30,7 @@
 .IF "$(GUI)"=="WNT"
 	unzip -q -d . $(UDKNAME)
 .ELSE
-	gzip -df < $(UDKNAME).tar.gz | tar -xvf -
+	tar -xzf $(UDKNAME).tar.gz
 .ENDIF
 	+-$(RENAME) $(UDKNAME) 		$(ODKNAME)
 	+rm -f $(ODKNAME)$/settings$/dk.mk
