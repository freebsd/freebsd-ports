--- lib/Test/OpenLDAP.pm.orig	2013-03-13 10:05:02 UTC
+++ lib/Test/OpenLDAP.pm
@@ -95,6 +95,8 @@ sub new {
       File::Spec->catdir( $self->{slapd_d_directory}, 'cn=config' );
     $self->{cn_schema_directory} =
       File::Spec->catdir( $self->{cn_config_directory}, 'cn=schema' );
+    $self->{cn_module_ldif_path} =
+      File::Spec->catfile( $self->{cn_config_directory}, 'cn=module{0}.ldif' );
     $self->{cn_schema_ldif_path} =
       File::Spec->catfile( $self->{cn_config_directory}, 'cn=schema.ldif' );
     $self->{cn_schema_core_ldif_path} =
@@ -123,6 +125,7 @@ sub new {
     mkdir $self->{db_directory}, oct USER_READ_WRITE_EXECUTE_PERMISSIONS()
       or Carp::croak("Failed to mkdir $self->{db_directory}:$OS_ERROR");
     $self->_create_config_ldif();
+    $self->_create_module_ldif();
     $self->_create_schema_ldif();
     $self->_create_schema_core_ldif();
     $self->{olc_database_for_config} = '{0}config';
@@ -372,6 +375,34 @@ __CONFIG_LDIF__
     return;
 }
 
+sub _create_module_ldif {
+    my ($self)      = @_;
+    my $write_flags = Fcntl::O_WRONLY() | Fcntl::O_CREAT() | Fcntl::O_EXCL();
+    my $uuid        = lc $self->_uuid();
+    my $entry_csn   = $self->_entry_csn();
+    my $create_timestamp = POSIX::strftime( '%Y%m%d%H%M%SZ', gmtime time );
+    my $handle = FileHandle->new( $self->{cn_module_ldif_path},
+        $write_flags, oct USER_READ_WRITE_PERMISSIONS() )
+      or Carp::croak(
+        "Failed to open '$self->{cn_module_ldif_path}' for writing:$OS_ERROR");
+    $handle->print(
+        <<"__MODULE_LDIF__") or Carp::croak("Failed to write to '$self->{cn_module_ldif_path}':$OS_ERROR");
+dn: cn=module{0}
+objectClass: olcModuleList
+cn: module{0}
+olcModulePath: %%LOCALBASE%%/libexec/openldap
+olcModuleLoad: {0}back_bdb
+olcModuleLoad: {1}back_hdb
+structuralObjectClass: olcModuleList
+entryUUID: $uuid
+creatorsName: cn=config
+createTimestamp: $create_timestamp
+entryCSN: $entry_csn
+modifiersName: cn=config
+modifyTimestamp: $create_timestamp
+__MODULE_LDIF__
+}
+
 sub _create_schema_ldif {
     my ($self)      = @_;
     my $write_flags = Fcntl::O_WRONLY() | Fcntl::O_CREAT() | Fcntl::O_EXCL();
@@ -1697,6 +1728,10 @@ sub DESTROY {
       or Carp::croak(
         "Failed to unlink '$self->{olc_database_config_path}':$OS_ERROR");
     $self->_remove_cn_schema_directory();
+    unlink $self->{cn_module_ldif_path}
+      or ( $OS_ERROR == POSIX::ENOENT() )
+      or Carp::croak(
+        "Failed to unlink '$self->{cn_module_ldif_path}':$OS_ERROR");
     rmdir $self->{cn_config_directory}
       or ( $OS_ERROR == POSIX::ENOENT() )
       or
