--- cdr_read.c.orig	Tue Oct  8 09:39:55 2002
+++ cdr_read.c	Mon Jul  5 11:14:12 2004
@@ -696,28 +696,27 @@
 	struct LogType *lt;
 
 	fprintf( stderr,
-"
-CDR Reader for PBXs v.%s (C) Alexey V. Kuznetsov, avk@gamma.ru, 2001-2002
-cdr_read [-D dir] [-L logfile] [-s speed] [-c csize] [-p parity] [-f sbits]
-	 [-t type] [-d] [-e] [-a] [-o] dev
--D dir		directory where CDR files will be put, default is current dir
--L logfile	file for error messages, default is stderr
--s speed	speed of serial device, default 9600
--c char_size	length of character; valid values from 5 to 8
--p parity	parity of serial device:
-		e - even parity, o - odd parity, n - no parity,
-		m - mark parity (Win32 only), s - space parity (Win32 only)
--f stop_bits	number of stop bits; valid values 1 or 2
--d		output additional debug messages
--e		copy error messages to stderr (in case if -L has value)
--a		write date at the beginning of file (for Definity type only)
--o		write CDR additionally to stdout
--m		write log files on month-by-month instead of day-by-day basis
--n		consider day in place of month and vice versa
--r x.x.x.x	accept TCP connections from this IP address only
--w seconds	timeout before I/O port will be opened next time after EOF
--t cdr_type	type of CDR records, valid values (first is default)
-",CDRR_VER);
+"\n" \
+"CDR Reader for PBXs v.%s (C) Alexey V. Kuznetsov, avk@gamma.ru, 2001-2002\n" \
+"cdr_read [-D dir] [-L logfile] [-s speed] [-c csize] [-p parity] [-f sbits]\n" \
+"	 [-t type] [-d] [-e] [-a] [-o] dev\n" \
+"-D dir		directory where CDR files will be put, default is current dir\n" \
+"-L logfile	file for error messages, default is stderr\n" \
+"-s speed	speed of serial device, default 9600\n" \
+"-c char_size	length of character; valid values from 5 to 8\n" \
+"-p parity	parity of serial device:\n" \
+"		e - even parity, o - odd parity, n - no parity,\n" \
+"		m - mark parity (Win32 only), s - space parity (Win32 only)\n" \
+"-f stop_bits	number of stop bits; valid values 1 or 2\n" \
+"-d		output additional debug messages\n" \
+"-e		copy error messages to stderr (in case if -L has value)\n" \
+"-a		write date at the beginning of file (for Definity type only)\n" \
+"-o		write CDR additionally to stdout\n" \
+"-m		write log files on month-by-month instead of day-by-day basis\n" \
+"-n		consider day in place of month and vice versa\n" \
+"-r x.x.x.x	accept TCP connections from this IP address only\n" \
+"-w seconds	timeout before I/O port will be opened next time after EOF\n" \
+"-t cdr_type	type of CDR records, valid values (first is default)\n",CDRR_VER);
 	for( lt=logtypes; lt->name!=NULL; lt++ ) {
 		fprintf( stderr,"\t%s",lt->name );
 	}
