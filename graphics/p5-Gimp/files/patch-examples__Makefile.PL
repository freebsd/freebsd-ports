--- examples/Makefile.PL.orig	2014-06-19 14:53:12 UTC
+++ examples/Makefile.PL
@@ -48,7 +48,8 @@
   my $dest = '$(GIMP_PLUGINS)/'.basename($plugin);
   <<EOF;
 $dest : $src
-	\$(NOECHO) \$(GTINSTALL) "$src"
+	\$(NOECHO) \$(MKPATH) \$(GIMP_PLUGINS)
+	\$(CP) "$src" "$dest"
 
 EOF
 }
@@ -73,7 +74,7 @@
    <<EOF;
 
 INST_PLUGINS = ../blib/plugins
-GIMP_PLUGINS = $cfg{gimpplugindir}
+GIMP_PLUGINS = \$(DESTDIR)$cfg{gimpplugindir}
 
 \$(INST_PLUGINS)\$(DFSEP).exists :: Makefile.PL
 	\$(NOECHO) \$(MKPATH) \$(INST_PLUGINS)
