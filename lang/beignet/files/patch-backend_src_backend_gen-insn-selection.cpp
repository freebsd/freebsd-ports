Error: No word lists can be found for the language "en_US".
--- backend/src/backend/gen_insn_selection.cpp.orig	2015-12-18 07:34:19.000000000 +0000
+++ backend/src/backend/gen_insn_selection.cpp	2016-06-13 17:37:52.540024000 +0000
@@ -1752,11 +1752,11 @@
 
   // Boiler plate to initialize the selection library at c++ pre-main
   static SelectionLibrary *selLib = NULL;
+  __attribute__((destructor))
   static void destroySelectionLibrary(void) { GBE_DELETE(selLib); }
   static struct SelectionLibraryInitializer {
     SelectionLibraryInitializer(void) {
       selLib = GBE_NEW_NO_ARG(SelectionLibrary);
-      atexit(destroySelectionLibrary);
     }
   } selectionLibraryInitializer;
 
