--- scripts/mysqlaccess.sh.orig	2005-01-16 14:28:38 -08:00
+++ scripts/mysqlaccess.sh	2005-01-16 14:28:38 -08:00
@@ -2,7 +2,7 @@
 # ****************************
 package MySQLaccess;
 #use strict;
-use POSIX qw(tmpnam);
+use File::Temp qw(tempfile tmpnam);
 use Fcntl;
 
 BEGIN {
@@ -32,7 +32,6 @@
 	$ACCESS_U_BCK = 'user_backup';   
 	$ACCESS_D_BCK = 'db_backup';     
         $DIFF      = '/usr/bin/diff'; 
-        $TMP_PATH  = '/tmp';             #path to writable tmp-directory
         $MYSQLDUMP = '@bindir@/mysqldump';
                                          #path to mysqldump executable
 
@@ -432,7 +431,7 @@
 # no caching on STDOUT
 	$|=1;
 
-	$MYSQL_CNF = POSIX::tmpnam();
+	$MYSQL_CNF = tmpnam();
 	%MYSQL_CNF = (client    => { },
                       mysql     => { },
                       mysqldump => { },
@@ -577,8 +576,6 @@
 push(@MySQLaccess::Grant::Error,'not_found_mysql')     if !(-x $MYSQL);
 push(@MySQLaccess::Grant::Error,'not_found_diff')      if !(-x $DIFF);
 push(@MySQLaccess::Grant::Error,'not_found_mysqldump') if !(-x $MYSQLDUMP);
-push(@MySQLaccess::Grant::Error,'not_found_tmp')       if !(-d $TMP_PATH);
-push(@MySQLaccess::Grant::Error,'write_err_tmp')       if !(-w $TMP_PATH);
 if (@MySQLaccess::Grant::Error) {
    MySQLaccess::Report::Print_Error_Messages() ;
    exit 0;
@@ -1777,17 +1774,15 @@
    @before = sort(@before);
    @after  = sort(@after);
 
-   $before = "$MySQLaccess::TMP_PATH/$MySQLaccess::script.before.$$";
-   $after  = "$MySQLaccess::TMP_PATH/$MySQLaccess::script.after.$$";
-   #$after = "/tmp/t0";
-   open(BEFORE,"> $before") ||
-    push(@MySQLaccess::Report::Errors,"Can't open temporary file $before for writing");
-   open(AFTER,"> $after") ||
-    push(@MySQLaccess::Report::Errors,"Can't open temporary file $after for writing");
-   print BEFORE join("\n",@before);
-   print AFTER  join("\n",@after);
-   close(BEFORE);
-   close(AFTER);
+   ($hb, $before) = tempfile("$MySQLaccess::script.XXXXXX") or
+    push(@MySQLaccess::Report::Errors,"Can't create temporary file: $!");
+   ($ha, $after)  = tempfile("$MySQLaccess::script.XXXXXX") or
+    push(@MySQLaccess::Report::Errors,"Can't create temporary file: $!");
+
+   print $hb join("\n",@before);
+   print $ha join("\n",@after);
+   close $hb;
+   close $ha;
 
    # ----------------------------------
    # compute difference
@@ -1800,8 +1795,8 @@
 
    # ----------------------------------
    # cleanup temp. files
-   unlink(BEFORE);
-   unlink(AFTER);
+   unlink($before);
+   unlink($after);
 
    return \@diffs;
 }
@@ -2316,14 +2311,6 @@
    => "The diff program <$MySQLaccess::DIFF> could not be found.\n"
      ."+ Check your path, or\n"
      ."+ edit the source of this script to point \$DIFF to the diff program.\n"
- ,'not_found_tmp'
-   => "The temporary directory <$MySQLaccess::TMP_PATH> could not be found.\n"
-     ."+ create this directory (writeable!), or\n"
-     ."+ edit the source of this script to point \$TMP_PATH to the right directory.\n"
- ,'write_err_tmp'
-   => "The temporary directory <$MySQLaccess::TMP_PATH> is not writable.\n"
-     ."+ make this directory writeable!, or\n"
-     ."+ edit the source of this script to point \$TMP_PATH to another directory.\n"
  ,'Unrecognized_option'
    => "Sorry,\n"
      ."You are using an old version of the mysql-program,\n"
