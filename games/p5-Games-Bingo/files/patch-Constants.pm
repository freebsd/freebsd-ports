--- lib/Games/Bingo/Constants.pm.orig	Sat Jan 24 12:44:38 2004
+++ lib/Games/Bingo/Constants.pm	Sat Jan 24 12:44:50 2004
@@ -23,8 +23,8 @@
 
 use constant NUMBER_OF_ROWS_IN_CARD    => 3;
 use constant NUMBER_OF_COLUMNS_IN_CARD => 9;
-use constant NUMBER_OF_NUMBERS_IN_CARD 
-	=> (NUMBER_OF_NUMBERS_IN_ROW * NUMBER_OF_ROWS_IN_CARD);
+use constant NUMBER_OF_NUMBERS_IN_CARD =>
+	(NUMBER_OF_NUMBERS_IN_ROW * NUMBER_OF_ROWS_IN_CARD);
 
 
 1;
@@ -109,4 +109,4 @@
 Games::Bingo is (C) 2003-2004 Jonas B. Nielsen (jonasbn)
 E<lt>jonasbn@cpan.orgE<gt>
 
-=cut
\ No newline at end of file
+=cut
