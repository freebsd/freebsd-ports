--- Makefile.SH.orig	2014-10-01 15:23:34 UTC
+++ Makefile.SH
@@ -805,7 +808,7 @@ $(LIBPERL): $& $(obj) $(DYNALOADER) $(LI
 	true)
 		$spitshell >>$Makefile <<'!NO!SUBS!'
 	rm -f $@
-	$(LD) -o $@ $(SHRPLDFLAGS) $(obj) $(DYNALOADER) $(libs)
+	$(LD) -o $@ $(SHRPLDFLAGS) -Wl,-soname,$(LIBPERL) $(obj) $(DYNALOADER) $(libs)
 !NO!SUBS!
 		case "$osname" in
 		aix)
