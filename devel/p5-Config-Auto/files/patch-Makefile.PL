--- Makefile.PL.orig	Sun Sep 28 13:41:23 2003
+++ Makefile.PL	Sun Sep 28 13:42:32 2003
@@ -29,4 +29,9 @@
             AUTHOR           => 'Jos I. Boumans <kane@cpan.org>') 
         : ()
     ),
+
+    'MAN3PODS'	=> {
+       'lib/Config/Auto.pm'	=> '$(INST_MAN3DIR)/Config::Auto.$(MAN3EXT)',
+    },
+
 );
