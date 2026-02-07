--- inc/Module/Install/Makefile.pm.orig	2010-07-09 05:30:37.888238012 +0900
+++ inc/Module/Install/Makefile.pm	2010-07-09 05:31:07.586884004 +0900
@@ -213,21 +213,6 @@
 	# Make sure we have a new enough MakeMaker
 	require ExtUtils::MakeMaker;
 
-	if ( $perl_version and $self->_cmp($perl_version, '5.006') >= 0 ) {
-		# MakeMaker can complain about module versions that include
-		# an underscore, even though its own version may contain one!
-		# Hence the funny regexp to get rid of it.  See RT #35800
-		# for details.
-		my $v = $ExtUtils::MakeMaker::VERSION =~ /^(\d+\.\d+)/;
-		$self->build_requires(     'ExtUtils::MakeMaker' => $v );
-		$self->configure_requires( 'ExtUtils::MakeMaker' => $v );
-	} else {
-		# Allow legacy-compatibility with 5.005 by depending on the
-		# most recent EU:MM that supported 5.005.
-		$self->build_requires(     'ExtUtils::MakeMaker' => 6.42 );
-		$self->configure_requires( 'ExtUtils::MakeMaker' => 6.42 );
-	}
-
 	# Generate the MakeMaker params
 	my $args = $self->makemaker_args;
 	$args->{DISTNAME} = $self->name;
