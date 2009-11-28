--- plugins/symbol-db/symbol-db-prefs.h.orig	2009-07-27 16:14:31.000000000 +0200
+++ plugins/symbol-db/symbol-db-prefs.h	2009-07-28 00:10:49.000000000 +0200
@@ -41,7 +41,7 @@ typedef struct _SymbolDBPrefsPriv Symbol
 
 
 /*
-#define CTAGS_PREFS			 "preferences_entry:text:/usr/bin/ctags:0:symboldb.ctags"
+#define CTAGS_PREFS			 "preferences_entry:text:%%LOCALBASE%%/bin/ctags:0:symboldb.ctags"
 #define CTAGS_PREFS_KEY		 "symboldb.ctags"
  */
 #define PROJECT_AUTOSCAN	 "symboldb.scan_prj_pkgs"
