Error: No word lists can be found for the language "en_US".
--- backend/src/backend/gen_insn_selection.cpp.orig	2017-01-20 10:40:51 UTC
+++ backend/src/backend/gen_insn_selection.cpp
@@ -2456,11 +2456,11 @@ namespace gbe
 
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
 
