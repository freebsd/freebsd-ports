--- lib/UI/Dialog/Backend/CDialog.pm.orig	Mon May 22 10:22:07 2006
+++ lib/UI/Dialog/Backend/CDialog.pm	Mon May 22 10:22:26 2006
@@ -63,7 +63,7 @@
     $self->{'_opts'}->{'height'} = $cfg->{'height'} || 10;
     $self->{'_opts'}->{'percentage'} = $cfg->{'percentage'} || 1;
     $self->{'_opts'}->{'colours'} = ($cfg->{'colours'} || $cfg->{'colors'}) ? 1 : 0;
-    $self->{'_opts'}->{'bin'} ||= $self->_find_bin('dialog');
+    $self->{'_opts'}->{'bin'} ||= $self->_find_bin('cdialog');
     $self->{'_opts'}->{'autoclear'} = $cfg->{'autoclear'} || 0;
     $self->{'_opts'}->{'clearbefore'} = $cfg->{'clearbefore'} || 0;
     $self->{'_opts'}->{'clearafter'} = $cfg->{'clearafter'} || 0;
@@ -71,7 +71,7 @@
     $self->{'_opts'}->{'beepbefore'} = $cfg->{'beepbefore'} || 0;
     $self->{'_opts'}->{'beepafter'} = $cfg->{'beepafter'} || 0;
     unless (-x $self->{'_opts'}->{'bin'}) {
-		croak("the dialog binary could not be found at: ".$self->{'_opts'}->{'bin'});
+		croak("the cdialog binary could not be found at: ".$self->{'_opts'}->{'bin'});
     }
     $self->{'_opts'}->{'DIALOGRC'} = $cfg->{'DIALOGRC'} || undef();
     my $beginref = $cfg->{'begin'};
