--- ../../hotspot/src/share/vm/opto/escape.cpp	21 Jul 2006 17:22:54 -0000	1.1.1.2
+++ ../../hotspot/src/share/vm/opto/escape.cpp	9 Aug 2007 16:24:59 -0000	1.3
@@ -35,21 +35,21 @@
 }
 
 #ifndef PRODUCT
-static char *node_type_names[] = {
+static const char *node_type_names[] = {
   "UnknownType",
   "JavaObject",
   "LocalVar",
   "Field"
 };
 
-static char *esc_names[] = {
+static const char *esc_names[] = {
   "UnknownEscape",
   "NoEscape     ",
   "ArgEscape    ",
   "GlobalEscape "
 };
 
-static char *edge_type_suffix[] = {
+static const char *edge_type_suffix[] = {
  "?", // UnknownEdge
  "P", // PointsToEdge
  "D", // DeferredEdge
