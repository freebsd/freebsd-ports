--- Makefile.SH.orig	2013-03-04 15:16:21 UTC
+++ Makefile.SH
@@ -795,7 +795,7 @@ $(LIBPERL): $& $(obj) $(DYNALOADER) $(LI
 	true)
 		$spitshell >>$Makefile <<'!NO!SUBS!'
 	rm -f $@
-	$(LD) -o $@ $(SHRPLDFLAGS) $(obj) $(DYNALOADER) $(libs)
+	$(LD) -o $@ $(SHRPLDFLAGS%%HOLDER%%) -Wl,-soname,$(LIBPERL:R) $(obj) $(DYNALOADER) $(libs)
 !NO!SUBS!
 		case "$osname" in
 		aix)
