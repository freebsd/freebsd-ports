--- Virtual.pm.orig	Sun Jun 27 20:45:37 2004
+++ Virtual.pm	Sun Jun 27 20:46:10 2004
@@ -18,7 +18,7 @@
 use Carp;
 use IO::File;
 
-our $VERSION = '0.04';
+use vars qw($VERSION); $VERSION = '0.04';
 
 # login: 
 
