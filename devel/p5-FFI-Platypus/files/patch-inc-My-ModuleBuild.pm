--- inc/My/ModuleBuild.pm.orig	2017-03-23 22:26:13 UTC
+++ inc/My/ModuleBuild.pm
@@ -3,7 +3,6 @@ package My::ModuleBuild;
 use strict;
 use warnings;
 use 5.008001;
-use Alien::FFI;
 use My::LibTest;
 use My::AutoConf;
 use My::Dev;
@@ -23,8 +22,6 @@ sub new
 
   $args{c_source}             = 'xs';  
   $args{include_dirs}         = 'include';
-  $args{extra_compiler_flags} = Alien::FFI->cflags;
-  $args{extra_linker_flags}   = Alien::FFI->libs;
   $args{requires}->{'Math::Int64'} = '0.34' if $ENV{FFI_PLATYPUS_DEBUG_FAKE32} || $Config{uvsize} < 8;
 
   if($^O eq 'MSWin32' && $Config{cc} =~ /cl(\.exe)?$/i)
@@ -94,15 +91,6 @@ sub new
     $ccflags = "@ccflags";
   }
 
-  # on some configurations (eg. Solaris 64 bit, Strawberry Perl)
-  # -L flags are included in the lddlflags configuration, but we
-  # need to make sure OUR -L comes first
-  my @libdirflags = grep /^-L/, shellwords(Alien::FFI->libs);
-  if(@libdirflags)
-  {
-    $lddlflags = join ' ', @libdirflags, $lddlflags;
-  }
-  
   if($^O eq 'MSWin32')
   {
     # needed by My/Probe.pm on any MSWin32 platform
