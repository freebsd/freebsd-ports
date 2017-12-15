--- lib/Log/Dispatch/File/Rolling.pm.orig	2017-11-09 20:22:14 UTC
+++ lib/Log/Dispatch/File/Rolling.pm
@@ -39,7 +39,8 @@ sub new {
 	my $self = bless {}, $class;
 
 	# only append mode is supported
-	$p{mode} = 'append';
+	$p{mode} = 'append';  # Specifies append for Log::Dispatch::File 2.37 through 2.58
+	$self->{mode} = '>>'; # Specifies append for Log::Dispatch::File 2.59+ (no longer done by _basic_init)
 
 	# base class initialization
 	$self->_basic_init(%p);
@@ -63,7 +64,10 @@ sub new {
 	}
 
 	$self->{rolling_fh_pid} = $$;
-	$self->_make_handle();
+	# _make_handle() was removed in Log::Dispatch::File 2.67
+	# $self->_make_handle();
+	$self->_open_file()
+		unless $self->{close_after_write} || $self->{lazy_open};
 
 	return $self;
 }
