--- tools/aiksaurus/xp/AiksaurusABI.cpp.orig	Fri Aug 13 21:09:34 2004
+++ tools/aiksaurus/xp/AiksaurusABI.cpp	Fri Aug 13 21:10:33 2004
@@ -310,11 +310,11 @@
     pView->extSelTo(FV_DOCPOS_EOW_SELECT);  
 	
     // Now we will figure out what word to look up when we open our dialog.
-    char* search = "";
+    char* search = NULL;
     if (!pView->isSelectionEmpty())
     {
         // We need to get the Ascii version of the current word.
-        UT_UCS4Char * ucs4ST;
+	 UT_UCS4Char * ucs4ST;
 	 pView->getSelectionText(*&ucs4ST);
 	 search = AiksaurusABI_ucsToAscii(
 					 ucs4ST
