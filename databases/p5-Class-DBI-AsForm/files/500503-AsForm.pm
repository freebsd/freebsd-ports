--- AsForm.pm.orig	Sat Apr  3 22:37:32 2004
+++ AsForm.pm	Sat Apr  3 22:37:38 2004
@@ -1,16 +1,14 @@
 package Class::DBI::AsForm;
-use 5.006;
 use strict;
-use warnings;
 use Class::DBI::Plugin::Type ();
-our $OLD_STYLE = 0;
+use vars qw($OLD_STYLE);$OLD_STYLE = 0;
 
 use HTML::Element;
 require Exporter;
-our @ISA = qw(Exporter);
-our @EXPORT = qw( to_cgi to_field _to_textarea _to_textfield _to_select
+use vars qw(@ISA);@ISA = qw(Exporter);
+use vars qw(@EXPORT);@EXPORT = qw( to_cgi to_field _to_textarea _to_textfield _to_select
 type_of );
-our $VERSION = '2.3';
+use vars qw($VERSION);$VERSION = '2.3';
 
 =head1 NAME
 
@@ -100,14 +98,14 @@
 sub _to_textarea {
     my ($self, $col) = @_;
     my $a = HTML::Element->new("textarea", name => $col);
-    if (ref $self) { $a->push_content($self->$col) }
+    if (ref $self) { $a->push_content($self->$col()) }
     $OLD_STYLE && return $a->as_HTML;
     $a;
 }
 
 sub _to_textfield {
     my ($self, $col) = @_;
-    my $value = ref $self && $self->$col;
+    my $value = ref $self && $self->$col();
     my $a = HTML::Element->new("input", type=> "text", name => $col);
     $a->attr("value" => $value) if $value;
     $OLD_STYLE && return $a->as_HTML;
@@ -122,7 +120,7 @@
     for (@objs) { 
         my $sel = HTML::Element->new("option", value => $_->id);
         $sel->attr("selected" => "selected") if ref $self 
-                                                and eval { $_->id eq $self->$col->id };
+                                                and eval { $_->id eq $self->$col()->id };
         $sel->push_content($_->stringify_self);
         $a->push_content($sel);
     }
