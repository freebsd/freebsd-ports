--- plugins/symbol-db/plugin.h.orig	2009-04-17 01:02:20.000000000 -0400
+++ plugins/symbol-db/plugin.h	2009-04-17 01:02:37.000000000 -0400
@@ -49,7 +49,7 @@ typedef struct _SymbolDBPluginClass Symb
 #include "symbol-db-prefs.h"
 
 /* a sort of 'default' value for ctags executable. User must have it installed */
-#define CTAGS_PATH			"/usr/bin/ctags"
+#define CTAGS_PATH			"%%LOCALBASE%%/bin/exctags"
 
 struct _SymbolDBPlugin {
 	AnjutaPlugin parent;
