--- Switch.pm	2014-08-01 14:47:54.000000000 +0200
+++ Switch.pm	2014-08-01 14:47:57.000000000 +0200
@@ -25,9 +25,11 @@ my ($Perl5, $Perl6) = (0,0);
 
 sub import
 {
+	my ($class) = @_;
+	my $self = bless {}, $class;
 	$fallthrough = grep /\bfallthrough\b/, @_;
 	$offset = (caller)[2]+1;
-	filter_add({}) unless @_>1 && $_[1] eq 'noimport';
+	filter_add($self) unless @_>1 && $_[1] eq 'noimport';
 	my $pkg = caller;
 	no strict 'refs';
 	for ( qw( on_defined on_exists ) )
