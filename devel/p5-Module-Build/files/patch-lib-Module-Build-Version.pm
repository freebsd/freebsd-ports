--- lib/Module/Build/Version.pm.orig	Sun Jul 16 04:42:38 2006
+++ lib/Module/Build/Version.pm	Sun Jul 16 16:07:54 2006
@@ -1,5 +1,5 @@
 package Module::Build::Version;
-use base qw/version/;
+#use base qw/version/;
 
 use overload (
     '""' => \&stringify,
