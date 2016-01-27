--- newt.c.orig	2014-10-23 08:34:37 UTC
+++ newt.c
@@ -98,6 +98,8 @@ static const struct keymap keymap[] = {
 	{ "\033[6~",		NEWT_KEY_PGDN,		"kN" },
 	{ "\033V",		NEWT_KEY_PGUP, 		NULL },
 	{ "\033v",		NEWT_KEY_PGUP, 		NULL },
+	{ "\033[G",             NEWT_KEY_PGDN,          NULL },
+	{ "\033[I",             NEWT_KEY_PGUP,          NULL },
         { "\026",		NEWT_KEY_PGDN,		NULL },
 
 	{ "\033[[A",		NEWT_KEY_F1,		NULL },
