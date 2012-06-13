--- ./Makefile.PL.orig	2012-06-13 13:15:56.266358713 +0200
+++ ./Makefile.PL	2012-06-13 13:16:02.263508135 +0200
@@ -5,10 +5,10 @@
     VERSION   => '2.1.2',
     EXE_FILES => [ <bin/*> ],
     MAN1PODS  => {
-      'docs/percona-toolkit.pod' => 'blib/man1/percona-toolkit.1p',
+      'docs/percona-toolkit.pod' => 'blib/man1/percona-toolkit.1',
       map {
          (my $name = $_) =~ s/^bin.//;
-         $_ => "blib/man1/$name.1p";
+         $_ => "blib/man1/$name.1";
       } <bin/*>
     },
     MAN3PODS     => {}, # man(3) pages are for C libs
