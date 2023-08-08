--- Makefile.PL.orig	2022-11-28 18:41:57 UTC
+++ Makefile.PL
@@ -5,12 +5,12 @@ WriteMakefile(
     VERSION   => '3.5.0',
     EXE_FILES => [ <bin/*> ],
     MAN1PODS  => {
-      'docs/percona-toolkit.pod' => 'blib/man1/percona-toolkit.1p',
+      'docs/percona-toolkit.pod' => 'blib/man1/percona-toolkit.1',
       map {
          (my $name = $_) =~ s/^bin.//;
          my $file_name = $_;
          if ( ( $file_name !~ m/mongo/ ) || ( $file_name !~ m/pg/ ) ) {
-             $_ => "blib/man1/$name.1p";
+             $_ => "blib/man1/$name.1";
          }
       } <bin/*>
     },
