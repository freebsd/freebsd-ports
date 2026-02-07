--- Makefile.PL.orig	2013-05-12 15:18:54 UTC
+++ Makefile.PL
@@ -29,6 +29,11 @@ WriteMakefile1(
     LICENSE => 'perl',
     META_MERGE => {
         resources => {
+
+    'MAN3PODS'	=> {
+       'lib/Config/Auto.pm'	=> '$(INST_MAN3DIR)/Config::Auto.$(MAN3EXT)',
+    },
+
             repository => 'https://github.com/jib/config-auto',
         },
     },
