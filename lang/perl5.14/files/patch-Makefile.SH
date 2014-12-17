--- Makefile.SH.orig	2012-12-19 12:25:23 UTC
+++ Makefile.SH
@@ -762,7 +762,7 @@ $(LIBPERL): $& $(obj) $(DYNALOADER) $(LI
 	true)
 		$spitshell >>$Makefile <<'!NO!SUBS!'
 	rm -f $@
-	$(LD) -o $@ $(SHRPLDFLAGS) $(obj) $(DYNALOADER) $(libs)
+	$(LD) -o $@ $(SHRPLDFLAGS%%HOLDER%%) -Wl,-soname,$(LIBPERL:R) $(obj) $(DYNALOADER) $(libs)
 !NO!SUBS!
 		case "$osname" in
 		aix)
