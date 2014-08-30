--- common.mk.orig	2014-08-22 13:03:44.855620685 +0000
+++ common.mk	2014-08-22 13:04:00.299306606 +0000
@@ -206,7 +206,7 @@
 Doxyfile: $(srcdir)/template/Doxyfile.tmpl $(PREP) $(srcdir)/tool/generic_erb.rb $(RBCONFIG)
 	$(ECHO) generating $@
 	$(Q) $(MINIRUBY) $(srcdir)/tool/generic_erb.rb -o $@ $(srcdir)/template/Doxyfile.tmpl \
-	--srcdir="$(srcdir)" --miniruby="$(BASERUBY)"
+	--srcdir="$(srcdir)" --miniruby="$(MINIRUBY)"
 
 program: showflags $(PROGRAM)
 wprogram: showflags $(WPROGRAM)
