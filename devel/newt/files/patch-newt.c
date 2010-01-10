
$FreeBSD$

--- newt.c	2009-09-24 11:03:09.000000000 -0400
+++ newt.c	2010-01-06 01:04:01.000000000 -0500
@@ -99,4 +99,6 @@
 	{ "\033V",		NEWT_KEY_PGUP, 		NULL },
 	{ "\033v",		NEWT_KEY_PGUP, 		NULL },
+	{ "\033[G",             NEWT_KEY_PGDN,          NULL },
+	{ "\033[I",             NEWT_KEY_PGUP,          NULL },
         { "\026",		NEWT_KEY_PGDN,		NULL },
 
