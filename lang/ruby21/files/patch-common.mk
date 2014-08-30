--- common.mk.orig	2014-08-22 13:08:58.634283881 +0000
+++ common.mk	2014-08-22 13:09:13.890283009 +0000
@@ -204,7 +204,7 @@
 Doxyfile: $(srcdir)/template/Doxyfile.tmpl $(PREP) $(srcdir)/tool/generic_erb.rb $(RBCONFIG)
 	$(ECHO) generating $@
 	$(Q) $(MINIRUBY) $(srcdir)/tool/generic_erb.rb -o $@ $(srcdir)/template/Doxyfile.tmpl \
-	--srcdir="$(srcdir)" --miniruby="$(BASERUBY)"
+	--srcdir="$(srcdir)" --miniruby="$(MINIRUBY)"
 
 program: showflags $(PROGRAM)
 wprogram: showflags $(WPROGRAM)
