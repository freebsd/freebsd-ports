--- backend/src/backend/gen_insn_selection.cpp.orig	2015-08-26 11:57:48.961363000 +0200
+++ backend/src/backend/gen_insn_selection.cpp	2015-08-26 11:58:15.326657000 +0200
@@ -1752,11 +1752,11 @@ namespace gbe
 
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
 
