--- inc/My/Builder.pm.orig	2025-05-03 13:20:23 UTC
+++ inc/My/Builder.pm
@@ -8,7 +8,7 @@ use IO::File qw();
 use File::Slurp qw(read_file write_file);
 use File::Spec::Functions qw(catdir catfile rootdir);
 use IO::File qw();
-use Module::Build '0.36' => qw();
+use Module::Build qw();
 use autodie qw(:all move read_file write_file);
 use parent 'Module::Build';
 use Locale::Maketext::Extract;
