--- lib/Workflow/Factory.pm.orig	2009-01-26 18:07:31.000000000 +0300
+++ lib/Workflow/Factory.pm	2009-04-19 00:30:10.000000000 +0400
@@ -1,6 +1,6 @@
 package Workflow::Factory;
 
-# $Id: Factory.pm 454 2009-01-12 10:04:02Z jonasbn $
+# $Id: Factory.pm 471 2009-04-18 20:29:51Z jonasbn $
 
 use warnings;
 use strict;
@@ -11,7 +11,7 @@
 use Carp qw(croak);
 use English qw( -no_match_vars );
 
-$Workflow::Factory::VERSION = '1.18';
+$Workflow::Factory::VERSION = '1.19';
 
 my ($log);
 my (%INSTANCES);
@@ -494,13 +494,20 @@
     foreach my $actions (@all_action_config) {
         next unless ( ref $actions eq 'HASH' );
 
-        # Handle optional type.
+        # TODO Handle optional type.
         # Should we check here to see if this matches an existing
         # workflow type? Maybe do a type check at the end of the config
         # process?
         my $type = exists $actions->{type} ? $actions->{type} : 'default';
 
-        foreach my $action_config ( @{ $actions->{action} } ) {
+        my $a;
+        if ( exists $actions->{action} ) {
+            $a = $actions->{action};
+        } else {
+            push @{$a}, $actions;
+        }
+
+        foreach my $action_config ( @{$a} ) {
             my $name = $action_config->{name};
             $log->is_debug
                 && $log->debug(
@@ -612,7 +619,14 @@
         my $type
             = exists $conditions->{type} ? $conditions->{type} : 'default';
 
-        foreach my $condition_config ( @{ $conditions->{condition} } ) {
+        my $c;
+        if ( exists $conditions->{condition} ) {
+            $c = $conditions->{condition};
+        } else {
+            push @{$c}, $conditions;
+        }
+
+        foreach my $condition_config ( @{$c} ) {
             my $name = $condition_config->{name};
             $log->is_debug
                 && $log->debug("Adding configuration for condition '$name'");
@@ -679,7 +693,14 @@
     foreach my $validators (@all_validator_config) {
         next unless ( ref $validators eq 'HASH' );
 
-        for my $validator_config ( @{ $validators->{validator} } ) {
+        my $v;
+        if ( exists $validators->{validator} ) {
+            $v = $validators->{validator};
+        } else {
+            push @{$v}, $validators;
+        }
+
+        for my $validator_config ( @{$v} ) {
             my $name = $validator_config->{name};
             $log->is_debug
                 && $log->debug("Adding configuration for validator '$name'");
