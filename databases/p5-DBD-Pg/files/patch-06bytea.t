--- t/06bytea.t.orig	Sun Mar 20 10:47:38 2005
+++ t/06bytea.t	Thu Aug  4 22:34:26 2005
@@ -9,7 +9,7 @@
 $|=1;
 
 if (defined $ENV{DBI_DSN}) {
-	plan tests => 3;
+	plan tests => 6;
 } else {
 	plan skip_all => 'Cannot run test unless DBI_DSN is defined. See the README file';
 }
@@ -22,12 +22,21 @@
 
 $sth = $dbh->prepare(qq{INSERT INTO dbd_pg_test (id,bytetest) VALUES (?,?)});
 $sth->bind_param(2, undef, { pg_type => DBD::Pg::PG_BYTEA });
-$sth->execute(400, "a\0b");
+ok($sth->execute(400, "a\0b", 'execute 401');
+ok($sth->execute(401, '\''), 'execute 401');
+ok($sth->execute(402, '\''), 'execute 402');
+
+
 $sth = $dbh->prepare(qq{SELECT bytetest FROM dbd_pg_test WHERE id=?});
 $sth->execute(400);
 
 my $byte = $sth->fetchall_arrayref()->[0][0];
 ok($byte eq "a\0b", "text from BYTEA column looks corect");
+
+$sth->execute(402);
+$byte = $sth->fetchall_arrayref()->[0][0];
+is($byte, '\'', 'text from BYTEA column with quote');
+
 $sth->finish();
 
 $dbh->rollback();
