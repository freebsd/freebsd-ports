--- sc/source/filter/inc/orcusinterface.hxx.orig	2017-10-25 14:25:39 UTC
+++ sc/source/filter/inc/orcusinterface.hxx
@@ -183,7 +183,8 @@ class ScOrcusSheetProperties : public orcus::spreadshe
 
     virtual void set_row_hidden(orcus::spreadsheet::row_t row, bool hidden) override;
 
-    virtual void set_merge_cell_range(const char* p_range, size_t n_range) override;
+
+    virtual void set_merge_cell_range(const orcus::spreadsheet::range_t& range) override;
 };
 
 class ScOrcusSheet : public orcus::spreadsheet::iface::import_sheet
@@ -243,6 +244,8 @@ class ScOrcusSheet : public orcus::spreadsheet::iface:
         orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, orcus::spreadsheet::formula_grammar_t grammar,
         const char* p, size_t n, const char* p_range, size_t n_range) override;
 
+    virtual orcus::spreadsheet::range_size_t get_sheet_size() const override;
+
     SCTAB getIndex() const { return mnTab; }
 };
 
@@ -418,7 +421,7 @@ class ScOrcusStyles : public orcus::spreadsheet::iface
     // border
 
     virtual void set_border_count(size_t n) override;
-    virtual void set_border_style(orcus::spreadsheet::border_direction_t dir, const char* s, size_t n) override;
+
     virtual void set_border_style(orcus::spreadsheet::border_direction_t dir, orcus::spreadsheet::border_style_t style) override;
     virtual void set_border_color(orcus::spreadsheet::border_direction_t dir,
             orcus::spreadsheet::color_elem_t alpha,
@@ -508,7 +511,8 @@ class ScOrcusFactory : public orcus::spreadsheet::ifac
 public:
     ScOrcusFactory(ScDocument& rDoc);
 
-    virtual orcus::spreadsheet::iface::import_sheet* append_sheet(const char *sheet_name, size_t sheet_name_length) override;
+    virtual orcus::spreadsheet::iface::import_sheet* append_sheet(
+        orcus::spreadsheet::sheet_t sheet_index, const char *sheet_name, size_t sheet_name_length) override;
     virtual orcus::spreadsheet::iface::import_sheet* get_sheet(const char *sheet_name, size_t sheet_name_length) override;
     virtual orcus::spreadsheet::iface::import_sheet* get_sheet(orcus::spreadsheet::sheet_t sheet_index) override;
     virtual orcus::spreadsheet::iface::import_global_settings* get_global_settings() override;
