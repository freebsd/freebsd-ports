--- src/tty.c.orig	Tue Apr 25 10:18:46 2006
+++ src/tty.c	Tue Apr 25 10:18:57 2006
@@ -629,7 +629,7 @@
 	int		rc = OK, restsize = TX_BUF_SIZE - tty_tx_free - tty_tx_ptr;
 	boolean		wd;
 	struct timeval	tv;
-	timer_t		tm;
+	time_t		tm;
     
 	tm = timer_set( tsec );
 	while( TX_BUF_SIZE != tty_tx_free ) {
