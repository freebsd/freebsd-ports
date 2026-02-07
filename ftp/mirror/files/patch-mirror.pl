--- mirror.pl.orig	Mon Jun  8 12:55:27 1998
+++ mirror.pl	Tue Jun  1 16:24:17 2004
@@ -104,7 +104,7 @@
 # Try to find the default location of various programs via
 # the users PATH then using $extra_path
 if( ! $on_win ){
-	$extra_path = '/usr/local/bin:/usr/new/bin:/usr/public/bin:/usr/ucb:/usr/bin:/bin:/etc:/usr/etc:/usr/local/etc';
+	$extra_path = '/bin:/sbin:/usr/bin:/usr/sbin:/usr/local/bin:/usr/local/sbin';
 }
 if( $extra_path ne '' ){
 	$ENV{ 'PATH' } .= $path_sep . $extra_path;
@@ -159,19 +159,20 @@
 $rm_prog = &find_prog( 'rm' );
 
 # Generate checksums
-$sum_prog = &find_prog( 'sum' );
+$sum_prog = &find_prog( 'md5' );
 
 # SPECIAL NOTE: This is eval'd, so DONT put double-quotes (") in it.
 # You can get local variables to appear as in the second example:
-$mail_subject = '-s \'mirror update\'';
-# $mail_subject = ' -s \'mirror update of $package\'';
+# $mail_subject = '-s \'mirror update\'';
+$mail_subject = ' -s \'mirror update of $package\'';
 
 # When scanning the local directory, how often to prod the remote
 # system to keep the connection alive
 $prod_interval = 60;
 
 # Put the directory that mirror is actually in at the start of PERLLIB.
-$dir = &real_dir_from_path( $0 );
+# $dir = &real_dir_from_path( $0 );
+$dir = "/usr/local/lib/mirror";
 unshift( @INC, $dir );
 
 # Debian GNU/Linux stores mirror.defaults in /etc/mirror
@@ -1322,8 +1323,11 @@
 
 		# Create a get_patt from the contents of the local directory
 		if( $update_local && $#get_top >= 0 ){
-			$get_patt = '^' . join( '|^', @get_top );
-			$get_patt =~ s/$squished//g;
+			my ($path,$re,@re_patt);
+			#$get_patt = '^' . join( '|^', @get_top );
+			#$get_patt =~ s/$squished//g;
+			foreach $path ( @get_top ) { push @re_patt, "\^\Q$path\E\$"; }
+			$get_patt= join( '|', @re_patt );
 			&msg( "get_patt = $get_patt\n" ) if $debug;
 		}
 	
