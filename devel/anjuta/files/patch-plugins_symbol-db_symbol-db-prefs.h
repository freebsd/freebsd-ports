--- plugins/symbol-db/symbol-db-prefs.h.orig	2009-04-17 01:06:07.000000000 -0400
+++ plugins/symbol-db/symbol-db-prefs.h	2009-04-17 01:06:34.000000000 -0400
@@ -40,7 +40,7 @@ typedef struct _SymbolDBPrefsPriv Symbol
 #include "symbol-db-system.h"
 
 
-#define CTAGS_PREFS			 "preferences_entry:text:/usr/bin/ctags:0:symboldb.ctags"
+#define CTAGS_PREFS			 "preferences_entry:text:%%LOCALBASE%%/bin/exctags:0:symboldb.ctags"
 #define CTAGS_PREFS_KEY		 "symboldb.ctags"
 #define PROJECT_AUTOSCAN	 "symboldb.scan_prj_pkgs"
 #define PARALLEL_SCAN		 "symboldb.parallel_scan"
