--- lib/Module/Build/ModuleInfo.pm.orig	Sun Jul 16 04:42:38 2006
+++ lib/Module/Build/ModuleInfo.pm	Sun Jul 16 16:16:22 2006
@@ -286,12 +286,16 @@
 		};
 
   local $^W;
+  my $old_version = \&UNIVERSAL::VERSION;
+  eval {require version};
   # Try and get the $VERSION
   my $result = eval $eval;
+  * UNIVERSAL::VERSION = $old_version;
   warn "Error evaling version line '$eval' in $self->{filename}: $@\n" if $@;
 
   # Bless it into our own version class
-  $result = Module::Build::Version->new($result);
+  #$result = Module::Build::Version->new($result);
+  $result = $result->numify if UNIVERSAL::isa($result, 'version');
 
   return $result;
 }
