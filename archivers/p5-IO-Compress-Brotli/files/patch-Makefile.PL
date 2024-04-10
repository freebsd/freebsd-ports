--- Makefile.PL.orig	2023-10-31 00:35:30 UTC
+++ Makefile.PL
@@ -1,6 +1,5 @@ use ExtUtils::MakeMaker;
 use 5.014000;
 use ExtUtils::MakeMaker;
-use Alien::cmake3;
 use File::Spec::Functions qw/catfile/;
 use Config;
 
@@ -32,14 +31,6 @@ WriteMakefile(
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
-	MYEXTLIB         => $myextlib,
 	clean            => { FILES => "brotli/Makefile $myextlib brotli/CMakeCache.txt brotli/CMakeFiles/* brotli/CTestTestfile.cmake brotli/DartConfiguration.tcl brotli/brotli* brotli/cmake_install.cmake brotli/libbrotlicommon.pc brotli/libbrotlidec.pc brotli/libbrotlienc.pc" },
 	META_ADD         => {
 		dynamic_config => 0,
@@ -48,12 +39,3 @@ WriteMakefile(
 		},
 	}
 );
-
-sub MY::postamble {
-    my @dirs = Alien::cmake3->bin_dir;
-    my $cmake = defined $dirs[0] ? catfile($dirs[0] , Alien::cmake3->exe) : Alien::cmake3->exe;
-'
-$(MYEXTLIB): brotli/CMakeLists.txt
-	cd brotli && "' . $cmake . '"' . $cmake_options . ' -DCMAKE_MAKE_PROGRAM=$(MAKE) -DBUILD_SHARED_LIBS=OFF -DCMAKE_POSITION_INDEPENDENT_CODE=ON -DCMAKE_BUILD_TYPE=Release -DCMAKE_INSTALL_PREFIX=./installed . && $(MAKE)
-'
-}
