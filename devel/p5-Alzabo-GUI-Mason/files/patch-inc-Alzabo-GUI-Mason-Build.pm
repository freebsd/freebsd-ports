--- inc/Alzabo/GUI/Mason/Build.pm~	Wed Feb 18 19:54:38 2004
+++ inc/Alzabo/GUI/Mason/Build.pm	Wed Oct 13 15:39:43 2004
@@ -25,12 +25,10 @@
 {
     my $self = shift;
 
-    $self->_make_mason_dirs( 'schema' );
-
     require Alzabo::GUI::Mason::Config;
     my $base = Alzabo::GUI::Mason::Config::mason_web_dir();
     my $count = $self->_copy_dir( [ cwd(), 'mason' ],
-                                  [ $base, 'schema' ] );
+                                  [ $base ] );
     if ($count)
     {
 	warn <<'EOF';
@@ -123,21 +121,9 @@
     return if ( exists $self->{Alzabo}{uid} &&
                 exists $self->{Alzabo}{gid} );
 
-    $self->{Alzabo}{user} =
-        $self->prompt( <<'EOF',
-
-What user would you like to own the directories and files used for the
-Mason components as well as the components themselves?
-EOF
-                       $self->_possible_web_user );
+    $self->{Alzabo}{user} = $ENV{WWWOWN};
 
-    $self->{Alzabo}{group} =
-        $self->prompt( <<'EOF',
-
-What group would you like to own the directories and files used for
-the Mason components as well as the components themselves?
-EOF
-                       $self->_possible_web_group );
+    $self->{Alzabo}{group} = $ENV{WWWGRP};
 
     $self->{Alzabo}{uid} = (getpwnam( $self->{Alzabo}{user} ))[2] || $<;
     $self->{Alzabo}{gid} = (getgrnam( $self->{Alzabo}{group} ))[2] || $(;
