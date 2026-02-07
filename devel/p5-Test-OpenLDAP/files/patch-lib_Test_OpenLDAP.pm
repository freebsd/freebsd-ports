--- lib/Test/OpenLDAP.pm.orig	2024-02-22 23:31:46 UTC
+++ lib/Test/OpenLDAP.pm
@@ -120,6 +120,7 @@
 sub _version {
     my ($self) = @_;
     my $key = '_slapd_version';
+    local $ENV{PATH} = "$ENV{PATH}$Config{path_sep}/usr/local/libexec";
     if ( defined $self->{$key} ) {
     }
     else {
@@ -197,7 +198,7 @@
     {
         my $path_sep          = $Config{path_sep};
         my @slapd_directories = split /$path_sep/smx,
-          "$ENV{PATH}$path_sep/usr/lib/openldap";
+          "$ENV{PATH}$path_sep/usr/local/libexec";
         my $slapd_path;
         foreach my $directory (@slapd_directories) {
             my $possible =
@@ -250,8 +251,8 @@
     }
     elsif ( defined $pid ) {
         eval {
-            local $ENV{PATH} = "$ENV{PATH}$Config{path_sep}/usr/lib/openldap"
-              ;    # adding /usr/lib/openldap for OpenSUSE deployments
+            local $ENV{PATH} = "$ENV{PATH}$Config{path_sep}/usr/local/libexec"
+              ;    # adding /usr/local/libexec for OpenSUSE deployments
             sysopen STDERR, $dev_null, Fcntl::O_WRONLY()
               or
               Carp::croak("Failed to redirect STDERR to $dev_null:$OS_ERROR");
