--- lib/File/Pid.pm    2009-01-17 09:44:31.653906918 +0000
+++ lib/File/Pid.pm    2009-01-17 09:44:01.397399415 +0000
@@ -119,7 +119,7 @@

 sub running {
     my $self = shift;
-    my $pid  = $self->_get_pid_from_file;
+    my $pid  = $self->_get_pid_from_file or return undef;

     return   kill(0, $pid)
            ? $pid
