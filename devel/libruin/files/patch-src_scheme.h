--- src/scheme.h.orig	2011-09-16 14:29:42 UTC
+++ src/scheme.h
@@ -23,7 +23,7 @@
 #include "layout.h"
 #include "window.h"
 
-SCM ruin_scheme_scss_document_interface_sdom;
+extern SCM ruin_scheme_scss_document_interface_sdom;
 
 SCM ruin_scheme_scss_color_to_hex (ruin_window_t *, char *);
 void ruin_scheme_scss_set_cascade_author (ruin_window_t *, SCM, SCM);
@@ -71,11 +71,11 @@ int ruin_scheme_sdom_text_node_p (ruin_window_t *, SCM
 char *ruin_scheme_sdom_value (ruin_window_t *, SCM);
 SCM ruin_scheme_sdom_xml_to_sdom (ruin_window_t *, SCM, SCM);
 
-SCM ruin_scheme_sdom_node_type_attr;
-SCM ruin_scheme_sdom_node_type_element;
-SCM ruin_scheme_sdom_node_type_document;
-SCM ruin_scheme_sdom_node_type_processing_instruction;
-SCM ruin_scheme_sdom_node_type_text;
+extern SCM ruin_scheme_sdom_node_type_attr;
+extern SCM ruin_scheme_sdom_node_type_element;
+extern SCM ruin_scheme_sdom_node_type_document;
+extern SCM ruin_scheme_sdom_node_type_processing_instruction;
+extern SCM ruin_scheme_sdom_node_type_text;
 
 void ruin_scheme_init();
 
