--- Virtual/Plain.pm.orig	Sun Jun 27 20:46:26 2004
+++ Virtual/Plain.pm	Sun Jun 27 20:47:17 2004
@@ -20,11 +20,11 @@
 use User::grent;
 use IO::File;
 
-our $AUTOLOAD;
-our $VERSION = '0.04';
-our @ISA = qw(Filesys::Virtual);
+use vars qw($AUTOLOAD $VERSION @ISA %_fields);
+$VERSION = '0.04';
+@ISA = qw(Filesys::Virtual);
 
-our %_fields = (
+%_fields = (
 	 'cwd'       => '1',
 	 'root_path' => '1',
 	 'home_path' => '1',
