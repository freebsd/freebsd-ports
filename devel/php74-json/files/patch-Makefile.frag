--- Makefile.frag.orig	2020-03-23 21:54:17 UTC
+++ Makefile.frag
@@ -1,5 +1,5 @@
 $(srcdir)/json_scanner.c: $(srcdir)/json_scanner.re
-	@$(RE2C) $(RE2C_FLAGS) -t $(srcdir)/php_json_scanner_defs.h --no-generation-date -bci -o $@ $(srcdir)/json_scanner.re
+	$(LOCALBASE)/bin/re2c $(RE2C_FLAGS) -t $(srcdir)/php_json_scanner_defs.h --no-generation-date -bci -o $@ $(srcdir)/json_scanner.re
 
 $(srcdir)/json_parser.tab.c: $(srcdir)/json_parser.y
 	@$(YACC) --defines -l $(srcdir)/json_parser.y -o $@
