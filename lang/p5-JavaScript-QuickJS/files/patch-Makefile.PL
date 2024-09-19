--- Makefile.PL.orig	2024-02-12 06:16:14 UTC
+++ Makefile.PL
@@ -13,7 +13,7 @@ use Cwd;
 use File::Which;
 use Cwd;
 
-my $GMAKE_PATH = _find_gmake();
+my $GMAKE_PATH = "/usr/bin/make";
 
 if (!$GMAKE_PATH) {
     die "GNU Make ($Config{'gmake'}) is required.\n";
@@ -30,7 +30,7 @@ my $PERL_QJS_MAKEFILE_PATH = File::Spec->catfile( Cwd:
 
 my $PERL_QJS_MAKEFILE_PATH = File::Spec->catfile( Cwd::getcwd(), 'Makefile.quickjs');
 
-my $libpath = File::Spec->catfile('quickjs', 'libquickjs.a');
+my $libpath = File::Spec->catfile('%%LOCALBASE%%/lib', 'libquickjs.so');
 
 # quickjs needs these; pre-5.20 perls didn’t include libpthread.
 # Note that MSWin32, if given these, will try to compile them statically
@@ -42,8 +42,6 @@ if (_need_librt()) {
     push @libs, '-lrt';
 }
 
-_tweak_for_os();
-
 if (!_stdatomic_h_exists()) {
     _avoid_stdatomic_h();
 }
@@ -54,13 +52,6 @@ mkdir( File::Spec->catdir( qw(quickjs .obj) ) );
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
@@ -71,7 +62,7 @@ WriteMakefile(
         ],
       ) : ()
     ),
-    INC               => '-Wall --std=c99 -I.',
+    INC               => '-Wall --std=c99 -I. -I%%LOCALBASE%%/include',
     LICENSE           => "perl_5",
 
     PMLIBDIRS => ['lib'],
@@ -325,7 +316,6 @@ $libpath:
     return <<"MAKE_FRAG"
 
 $libpath:
-\t+$make -C quickjs -f '$PERL_QJS_MAKEFILE_PATH' libquickjs.a
 MAKE_FRAG
 }
 
