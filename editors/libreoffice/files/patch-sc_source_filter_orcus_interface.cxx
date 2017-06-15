--- sc/source/filter/orcus/interface.cxx.orig	2017-01-12 00:54:33 UTC
+++ sc/source/filter/orcus/interface.cxx
@@ -961,6 +961,29 @@ void ScOrcusStyles::set_font_underline(o
     }
 }
 
+void ScOrcusStyles::set_font_underline_width(orcus::spreadsheet::underline_width_t /* e */)
+{
+
+}
+
+void ScOrcusStyles::set_font_underline_mode(orcus::spreadsheet::underline_mode_t /* e */)
+{
+
+}
+
+void ScOrcusStyles::set_font_underline_type(orcus::spreadsheet::underline_type_t /* e */)
+{
+
+}
+
+void ScOrcusStyles::set_font_underline_color(orcus::spreadsheet::color_elem_t /*alpha*/,
+            orcus::spreadsheet::color_elem_t /*red*/,
+            orcus::spreadsheet::color_elem_t /*green*/,
+            orcus::spreadsheet::color_elem_t /*blue*/)
+{
+
+}
+
 void ScOrcusStyles::set_font_color(orcus::spreadsheet::color_elem_t alpha,
             orcus::spreadsheet::color_elem_t red,
             orcus::spreadsheet::color_elem_t green,
@@ -969,6 +992,22 @@ void ScOrcusStyles::set_font_color(orcus
     maCurrentFont.maColor = Color(alpha, red, green, blue);
 }
 
+void ScOrcusStyles::set_strikethrough_style(orcus::spreadsheet::strikethrough_style_t /*s*/)
+{
+}
+
+void ScOrcusStyles::set_strikethrough_type(orcus::spreadsheet::strikethrough_type_t /*s*/)
+{
+}
+
+void ScOrcusStyles::set_strikethrough_width(orcus::spreadsheet::strikethrough_width_t /*s*/)
+{
+}
+
+void ScOrcusStyles::set_strikethrough_text(orcus::spreadsheet::strikethrough_text_t /*s*/)
+{
+}
+
 size_t ScOrcusStyles::commit_font()
 {
     SAL_INFO("sc.orcus.style", "commit font");
@@ -1035,6 +1074,11 @@ void ScOrcusStyles::set_border_color(orc
     current_line.maColor = Color(alpha, red, green, blue);
 }
 
+void ScOrcusStyles::set_border_width(orcus::spreadsheet::border_direction_t /* dir */, double /* val */, orcus::length_unit_t /* unit */)
+{
+
+}
+
 size_t ScOrcusStyles::commit_border()
 {
     SAL_INFO("sc.orcus.style", "commit border");
@@ -1054,6 +1098,16 @@ void ScOrcusStyles::set_cell_locked(bool
     maCurrentProtection.mbLocked = b;
 }
 
+void ScOrcusStyles::set_cell_print_content(bool /* b */)
+{
+
+}
+
+void ScOrcusStyles::set_cell_formula_hidden(bool /* b */)
+{
+
+}
+
 size_t ScOrcusStyles::commit_cell_protection()
 {
     SAL_INFO("sc.orcus.style", "commit cell protection");
