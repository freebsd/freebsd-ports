*** Makefile.PL.orig	Wed Jan  3 14:28:25 2001
--- Makefile.PL	Wed Jan  3 14:28:38 2001
***************
*** 75,79 ****
  					map { "$_ */$_ */*/$_" }
  					qw(*% *.html *.b[ac]k *.old *.orig))
  			   },
- 	'macro'		=> { INSTALLDIRS => 'perl' },
  );
--- 75,78 ----
