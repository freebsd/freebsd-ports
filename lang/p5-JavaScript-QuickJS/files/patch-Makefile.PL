--- Makefile.PL.orig	2024-02-12 06:16:14 UTC
+++ Makefile.PL
@@ -13,24 +13,11 @@ use Cwd;
 use File::Which;
 use Cwd;
 
-my $GMAKE_PATH = _find_gmake();
-
-if (!$GMAKE_PATH) {
-    die "GNU Make ($Config{'gmake'}) is required.\n";
-}
-elsif (!-x $GMAKE_PATH) {
-    if ($!) {
-        die "Failed to detect if GNU Make ($GMAKE_PATH) is executable: $!\n";
-    }
-
-    die "GNU Make ($GMAKE_PATH) is not executable.\n";
-}
-
 my $ATOMIC_ENV_KEY = 'JS_QUICKJS_LINK_LIBATOMIC';
 
 my $PERL_QJS_MAKEFILE_PATH = File::Spec->catfile( Cwd::getcwd(), 'Makefile.quickjs');
 
-my $libpath = File::Spec->catfile('quickjs', 'libquickjs.a');
+my $libpath = File::Spec->catfile('%%LOCALBASE%%/lib', 'libquickjs.so');
 
 # quickjs needs these; pre-5.20 perls didn’t include libpthread.
 # Note that MSWin32, if given these, will try to compile them statically
@@ -42,8 +29,6 @@ if (_need_librt()) {
     push @libs, '-lrt';
 }
 
-_tweak_for_os();
-
 if (!_stdatomic_h_exists()) {
     _avoid_stdatomic_h();
 }
@@ -54,13 +39,6 @@ mkdir( File::Spec->catdir( qw(quickjs .obj) ) );
 #
 mkdir( File::Spec->catdir( qw(quickjs .obj) ) );
 
-make_libquickjs_makefile();
-
-# RaspiOS needs this; others may, too:
-if (_should_link_libatomic()) {
-    push @libs, '-latomic';
-}
-
 WriteMakefile(
     NAME              => 'JavaScript::QuickJS',
     VERSION_FROM      => 'lib/JavaScript/QuickJS.pm', # finds $VERSION
@@ -71,7 +49,7 @@ WriteMakefile(
         ],
       ) : ()
     ),
-    INC               => '-Wall --std=c99 -I.',
+    INC               => '-Wall --std=c99 -I. -I%%LOCALBASE%%/include',
     LICENSE           => "perl_5",
 
     PMLIBDIRS => ['lib'],
@@ -224,8 +202,6 @@ sub _should_link_libatomic {
     my $needs_libatomic;
 
     eval {
-        system $GMAKE_PATH, '-C', 'quickjs', '-f', $PERL_QJS_MAKEFILE_PATH, $rel_objpath;
-        die if $?;
         my $objbin = File::Slurper::read_binary($objpath);
 
         $needs_libatomic = -1 != index($objbin, '__atomic_fetch_sub_');
@@ -315,18 +291,5 @@ use Config;
 package MY;
 
 use Config;
-
-sub postamble {
-
-    # QuickJS requires GNU make.
-    my $make = ($^O =~ m<bsd>i) ? $GMAKE_PATH : '$(MAKE)';
-
-    # The leading “+” is to ensure that parallel builds work properly.
-    return <<"MAKE_FRAG"
-
-$libpath:
-\t+$make -C quickjs -f '$PERL_QJS_MAKEFILE_PATH' libquickjs.a
-MAKE_FRAG
-}
 
 1;
