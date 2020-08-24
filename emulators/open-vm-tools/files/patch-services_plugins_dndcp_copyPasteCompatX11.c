--- services/plugins/dndcp/copyPasteCompatX11.c.orig	2020-08-24 00:33:01 UTC
+++ services/plugins/dndcp/copyPasteCompatX11.c
@@ -73,11 +73,11 @@ GdkAtom GDK_SELECTION_CLIPBOARD;
 #endif
 
 #ifndef GDK_SELECTION_TYPE_TIMESTAMP
-GdkAtom GDK_SELECTION_TYPE_TIMESTAMP;
+extern GdkAtom GDK_SELECTION_TYPE_TIMESTAMP;
 #endif
 
 #ifndef GDK_SELECTION_TYPE_UTF8_STRING
-GdkAtom GDK_SELECTION_TYPE_UTF8_STRING;
+extern GdkAtom GDK_SELECTION_TYPE_UTF8_STRING;
 #endif
 
 /*
