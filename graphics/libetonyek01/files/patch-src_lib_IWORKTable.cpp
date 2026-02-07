* ``is_tree_valid()`` method has been renamed to ``valid_tree()``in mdds-3.0

--- src/lib/IWORKTable.cpp.orig	2024-11-05 21:56:01 UTC
+++ src/lib/IWORKTable.cpp
@@ -168,7 +168,7 @@ void writeBorder(librevenge::RVNGPropertyList &props, 
 
 void writeBorder(librevenge::RVNGPropertyList &props, const char *name, IWORKGridLine_t &line, unsigned index)
 {
-  if (!line.is_tree_valid())
+  if (!line.valid_tree())
     line.build_tree();
 
   IWORKStylePtr_t style;
