http://www.openoffice.org/issues/show_bug.cgi?id=29286
--- ../solenv/bin/deliver.pl.old	Mon May 10 18:46:11 2004
+++ ../solenv/bin/deliver.pl	Tue May 18 09:10:47 2004
@@ -138,6 +138,7 @@
 };
 $strip 		= '/usr/ccs/bin/strip' if ( $^O eq 'solaris' );
 $strip 		= 'strip' if ( $^O eq "darwin" );
+$strip 		= 'strip' if ( $^O eq "freebsd" );
 $upd           = $ENV{'UPD'};
 ($gui		= lc($ENV{GUI})) 		|| die "can't determine GUI";
 
