--- Relationship.pm.orig	Mon Mar  1 16:48:45 2004
+++ Relationship.pm	Sun Apr  4 22:30:41 2004
@@ -1,9 +1,8 @@
 package Class::DBI::Loader::Relationship;
-use 5.006;
 use strict;
-use warnings;
-our $VERSION = '1.2';
-our $DEBUG = 0;
+use vars qw($VERSION $DEBUG);
+$VERSION = '1.2';
+$DEBUG = 0;
 
 1;
 
@@ -82,7 +81,7 @@
                "$via_c->has_a(".to_S($to)." => $to_c)\n".
                "$from_c->$method($mapper => [ $via_c => ".to_S($to)." ])\n".
                "$to_c->has_many(".to_PL($from)." => [ $via_c => ".to_S($from)." ])\n"
-        if $DEBUG;
+        if $Class::DBI::Loader::Relationship::DEBUG;
 
         $via_c->has_a(to_S($from) => $from_c);
         $via_c->has_a(to_S($to) => $to_c);
@@ -92,7 +91,7 @@
     } 
     return "$from_c->$method($mapper => $to_c);\n".
            ($method ne "has_a" && "$to_c->has_a(".to_S($from)." => $from_c);\n") 
-           if $DEBUG;
+           if $Class::DBI::Loader::Relationship::DEBUG;
     $from_c->$method($mapper => $to_c);
     $to_c->has_a(to_S($from) => $from_c) unless $method eq "has_a";
 }
