--- lib/Parse/Template.pm.orig	Thu Sep 23 12:16:28 1999
+++ lib/Parse/Template.pm	Fri Aug 20 16:03:23 2004
@@ -1,4 +1,4 @@
-use strict
+use strict;
 require 5.004;
 package Parse::Template;
 $Parse::Template::VERSION = '0.32';
@@ -132,7 +132,7 @@
   }
   # evaluated expressions are not always available in (caller(1))[6];	
   if (defined($1) and $1 ne '') {
-    $expr = $1;			# what is the  template expression?
+    my $expr = $1;			# what is the  template expression?
     { package DB;		# what is the part name?
       @DB::caller = caller(2);	# why is this needed? /ee?
       @DB::caller = caller(1);
