--- scripts/mysqlhotcopy.sh.orig	Sun Dec 21 19:01:29 2003
+++ scripts/mysqlhotcopy.sh	Thu Sep 23 11:02:45 2004
@@ -7,6 +7,7 @@
 use File::Path;
 use DBI;
 use Sys::Hostname;
+use File::Temp;
 
 =head1 NAME
 
@@ -607,7 +608,6 @@
 sub copy_index
 {
   my ($method, $files, $source, $target) = @_;
-  my $tmpfile="$opt_tmpdir/mysqlhotcopy$$";
   
   print "Copying indices for ".@$files." files...\n" unless $opt{quiet};  
   foreach my $file (@$files)
@@ -633,23 +633,23 @@
       }
       close OUTPUT	   || die "Error on close of $to: $!\n";
     }
-    elsif ($opt{method} eq 'scp')
+    elsif ($opt{method} =~ /^scp\b/)
     {
-      my $tmp=$tmpfile;
-      open(OUTPUT,">$tmp") || die "Can\'t create file $tmp: $!\n";
-      if (syswrite(OUTPUT,$buff) != length($buff))
+      my ($fh, $tmp)=tempfile('mysqlhotcopy-XXXXXX', DIR => $opt_tmpdir);
+      die "Can\'t create/open file in $opt_tmpdir\n";
+      if (syswrite($fh,$buff) != length($buff))
       {
 	die "Error when writing data to $tmp: $!\n";
       }
-      close OUTPUT	     || die "Error on close of $tmp: $!\n";
-      safe_system("scp $tmp $to");
+      close $fh || die "Error on close of $tmp: $!\n";
+      safe_system("$opt{method} $tmp $to");
+      unlink $tmp;
     }
     else
     {
       die "Can't use unsupported method '$opt{method}'\n";
     }
   }
-  unlink "$tmpfile" if  ($opt{method} eq 'scp');
 }
 
 
