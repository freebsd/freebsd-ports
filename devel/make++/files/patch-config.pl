--- ./config.pl.orig	2014-08-05 05:06:18.000000000 -0400
+++ ./config.pl	2014-08-05 05:07:12.000000000 -0400
@@ -127,7 +127,7 @@
 	rm -rf $(VERSION)
 
 install: all
-	$(PERL) install.pl $(BINDIR) $(DATADIR) $(MANDIR) $(HTMLDIR) $(FINDBIN) $(DESTDIR)
+	$(PERL) install.pl $(BINDIR) $(DATADIR) $(MANDIR) $(HTMLDIR) $(FINDBIN) $(DESTDIR)$(PREFIX)
 
 .PHONY: all distribution install test testall
 ];
