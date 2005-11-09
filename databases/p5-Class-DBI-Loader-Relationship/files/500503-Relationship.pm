--- Relationship.pm.orig	Wed Nov  9 02:28:38 2005
+++ Relationship.pm	Wed Nov  9 14:27:27 2005
@@ -1,9 +1,8 @@
 package Class::DBI::Loader::Relationship;
-use 5.006;
 use strict;
-use warnings;
-our $VERSION = '1.3';
-our $DEBUG = 0;
+use vars qw($VERSION $DEBUG);
+$VERSION = '1.3';
+$DEBUG = 0;
 
 1;
 
@@ -96,7 +95,7 @@
                "$via_c->has_a(".to_S($to)." => $to_c)\n".
                "$from_c->$method($mapper => [ $via_c => ".to_S($to)." ])\n".
                "$to_c->has_many(".to_PL($from)." => [ $via_c => ".to_S($from)." ])\n"
-        if $DEBUG;
+        if $Class::DBI::Loader::Relationship::DEBUG;
 
         $via_c->has_a(to_S($from) => $from_c);
         $via_c->has_a(to_S($to) => $to_c);
@@ -106,7 +105,7 @@
     } 
     return "$from_c->$method($mapper => $to_c);\n".
            ($method ne "has_a" && "$to_c->has_a(".to_S($from)." => $from_c);\n") 
-           if $DEBUG;
+           if $Class::DBI::Loader::Relationship::DEBUG;
     $from_c->$method($mapper => $to_c);
     $to_c->has_a(to_S($from) => $from_c) unless $method eq "has_a";
 }
