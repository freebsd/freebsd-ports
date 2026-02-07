--- Makefile.PL.orig	Wed Feb 16 14:14:05 2000
+++ Makefile.PL	Tue Mar  1 14:10:35 2005
@@ -19,6 +19,10 @@
         'PerlConfig.pm' => '$(INST_LIBDIR)/PerlConfig.pm'
     },
 
+    'MAN3PODS' => {
+	'PerlConfig.pm' => '$(INST_MAN3DIR)/Parse::PerlConfig.$(MAN3EXT)'
+    },
+
 
     # This may not be portable, as I found the TESTS attribute in
     # ExtUtils::MM_Unix.pm's source.  However, it seems cleaner and
