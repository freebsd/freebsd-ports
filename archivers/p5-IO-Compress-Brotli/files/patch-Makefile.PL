--- Makefile.PL.orig	2023-10-25 00:42:06 UTC
+++ Makefile.PL
@@ -1,6 +1,5 @@
 use 5.014000;
 use ExtUtils::MakeMaker;
-use Alien::cmake3;
 use File::Spec::Functions qw/catfile/;
 
 WriteMakefile(
@@ -17,14 +16,6 @@ WriteMakefile(
 		'Getopt::Long'  => '0',
 		'Time::HiRes'   => '0',
 	},
-	CONFIGURE_REQUIRES   => {
-		'Alien::cmake3' => '0',
-	},
-	BUILD_REQUIRES   => {
-		'Alien::cmake3' => '0',
-	},
-	INC              => '-Ibrotli/c/include',
-	MYEXTLIB         => 'brotli/libbrotlienc.so.1.1.0 brotli/libbrotlidec.so.1.1.0 brotli/libbrotlicommon.so.1.1.0',
 	clean            => { FILES => 'brotli/Makefile brotli/libbrotlienc.so* brotli/libbrotlidec.so* brotli/libbrotlicommon.so* brotli/CMakeCache.txt brotli/CMakeFiles/* brotli/CTestTestfile.cmake brotli/DartConfiguration.tcl brotli/brotli brotli/cmake_install.cmake brotli/libbrotlicommon.pc brotli/libbrotlidec.pc brotli/libbrotlienc.pc' },
 	META_ADD         => {
 		dynamic_config => 0,
@@ -33,12 +24,3 @@ WriteMakefile(
 		},
 	}
 );
-
-sub MY::postamble {
-    my @dirs = Alien::cmake3->bin_dir;
-    my $cmake = defined $dirs[0] ? catfile($dirs[0] , Alien::cmake3->exe) : Alien::cmake3->exe;
-'
-$(MYEXTLIB): brotli/CMakeLists.txt
-	cd brotli && ' . $cmake . ' -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./installed . && make
-'
-}
