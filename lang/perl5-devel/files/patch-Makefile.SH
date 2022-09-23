Allow customisation of shrpldflags.

--- Makefile.SH.orig	2022-06-19 19:29:35 UTC
+++ Makefile.SH
@@ -40,7 +40,6 @@ linklibperl_nonshr=''
 pwd="`pwd`"
 linklibperl='$(LIBPERL)'
 linklibperl_nonshr=''
-shrpldflags='$(LDDLFLAGS)'
 ldlibpth=''
 DPERL_EXTERNAL_GLOB='-DPERL_EXTERNAL_GLOB'
 DPERL_IS_MINIPERL='-DPERL_IS_MINIPERL'
@@ -924,7 +923,7 @@ $(LIBPERL): $& $(perllib_dep) $(DYNALOADER) $(LIBPERLE
 	true)
 		$spitshell >>$Makefile <<'!NO!SUBS!'
 	rm -f $@
-	$(LD) -o $@ $(SHRPLDFLAGS) $(perllib_objs) $(DYNALOADER) $(libs)
+	$(LD) -o $@ $(SHRPLDFLAGS) -Wl,--allow-multiple-definition $(perllib_objs) $(DYNALOADER) $(libs)
 !NO!SUBS!
 		case "$osname" in
 		aix)
@@ -1015,7 +1014,7 @@ lib/buildcustomize.pl: $& $(miniperl_dep) write_buildc
 			$spitshell >>$Makefile <<'!NO!SUBS!'
 lib/buildcustomize.pl: $& $(miniperl_dep) write_buildcustomize.pl
 	-@rm -f miniperl.xok
-	$(CC) $(CLDFLAGS) -o $(MINIPERL_EXE) \
+	$(CC) $(CLDFLAGS) -Wl,--allow-multiple-definition -o $(MINIPERL_EXE) \
 	    $(miniperl_objs) $(libs)
 	$(LDLIBPTH) ./miniperl$(HOST_EXE_EXT) -w -Ilib -Idist/Exporter/lib -MExporter -e '<?>' || sh -c 'echo >&2 Failed to build miniperl.  Please run make minitest; exit 1'
 	$(MINIPERL) -f write_buildcustomize.pl
