--- Makefile.PL.orig	Sun Jul 18 02:16:55 2004
+++ Makefile.PL	Mon Jul 19 10:51:54 2004
@@ -21,7 +21,7 @@
 
    if ($key eq 'LIBS' || $key eq 'INC')
    {
-      delete $ARGV[$i];
+      undef $ARGV[$i];
    }
 
    $i++;
@@ -38,7 +38,7 @@
 
 print 'Checking for iconv ... ';
 
-if (linktest($config{LIBS}, $config{INC}))
+if (1)
 {
    $ok = 1;
    print "ok (iconv apparently in libc)\n";
@@ -86,13 +86,13 @@
       (ABSTRACT_FROM => 'Iconv.pm', # retrieve abstract from module
        AUTHOR        => 'Michael Piotrowski <mxp@dynalabs.de>') : ()),
     'LIBS'		=> $config{LIBS},
-    'DEFINE'		=> "@DEFINE",
     'INC'		=> $config{INC},
     'dist'              => {COMPRESS => 'gzip', SUFFIX => 'gz'},
 );
 
 ###############################################################################
 
+__END__
 sub linktest
 {
    my $libs = shift;
