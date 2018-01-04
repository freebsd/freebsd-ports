--- Makefile.PL.orig	2017-12-16 18:29:36 UTC
+++ Makefile.PL
@@ -5,12 +5,12 @@ WriteMakefile(
     VERSION   => '3.0.5',
     EXE_FILES => [ <bin/*> ],
     MAN1PODS  => {
-      'docs/percona-toolkit.pod' => 'blib/man1/percona-toolkit.1p',
+      'docs/percona-toolkit.pod' => 'blib/man1/percona-toolkit.1',
       map {
          (my $name = $_) =~ s/^bin.//;
          my $file_name = $_;
          if ( $file_name !~ m/mongo/ ) {
-             $_ => "blib/man1/$name.1p";
+             $_ => "blib/man1/$name.1";
         }
       } <bin/*>
     },
