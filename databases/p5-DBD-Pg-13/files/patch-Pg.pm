--- ./Pg.pm.orig	Tue Aug 12 02:03:06 2003
+++ ./Pg.pm	Tue Aug 12 02:31:41 2003
@@ -70,8 +70,8 @@
     sub pg_use_catalog {
       my $dbh = shift;
       my $version = DBD::Pg::pg_server_version($dbh);
-		$version =~ /^(\d+\.\d+)/;
-      return $1 < 7.3 ? "" : "pg_catalog.";
+      $version =~ s/^(\d+\.\d+).*/$1/;
+      return $version < 7.3 ? "" : "pg_catalog.";
     }
 
     1;
@@ -200,6 +200,7 @@
 		my $wh = ""; # ();
 		$wh = join( " AND ", '', @wh ) if (@wh);
 		my $version = DBD::Pg::pg_server_version($dbh);
+		$version =~ s/^(\d+\.\d+).*/$1/;
 		my $showschema = $version < 7.3 ? "NULL::text" : "n.nspname";
 		my $schemajoin = $version < 7.3 ? "" : "LEFT JOIN pg_catalog.pg_namespace n ON (n.oid = c.relnamespace)";
 		my $col_info_sql = qq{
@@ -258,10 +259,10 @@
 		my @wh = (); my @dat = ();  # Used to hold data for the attributes.
 
 		my $version = DBD::Pg::pg_server_version($dbh);
-		$version =~ /^(\d+)\.(\d)/;
+		$version =~ s/^(\d+\.\d+).*/$1/;
 
 		my @flds = qw/catname u.usename bc.relname/;
-		$flds[1] = 'n.nspname' unless ($1.$2 < 73);
+		$flds[1] = 'n.nspname' unless ($version < 7.3);
 
 		for my $idx (0 .. $#attrs) {
 			next if ($flds[$idx] eq 'catname'); # Skip catalog
@@ -600,6 +601,7 @@
 		my $tbl_sql = ();
 
         my $version = DBD::Pg::pg_server_version($dbh);
+        $version =~ s/^(\d+\.\d+).*/$1/;
         my $CATALOG = DBD::Pg::pg_use_catalog($dbh);
 
 		if ( # Rules 19a
@@ -804,6 +806,7 @@
     sub tables {
         my($dbh) = @_;
         my $version = DBD::Pg::pg_server_version($dbh);
+        $version =~ s/^(\d+\.\d+).*/$1/;
 
 		my $SQL = ($version < 7.3) ? 
             "SELECT relname  AS \"TABLE_NAME\"
@@ -908,7 +911,8 @@
             # by pg_constraint. To maintain compatibility, check 
             # version number and execute appropriate query.
 	
-            my $version = pg_server_version( $dbh );
+            my $version = DBD::Pg::pg_server_version( $dbh );
+            $version =~ s/^(\d+\.\d+).*/$1/;
             
             my $con_query = $version < 7.3
              ? "SELECT rcsrc FROM pg_relcheck WHERE rcname = '${table}_$col_name'"
