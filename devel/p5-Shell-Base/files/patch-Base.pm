--- Base.pm.orig        Mon Feb 23 21:03:44 2004
+++ Base.pm     Mon Feb 23 21:02:36 2004
@@ -16,7 +16,7 @@
             );

 use Carp qw(carp croak);
-use Env qw($PAGER $SHELL $COLUMNS);
+use Env qw(PAGER SHELL COLUMNS);
 use IO::File;
 use File::Basename qw(basename);
 use Term::Size qw(chars);

Unfortunately, this causes t/signature to fail because of a broken
checksum. Here's a patch for that:

