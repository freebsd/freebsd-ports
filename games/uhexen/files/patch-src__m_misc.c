--- src/m_misc.c.orig	Tue May  3 10:56:39 2005
+++ src/m_misc.c	Tue May  3 10:57:24 2005
@@ -440,7 +440,7 @@
 {
 	char    *name;
 	int     *location;
-	int     defaultvalue;
+	intptr_t defaultvalue;
 	int     scantranslate;      // PC scan code hack
 	int     untranslated;       // lousy hack
 } default_t;
@@ -503,20 +503,20 @@
 
 #define DEFAULT_SAVEPATH		"hexndata/"
 
-	{ "savedir", (int *) &SavePath, (int) DEFAULT_SAVEPATH },
+	{ "savedir", (int *) &SavePath, (intptr_t) DEFAULT_SAVEPATH },
 
 	{ "messageson", (int *) &messageson, 1 },
         { "speed_lock", (int *) &speed_lock, 1 },
-	{ "chatmacro0", (int *) &chat_macros[0], (int) HUSTR_CHATMACRO0 },
-	{ "chatmacro1", (int *) &chat_macros[1], (int) HUSTR_CHATMACRO1 },
-	{ "chatmacro2", (int *) &chat_macros[2], (int) HUSTR_CHATMACRO2 },
-	{ "chatmacro3", (int *) &chat_macros[3], (int) HUSTR_CHATMACRO3 },
-	{ "chatmacro4", (int *) &chat_macros[4], (int) HUSTR_CHATMACRO4 },
-	{ "chatmacro5", (int *) &chat_macros[5], (int) HUSTR_CHATMACRO5 },
-	{ "chatmacro6", (int *) &chat_macros[6], (int) HUSTR_CHATMACRO6 },
-	{ "chatmacro7", (int *) &chat_macros[7], (int) HUSTR_CHATMACRO7 },
-	{ "chatmacro8", (int *) &chat_macros[8], (int) HUSTR_CHATMACRO8 },
-	{ "chatmacro9", (int *) &chat_macros[9], (int) HUSTR_CHATMACRO9 }
+	{ "chatmacro0", (int *) &chat_macros[0], (intptr_t) HUSTR_CHATMACRO0 },
+	{ "chatmacro1", (int *) &chat_macros[1], (intptr_t) HUSTR_CHATMACRO1 },
+	{ "chatmacro2", (int *) &chat_macros[2], (intptr_t) HUSTR_CHATMACRO2 },
+	{ "chatmacro3", (int *) &chat_macros[3], (intptr_t) HUSTR_CHATMACRO3 },
+	{ "chatmacro4", (int *) &chat_macros[4], (intptr_t) HUSTR_CHATMACRO4 },
+	{ "chatmacro5", (int *) &chat_macros[5], (intptr_t) HUSTR_CHATMACRO5 },
+	{ "chatmacro6", (int *) &chat_macros[6], (intptr_t) HUSTR_CHATMACRO6 },
+	{ "chatmacro7", (int *) &chat_macros[7], (intptr_t) HUSTR_CHATMACRO7 },
+	{ "chatmacro8", (int *) &chat_macros[8], (intptr_t) HUSTR_CHATMACRO8 },
+	{ "chatmacro9", (int *) &chat_macros[9], (intptr_t) HUSTR_CHATMACRO9 }
 };
 
 int numdefaults;
