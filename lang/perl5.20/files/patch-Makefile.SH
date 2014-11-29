--- Makefile.SH.orig	2014-09-14 11:30:59 UTC
+++ Makefile.SH
@@ -838,7 +838,7 @@ $(LIBPERL): $& $(obj) $(DYNALOADER) $(LI
 	true)
 		$spitshell >>$Makefile <<'!NO!SUBS!'
 	rm -f $@
-	$(LD) -o $@ $(SHRPLDFLAGS) $(obj) $(DYNALOADER) $(libs)
+	$(LD) -o $@ $(SHRPLDFLAGS) -Wl,-soname,$(LIBPERL) $(obj) $(DYNALOADER) $(libs)
 !NO!SUBS!
 		case "$osname" in
 		aix)
