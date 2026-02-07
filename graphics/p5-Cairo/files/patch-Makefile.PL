Propagate Perl's ccflags to make sure it uses Perl's headers the same way as
Perl itself.

--- Makefile.PL.orig	2021-01-19 17:26:47 UTC
+++ Makefile.PL
@@ -612,7 +612,7 @@ my $dep = ExtUtils::Depends->new ('Cairo');
 push @typemaps, 'cairo-perl.typemap';
 
 my $dep = ExtUtils::Depends->new ('Cairo');
-$dep->set_inc ('-I. -I'.$autogen_dir.' '.$cairo_cfg{cflags});
+$dep->set_inc ('-I. -I'.$autogen_dir.' '.$cairo_cfg{cflags}.' '.$Config::Config{ccflags});
 $dep->set_libs ($cairo_cfg{libs});
 $dep->add_xs (@xs_files);
 $dep->add_c (qw/cairo-perl-enums.c cairo-perl-flags.c/);
