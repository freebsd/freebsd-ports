--- Pg.pm.orig	Thu Apr 19 13:39:06 2001
+++ Pg.pm	Thu Apr 19 13:40:13 2001
@@ -82,8 +82,10 @@
         $user = "" unless defined($user);
         $auth = "" unless defined($auth);
 
-        $user = $ENV{DBI_USER} unless $user eq "";
-        $auth = $ENV{DBI_PASS} unless $auth eq "";
+        $user ||= $ENV{DBI_USER};
+        $auth ||= $ENV{DBI_PASS};
+	$user ||= "";
+	$auth ||= "";
 
         my($dbh) = DBI::_new_dbh($drh, {
             'Name' => $Name,
