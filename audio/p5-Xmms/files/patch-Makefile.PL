--- Makefile.PL.orig	Mon Dec 11 01:07:06 2000
+++ Makefile.PL	Mon Dec 11 01:10:55 2000
@@ -11,16 +11,4 @@
 		         'Term::ANSIColor'    => 0,
 		         'MPEG::MP3Info'    => 0,
 		      },
-    'macro' => {
-	  CVSROOT => 'modperl.com:/local/cvs_repository',
-    },
 );
-
-sub MY::postamble { 
-    return <<'EOF'; 
-
-cvs_tag :
-	cvs -d $(CVSROOT) tag v$(VERSION_SYM) . 
-	@echo update lib/Xmms.pm VERSION now 
-EOF
-} 
