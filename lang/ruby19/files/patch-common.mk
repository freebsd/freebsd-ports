--- common.mk.orig	2011-05-17 21:19:20.689620679 -0400
+++ common.mk	2011-05-17 21:19:28.688621223 -0400
@@ -96,7 +96,7 @@
 
 GOLFOBJS      = goruby.$(OBJEXT) golf_prelude.$(OBJEXT)
 
-PRELUDE_SCRIPTS = $(srcdir)/prelude.rb $(srcdir)/enc/prelude.rb $(srcdir)/gem_prelude.rb
+PRELUDE_SCRIPTS = $(srcdir)/prelude.rb $(srcdir)/enc/prelude.rb
 PRELUDES      = prelude.c miniprelude.c
 GOLFPRELUDES = golf_prelude.c
 
@@ -256,7 +256,7 @@
 install-capi: capi pre-install-capi do-install-capi post-install-capi
 pre-install-capi:: install-prereq
 do-install-capi: $(PREP)
-	$(INSTRUBY) --make="$(MAKE)" $(INSTRUBY_ARGS) --install=capi
+	@$(NULLCMD)
 post-install-capi::
 	@$(NULLCMD)
 
@@ -738,7 +738,6 @@
 	$(BASERUBY) -I$(srcdir) $(srcdir)/tool/compile_prelude.rb $(srcdir)/prelude.rb $@
 
 prelude.c: $(srcdir)/tool/compile_prelude.rb $(RBCONFIG) \
-	   $(srcdir)/lib/rubygems/defaults.rb $(srcdir)/lib/rubygems/custom_require.rb \
 	   $(PRELUDE_SCRIPTS) $(PREP)
 	$(COMPILE_PRELUDE) $(PRELUDE_SCRIPTS) $@
 
