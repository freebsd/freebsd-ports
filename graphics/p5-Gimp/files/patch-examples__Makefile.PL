--- examples/Makefile.PL.orig	2016-05-01 01:47:52 UTC
+++ examples/Makefile.PL
@@ -47,7 +47,8 @@ sub install_plugin_target {
   my $dest = '$(GIMP_PLUGINS)/'.basename($plugin);
   <<EOF;
 $dest : $src
-	\$(NOECHO) \$(GTINSTALL) "$src"
+	\$(NOECHO) \$(MKPATH) \$(GIMP_PLUGINS)
+	\$(CP) "$src" "$dest"
 
 EOF
 }
@@ -73,7 +74,7 @@ undef &MY::postamble; # suppress warning
    <<EOF;
 
 INST_PLUGINS = ../blib/plugins
-GIMP_PLUGINS = $plugindir
+GIMP_PLUGINS = \$(DESTDIR)$plugindir
 
 \$(INST_PLUGINS)\$(DFSEP).exists :: Makefile.PL
 	\$(NOECHO) \$(MKPATH) \$(INST_PLUGINS)
