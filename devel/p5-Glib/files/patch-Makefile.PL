Fix runtime starting with Perl 5.40 by adding back Perl's ccflqgs to Glib's
ccflags when building.

--- Makefile.PL.orig	2025-05-17 07:25:21 UTC
+++ Makefile.PL
@@ -183,7 +183,7 @@ our $glib = ExtUtils::Depends->new ('Glib');
 # add -I. and -I./build to the include path so we can find our own files.
 # this will be inherited by dependant modules, so they can find their
 # generated files.
-$glib->set_inc (' -I. ' . $glibcfg{cflags} . ' ' . $gthreadcfg{cflags});
+$glib->set_inc (' -I. ' . $glibcfg{cflags} . ' ' . $gthreadcfg{cflags} . ' ' . $Config::Config{ccflags});
 $glib->set_libs ($glibcfg{libs} . ' ' . $gthreadcfg{libs});
 my $cwd = cwd();
 $glib->add_typemaps (map {File::Spec->catfile($cwd,$_)} 'typemap');
