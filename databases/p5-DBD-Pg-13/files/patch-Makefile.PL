--- Makefile.PL.orig	Thu Feb 19 04:46:40 2004
+++ Makefile.PL	Fri Oct 15 13:25:34 2004
@@ -33,7 +32,7 @@
 require App::Info::Handler::Prompt;
 my $p = App::Info::Handler::Prompt->new;
 my $pg = App::Info::RDBMS::PostgreSQL->new(on_unknown => $p);
-my ($major_ver, $minor_ver, $patch) = map {$pg->$_} qw/major_version minor_version patch_version/;
+my ($major_ver, $minor_ver, $patch) = map {$pg->$_()} qw/major_version minor_version patch_version/;
 
 if ((!$ENV{POSTGRES_INCLUDE} or !$ENV{POSTGRES_LIB}) and !$ENV{POSTGRES_HOME}) {
     $POSTGRES_INCLUDE = $pg->inc_dir;
@@ -66,7 +65,7 @@
   $dbi_arch_dir = dbd_dbi_arch_dir();
 }
 
-my $comp_opts = $Config{q{ccflags}};
+my $comp_opts = '';
 if ($major_ver == 7) {
     if ($minor_ver >= 2) {
         $comp_opts .= " -DHAVE_PQescapeString";
@@ -86,7 +85,7 @@
 my %opts = (
     NAME         => 'DBD::Pg',
     VERSION_FROM => 'Pg.pm',
-    INC          => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir",
+    INC          => "-I$POSTGRES_INCLUDE -I$dbi_arch_dir $comp_opts",
     OBJECT       => "Pg\$(OBJ_EXT) dbdimp\$(OBJ_EXT) quote\$(OBJ_EXT) types\$(OBJ_EXT)",
     LIBS         => ["-L$POSTGRES_LIB -lpq"],
     AUTHOR       => 'http://gborg.postgresql.org/project/dbdpg/projdisplay.php',
@@ -94,7 +93,6 @@
     PREREQ_PM    => { 'Test::Simple' => '0.17',  # Need Test::More.
                       'Test::Harness' => '2.03', # Need TODO tests.
                     },
-    CCFLAGS      => $comp_opts,
     PERL_MALLOC_OK => 1,
 );
 
