--- AsForm.pm.orig	Mon Dec 27 16:43:44 2004
+++ AsForm.pm	Wed Dec 29 20:31:57 2004
@@ -1,19 +1,18 @@
 package Class::DBI::AsForm;
 
-use 5.006;
 
 use strict;
-use warnings;
 
 use base 'Exporter';
 
 use Class::DBI::Plugin::Type ();
 use HTML::Element;
 
-our $OLD_STYLE = 0;
-our @EXPORT    = qw( to_cgi to_field _to_textarea _to_textfield _to_select
+use vars qw($OLD_STYLE @EXPORT $VERSION);
+$OLD_STYLE = 0;
+@EXPORT    = qw( to_cgi to_field _to_textarea _to_textfield _to_select
 	type_of );
-our $VERSION = '2.41';
+$VERSION = '2.41';
 
 =head1 NAME
 
@@ -106,14 +105,14 @@
 	my ($self, $col) = @_;
 	my $a =
 		HTML::Element->new("textarea", name => $col, rows => "3", cols => "22");
-	if (ref $self) { $a->push_content($self->$col) }
+	if (ref $self) { $a->push_content($self->$col()) }
 	$OLD_STYLE && return $a->as_HTML;
 	$a;
 }
 
 sub _to_textfield {
 	my ($self, $col) = @_;
-	my $value = ref $self && $self->$col;
+	my $value = ref $self && $self->$col();
 	my $a = HTML::Element->new("input", type => "text", name => $col);
 	$a->attr("value" => $value) if $value;
 	$OLD_STYLE && return $a->as_HTML;
@@ -129,7 +128,7 @@
 		my $sel = HTML::Element->new("option", value => $_->id);
 		$sel->attr("selected" => "selected")
 			if ref $self
-			and eval { $_->id eq $self->$col->id };
+			and eval { $_->id eq $self->$col()->id };
 		$sel->push_content($_->stringify_self);
 		$a->push_content($sel);
 	}
