--- inc/Module/Install/Makefile.pm.orig	Wed Apr  6 10:14:53 2005
+++ inc/Module/Install/Makefile.pm	Wed Apr  6 10:14:36 2005
@@ -0,0 +1,143 @@
+#line 1 "inc/Module/Install/Makefile.pm - /usr/local/lib/perl5/site_perl/5.8.6/Module/Install/Makefile.pm"
+package Module::Install::Makefile;
+use Module::Install::Base; @ISA = qw(Module::Install::Base);
+
+$VERSION = '0.01';
+
+use strict 'vars';
+use vars '$VERSION';
+
+use ExtUtils::MakeMaker ();
+
+sub Makefile { $_[0] }
+
+sub prompt { 
+    shift;
+    goto &ExtUtils::MakeMaker::prompt;
+}
+
+sub makemaker_args {
+    my $self = shift;
+    my $args = ($self->{makemaker_args} ||= {});
+    %$args = ( %$args, @_ ) if @_;
+    $args;
+}
+
+sub clean_files {
+    my $self = shift;
+    my $clean = $self->makemaker_args->{clean} ||= {};
+    %$clean = (
+        %$clean, 
+        FILES => join(" ", grep length, $clean->{FILES}, @_),
+    );
+}
+
+sub libs {
+    my $self = shift;
+    my $libs = ref $_[0] ? shift : [shift];
+    $self->makemaker_args( LIBS => $libs );
+}
+
+sub inc {
+    my $self = shift;
+    $self->makemaker_args( INC => shift );
+}
+
+sub write {
+    my $self = shift;
+    die "&Makefile->write() takes no arguments\n" if @_;
+
+    my $args = $self->makemaker_args;
+
+    $args->{DISTNAME} = $self->name;
+    $args->{NAME} = $self->module_name || $self->name || $self->determine_NAME($args);
+    $args->{VERSION} = $self->version || $self->determine_VERSION($args);
+    $args->{NAME} =~ s/-/::/g;
+
+    if ($] >= 5.005) {
+	$args->{ABSTRACT} = $self->abstract;
+	$args->{AUTHOR} = $self->author;
+    }
+    if ( eval($ExtUtils::MakeMaker::VERSION) >= 6.10 ) {
+        $args->{NO_META} = 1;
+    }
+    if ( eval($ExtUtils::MakeMaker::VERSION) > 6.17 ) {
+	$args->{SIGN} = 1 if $self->sign;
+    }
+    delete $args->{SIGN} unless $self->is_admin;
+
+    # merge both kinds of requires into prereq_pm
+    my $prereq = ($args->{PREREQ_PM} ||= {});
+    %$prereq = ( %$prereq, map { @$_ } map { @$_ } grep $_,
+                 ($self->build_requires, $self->requires) );
+
+    # merge both kinds of requires into prereq_pm
+    my $dir = ($args->{DIR} ||= []);
+    if ($self->bundles) {
+        push @$dir, map "$_->[1]", @{$self->bundles};
+        delete $prereq->{$_->[0]} for @{$self->bundles};
+    }
+
+    if (my $perl_version = $self->perl_version) {
+        eval "use $perl_version; 1"
+            or die "ERROR: perl: Version $] is installed, ".
+                   "but we need version >= $perl_version";
+    }
+
+    my %args = map {($_ => $args->{$_})} grep {defined($args->{$_})} keys %$args;
+
+    if ($self->admin->preop) {
+        $args{dist} = $self->admin->preop;
+    }
+
+    ExtUtils::MakeMaker::WriteMakefile(%args);
+
+    $self->fix_up_makefile();
+}
+
+sub fix_up_makefile {
+    my $self = shift;
+    my $top_class = ref($self->_top) || '';
+    my $top_version = $self->_top->VERSION || '';
+
+    my $preamble = $self->preamble 
+       ? "# Preamble by $top_class $top_version\n" . $self->preamble
+       : '';
+    my $postamble = "# Postamble by $top_class $top_version\n" . 
+                    ($self->postamble || '');
+
+    open MAKEFILE, '< Makefile' or die $!;
+    my $makefile = do { local $/; <MAKEFILE> };
+    close MAKEFILE;
+
+    $makefile =~ s/\b(test_harness\(\$\(TEST_VERBOSE\), )/$1'inc', /;
+    $makefile =~ s/( -I\$\(INST_ARCHLIB\))/ -Iinc$1/g;
+    $makefile =~ s/( "-I\$\(INST_LIB\)")/ "-Iinc"$1/g;
+
+    $makefile =~ s/^(FULLPERL = .*)/$1 -Iinc/m;
+    $makefile =~ s/^(PERL = .*)/$1 -Iinc/m;
+
+    open MAKEFILE, '> Makefile' or die $!;
+    print MAKEFILE "$preamble$makefile$postamble";
+    close MAKEFILE;
+}
+
+sub preamble {
+    my ($self, $text) = @_;
+    $self->{preamble} = $text . $self->{preamble} if defined $text;
+    $self->{preamble};
+}
+
+sub postamble {
+    my ($self, $text) = @_;
+
+    $self->{postamble} ||= $self->admin->postamble;
+    $self->{postamble} .= $text if defined $text;
+    $self->{postamble}
+}
+
+1;
+
+__END__
+
+#line 273
