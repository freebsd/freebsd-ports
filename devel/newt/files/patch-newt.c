
$FreeBSD$

--- newt.c
+++ newt.c
@@ -94,6 +94,9 @@
 	{ "\033[6~",		NEWT_KEY_PGDN,		NULL },
 	{ "\033V",		NEWT_KEY_PGUP, 		"kH" },
 	{ "\033v",		NEWT_KEY_PGUP, 		"kH" },
+
+	{ "\033[G",		NEWT_KEY_PGDN,		NULL },
+	{ "\033[I",		NEWT_KEY_PGUP,		NULL },
 
 	{ "\033[[A",		NEWT_KEY_F1,		NULL },
 	{ "\033[[B",		NEWT_KEY_F2,		NULL },
