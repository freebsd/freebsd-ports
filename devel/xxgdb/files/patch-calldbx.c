--- calldbx.c.orig	1995-06-19 15:11:00.000000000 -0700
+++ calldbx.c	2014-03-26 12:20:00.741924675 -0700
@@ -74,8 +74,16 @@
 #include <string.h>
 #include <fcntl.h>
 #include "global.h"
-#if !(defined(OLDSUNOS) || defined(BSD))
-#include <termio.h>
+#if !(defined(OLDSUNOS) || defined(BSD)) || defined(__FreeBSD__)
+#include <termios.h>
+#include <sys/param.h>
+#if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
+#define NEW_FREEBSD_PTYS
+#include <sys/types.h>
+#include <sys/ioctl.h>
+#include <termios.h>
+#include <libutil.h>
+#endif
 #else
 #include <sgtty.h>
 #endif
@@ -116,6 +124,7 @@
 char            iowintty[] = "/dev/ttyp0";
 int             iowinpid = 0;
 #endif /* CREATE_IO_WINDOW */
+#ifndef NEW_FREEBSD_PTYS
 /*
  *  Xdbx talks to dbx through a pseudo terminal which is a pair of master
  *  and slave devices: /dev/pty?? and /dev/tty??, where ?? goes from p0 to
@@ -137,13 +146,17 @@
 
 #ifndef sco
 	for (c='p'; c<'t'; c++) {
+#ifdef __FreeBSD__
+	for (i=0; i<32; i++) {
+#else
 	for (i=0; i<16; i++) {
+#endif
 #else
 	c = 'p';
 	for (i=0; i<8; i++) {
 #endif
 	    pty[8] = c;
-	    pty[9] = "0123456789abcdef"[i];
+	    pty[9] = "0123456789abcdefghijklmnopqrstuv"[i];
 	    if ((master = open(pty, O_RDWR)) >= 0) 
 		return (master); 
 	}
@@ -194,6 +207,7 @@
     return slave;
 #endif /* SVR4 */
 }
+#endif /* NEW_FREEBSD_PTYS */
 
 #ifdef CREATE_IO_WINDOW 
 /* use a separate io window to talk to gdb, so program output is not confused with gdb output. */
@@ -246,8 +260,8 @@
 /*
  * (JBL)10MAY91 : use sgttyb if generic BSD
  */
-#if !(defined(OLDSUNOS) || defined(BSD))
-    struct termio Termio;
+#if !(defined(OLDSUNOS) || defined(BSD)) || defined(__FreeBSD__)
+    struct termios Termio;
 #else
     struct sgttyb Termio;
 #endif
@@ -261,8 +275,10 @@
 
 #ifdef GDB	/* for GDB, we use XXGDB_DEBUGGER instead */
     debugger = (char *) getenv("XXGDB_DEBUGGER");	/* first looks up env var */
+    dbxprompt = (char *) getenv("XXGDB_DBXPROMPT");	/* first looks up env var */
 #else
     debugger = (char *) getenv("DEBUGGER");	/* first looks up env var */
+    dbxprompt = (char *) getenv("DBXPROMPT");	/* first looks up env var */
 #endif
 
 /* CRL mod 4 3/15/91 GWC if no env var then try app res for db_name */
@@ -275,7 +291,8 @@
 	debugger  = XtNewString(DEBUGGER);
 
 /* CRL mod 4 3/15/91 GWC -  allow the user to specify a db_prompt */
-    if (app_resources.db_prompt &&
+    if (dbxprompt == NULL &&
+	app_resources.db_prompt &&
 	strcmp(app_resources.db_prompt, "") != 0)
 	dbxprompt = XtNewString(app_resources.db_prompt);
   
@@ -288,7 +305,15 @@
 	if (debug)
 		fprintf(stderr,"debugger=\"%s\"\nprompt=\"%s\"\n",debugger,dbxprompt);
   
+#ifdef NEW_FREEBSD_PTYS
+    if (openpty(&master, &slave, NULL, NULL, NULL) == -1) {
+	sprintf(errmsg,"%s error: openpty failed\n");
+	perror(errmsg);
+	exit(1);
+    }
+#else
     master = open_master();
+#endif
 
     dbxpid = fork();
     if (dbxpid == -1) {
@@ -305,6 +330,7 @@
 	 *	    set line buffered mode
 	 *	    register dbx input with X
 	 */
+	close(slave);
 	close(0);
 	close(1);
 
@@ -345,7 +371,9 @@
 	}
 #endif
 
+#ifndef NEW_FREEBSD_PTYS
 	slave = open_slave(master);
+#endif
 	close(master);
 
 	/*
@@ -355,11 +383,11 @@
 	/*
 	 * (JBL)10MAY91 : use sgttyb if OLDSUN or generic BSD
 	 */ 
-#if !(defined(OLDSUNOS) || defined(BSD))
-	ioctl(slave, TCGETA, &Termio);
+#if !(defined(OLDSUNOS) || defined(BSD)) || defined(__FreeBSD__)
+	tcgetattr(slave, &Termio);
 	Termio.c_lflag &= ~ECHO;	/* No echo */
 	Termio.c_oflag &= ~ONLCR;	/* Do not map NL to CR-NL on output */
-	ioctl(slave, TCSETA, &Termio);
+	tcsetattr(slave, TCSANOW, &Termio);
 #else
 	ioctl(slave, TIOCGETP, &Termio);
 	Termio.sg_flags &= ~ECHO;	/* No echo */
