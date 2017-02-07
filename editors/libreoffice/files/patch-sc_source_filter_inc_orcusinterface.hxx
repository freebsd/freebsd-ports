--- sc/source/filter/inc/orcusinterface.hxx.orig	2017-01-12 00:54:33 UTC
+++ sc/source/filter/inc/orcusinterface.hxx
@@ -357,10 +357,21 @@ public:
     virtual void set_font_name(const char* s, size_t n) override;
     virtual void set_font_size(double point) override;
     virtual void set_font_underline(orcus::spreadsheet::underline_t e) override;
+    virtual void set_font_underline_width(orcus::spreadsheet::underline_width_t e) override;
+    virtual void set_font_underline_mode(orcus::spreadsheet::underline_mode_t e) override;
+    virtual void set_font_underline_type(orcus::spreadsheet::underline_type_t e) override;
+    virtual void set_font_underline_color(orcus::spreadsheet::color_elem_t alpha,
+            orcus::spreadsheet::color_elem_t red,
+            orcus::spreadsheet::color_elem_t green,
+            orcus::spreadsheet::color_elem_t blue) override;
     virtual void set_font_color( orcus::spreadsheet::color_elem_t alpha,
             orcus::spreadsheet::color_elem_t red,
             orcus::spreadsheet::color_elem_t green,
             orcus::spreadsheet::color_elem_t blue) override;
+    virtual void set_strikethrough_style(orcus::spreadsheet::strikethrough_style_t s) override;
+    virtual void set_strikethrough_type(orcus::spreadsheet::strikethrough_type_t s) override;
+    virtual void set_strikethrough_width(orcus::spreadsheet::strikethrough_width_t s) override;
+    virtual void set_strikethrough_text(orcus::spreadsheet::strikethrough_text_t s) override;
     virtual size_t commit_font() override;
 
     // fill
@@ -381,11 +392,14 @@ public:
             orcus::spreadsheet::color_elem_t red,
             orcus::spreadsheet::color_elem_t green,
             orcus::spreadsheet::color_elem_t blue) override;
+    virtual void set_border_width(orcus::spreadsheet::border_direction_t dir, double val, orcus::length_unit_t unit) override;
     virtual size_t commit_border() override;
 
     // cell protection
     virtual void set_cell_hidden(bool b) override;
     virtual void set_cell_locked(bool b) override;
+    virtual void set_cell_print_content(bool b) override;
+    virtual void set_cell_formula_hidden(bool b) override;
     virtual size_t commit_cell_protection() override;
 
     // number format
