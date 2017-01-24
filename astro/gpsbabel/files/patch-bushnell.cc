https://github.com/gpsbabel/gpsbabel/issues/62

--- bushnell.cc.orig	2017-01-24 13:08:41 UTC
+++ bushnell.cc
@@ -135,7 +135,7 @@ bushnell_get_icon_from_name(QString name
     name = "Waypoint";
   }
 
-  for (t = bushnell_icons; t->icon > 0; t++) {
+  for (t = bushnell_icons; t->icon != NULL; t++) {
     if (0 == name.compare(t->icon, Qt::CaseInsensitive)) {
       return t->symbol;
     }
@@ -147,7 +147,7 @@ static const char*
 bushnell_get_name_from_symbol(signed int s)
 {
   icon_mapping_t* t;
-  for (t = bushnell_icons; t->icon > 0; t++) {
+  for (t = bushnell_icons; t->icon != NULL; t++) {
     if (s == t->symbol) {
       return t->icon;
     }
