Index: lib/mkmf.rb
===================================================================
RCS file: /src/ruby/lib/mkmf.rb,v
retrieving revision 1.116
diff -u -1 -r1.116 mkmf.rb
--- lib/mkmf.rb	14 Nov 2002 13:51:19 -0000	1.116
+++ lib/mkmf.rb	22 Nov 2002 12:38:13 -0000
@@ -688,7 +688,6 @@
   mfile.print %{
-all:		$(DLLIB)
+CLEANLIBS     = "$(TARGET).{lib,exp,il?,tds,map}" $(DLLIB)
+CLEANOBJS     = "*.{#{$OBJEXT},#{$LIBEXT},s[ol],pdb,bak}"
 
-clean::
-		@$(RM) "$(TARGET).{lib,exp,il?,tds,map}" $(DLLIB)
-		@$(RM) "*.{#{$OBJEXT},#{$LIBEXT},s[ol],pdb,bak}"
+all:		$(DLLIB)
 }
@@ -850,6 +849,6 @@
 CLEANINGS = "
-clean::
-		@$(RM) $(CLEANFILES)
+clean:
+		@$(RM) $(CLEANLIBS) $(CLEANOBJS) $(CLEANFILES)
 
-distclean::	clean
+distclean:	clean
 		@$(RM) Makefile extconf.h conftest.* mkmf.log
@@ -857,3 +856,3 @@
 
-realclean::	distclean
+realclean:	distclean
 "
