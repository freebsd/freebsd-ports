--- Ordered.pm.orig	Sat Jul 17 16:57:11 2004
+++ Ordered.pm	Sun Aug 29 11:46:19 2004
@@ -1,10 +1,8 @@
 package Module::Pluggable::Ordered;
-use 5.006;
 use strict;
-use warnings;
 require Module::Pluggable;
 use UNIVERSAL::require;
-our $VERSION = '1.2';
+use vars qw($VERSION); $VERSION = '1.2';
 
 sub import {
     my ($self, %args) = @_;
@@ -32,7 +30,7 @@
         $_->require for @plugins;
 
         my $order_name = "${name}_order";
-        for my $class (sort { $a->$order_name <=> $b->$order_name }
+        for my $class (sort { $a->$order_name() <=> $b->$order_name() }
                        grep { $_->can($order_name) }
                        @plugins) {
             $class->$name(@args);
