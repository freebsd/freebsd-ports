*** ftp.pl.orig	Fri Jun  5 11:10:27 1998
--- ftp.pl	Fri Sep 10 10:40:50 1999
***************
*** 150,156 ****
  # (Normally set elsewhere - this is just a sensible default.)
  # Is expected to take count and code as arguments and prompt
  # for the secret key  with 'password:' on stdout and then print the password.
! $ftp'keygen_prog = '/usr/local/bin/key';
  
  # Uncomment to turn on lots of debugging.
  # &debug( 10 );
--- 150,156 ----
  # (Normally set elsewhere - this is just a sensible default.)
  # Is expected to take count and code as arguments and prompt
  # for the secret key  with 'password:' on stdout and then print the password.
! $ftp'keygen_prog = '/usr/bin/key';
  
  # Uncomment to turn on lots of debugging.
  # &debug( 10 );
***************
*** 486,492 ****
  		return 0;
  	}
  	if( $ret == 1 ) {
! 		if( $response =~ m/^227 Entering Passive Mode \((\d+),(\d+),(\d+),(\d+),(\d+),(\d+)\)/ ){
  			$newhost = sprintf( "%d.%d.%d.%d", $1, $2, $3, $4 );
  			$newport = $5 * 256 + $6;
  		}
--- 486,492 ----
  		return 0;
  	}
  	if( $ret == 1 ) {
! 		if( $response =~ m/^227 .* \((\d+),(\d+),(\d+),(\d+),(\d+),(\d+)\)/ ){
  			$newhost = sprintf( "%d.%d.%d.%d", $1, $2, $3, $4 );
  			$newport = $5 * 256 + $6;
  		}
