--- Makefile.PL.orig	Wed Jul 19 23:22:09 2006
+++ Makefile.PL	Thu Jul 20 10:29:00 2006
@@ -47,6 +47,8 @@
                        AUTHOR      => 'John Peacock <jpeacock@cpan.org>') :
                      ()
                    ), 
+		   MAN3PODS	   => 
+		       {'lib/version.pod' => 'blib/man3/version.3' },
 		   PM              => 
 		       {'lib/version.pm' => '$(INST_LIBDIR)/version.pm'},
 		   PL_FILES        => {},
