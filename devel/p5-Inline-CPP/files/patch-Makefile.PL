--- Makefile.PL.orig	2019-04-02 14:50:25 UTC
+++ Makefile.PL
@@ -10,7 +10,7 @@ my $CPP_Config_path = 'lib/Inline/CPP/Co
 
 my %PREREQ_PM = (
   'Inline'            => '0.78',
-  'Inline::C'         => '0.78_003', # supports 5.8.1
+  'Inline::C'         => '0.78', # supports 5.8.1
   'Parse::RecDescent' => '0',
   'Carp'              => '0',
   'Config'            => '0',
@@ -22,11 +22,6 @@ my $guess = ExtUtils::CppGuess->new;
 my @info = map $guess->$_,
   qw(compiler_command linker_flags iostream_fname cpp_flavor_defs);
 
-$info[0] = prompt("What C++ compiler would you like to use?", $info[0]);
-
-$info[1]
-  = prompt("What default libraries would you like to include?", $info[1]);
-
 configure_distribution(@info);
 
 WriteMakefile(
