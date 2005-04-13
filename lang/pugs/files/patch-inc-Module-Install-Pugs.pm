--- inc/Module/Install/Pugs.pm  (revision 12842)
+++ inc/Module/Install/Pugs.pm  (local)
@@ -75,8 +75,8 @@
       File::Spec->catfile($path, "man1");
     $self->makemaker_args->{INST_MAN3DIR} =
       File::Spec->catfile($path, "man3");
-    $self->makemaker_args->{MAN1PODS} = {};
-    $self->makemaker_args->{MAN3PODS} = {};
+    $self->makemaker_args->{MAN1PODS} = {} if $perl_version == 6;
+    $self->makemaker_args->{MAN3PODS} = {} if $perl_version == 6;
     $self->{MM}{INST_AUTODIR} = '$(INST_LIB)/$(BASEEXT)';
     $self->{MM}{INST_ARCHAUTODIR} = '$(INST_ARCHLIB)/$(FULLEXT)';
 }
