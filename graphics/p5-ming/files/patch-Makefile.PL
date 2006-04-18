--- Makefile.PL.orig	Wed Feb  1 15:45:17 2006
+++ Makefile.PL	Mon Apr 17 23:31:32 2006
@@ -78,25 +78,25 @@
     clean   => {
         FILES   => "@do_clean",
     },
-    'MYEXTLIB'     => $MING_DIR . '/libming.a',
+#    'MYEXTLIB'     => $MING_DIR . '/libming.a',
     'OBJECT'       => "$XS_OBJECTS",
     #'LIBS'         => [ "-lz" ],
-		'LIBS'         => [ $libs ],
+		'LIBS'         => ["-L$ENV{LOCALBASE}/lib -lming"],
 );
 
 sub MY::install {
 	my $self = shift;
 	write_myconfig_file($self->{INSTALLSITEARCH});
 
-	for (qw(ming.h libming.a)){
-		$self->{PM}->{"$MING_DIR/$_"} = '$(INST_ARCHLIB)' . "/auto/SWF/include/$_";
-	}
+#	for (qw(ming.h libming.a)){
+#		$self->{PM}->{"$MING_DIR/$_"} = '$(INST_ARCHLIB)' . "/auto/SWF/include/$_";
+#	}
 	$self->{PM}->{'perl_swf.h'} = '$(INST_ARCHLIB)' . "/auto/SWF/include/perl_swf.h";
 	return $self->MM::install;
 }
 
 sub ming_is_compiled{
-	return undef unless (-e "$MING_DIR/libming.a");
+#	return undef unless (-e "$MING_DIR/libming.a");
 	return 1;
 }
 
