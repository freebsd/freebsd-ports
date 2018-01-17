--- sc/source/filter/orcus/interface.cxx.orig	2017-10-25 14:25:39 UTC
+++ sc/source/filter/orcus/interface.cxx
@@ -84,7 +84,8 @@ ScOrcusFactory::ScOrcusFactory(ScDocument& rDoc) :
     maStyles(rDoc),
     mnProgress(0) {}
 
-orcus::spreadsheet::iface::import_sheet* ScOrcusFactory::append_sheet(const char* sheet_name, size_t sheet_name_length)
+orcus::spreadsheet::iface::import_sheet* ScOrcusFactory::append_sheet(
+    orcus::spreadsheet::sheet_t /*sheet_index*/, const char* sheet_name, size_t sheet_name_length)
 {
     OUString aTabName(sheet_name, sheet_name_length, RTL_TEXTENCODING_UTF8);
     if (!maDoc.appendSheet(aTabName))
@@ -296,7 +297,7 @@ void ScOrcusSheetProperties::set_row_hidden(os::row_t 
         mrDoc.getDoc().SetRowHidden(row, row, mnTab, hidden);
 }
 
-void ScOrcusSheetProperties::set_merge_cell_range(const char* /*p_range*/, size_t /*n_range*/)
+void ScOrcusSheetProperties::set_merge_cell_range(const orcus::spreadsheet::range_t& /*range*/)
 {
 }
 
@@ -576,6 +577,9 @@ formula::FormulaGrammar::Grammar getCalcGrammarFromOrc
         case orcus::spreadsheet::formula_grammar_t::gnumeric:
             eGrammar = formula::FormulaGrammar::GRAM_ENGLISH_XL_A1;
             break;
+        case orcus::spreadsheet::formula_grammar_t::xls_xml:
+            eGrammar = formula::FormulaGrammar::GRAM_ENGLISH_XL_R1C1;
+            break;
         case orcus::spreadsheet::formula_grammar_t::unknown:
             break;
     }
@@ -693,6 +697,15 @@ void ScOrcusSheet::set_array_formula(
 {
 }
 
+orcus::spreadsheet::range_size_t ScOrcusSheet::get_sheet_size() const
+{
+    orcus::spreadsheet::range_size_t ret;
+    ret.rows = MAXROWCOUNT;
+    ret.columns = MAXCOLCOUNT;
+
+    return ret;
+}
+
 ScOrcusSharedStrings::ScOrcusSharedStrings(ScOrcusFactory& rFactory) :
     mrFactory(rFactory) {}
 
@@ -1281,11 +1294,6 @@ size_t ScOrcusStyles::commit_fill()
 void ScOrcusStyles::set_border_count(size_t /*n*/)
 {
     // needed at all?
-}
-
-void ScOrcusStyles::set_border_style(orcus::spreadsheet::border_direction_t /*dir*/, const char* /*s*/, size_t /*n*/)
-{
-    // implement later
 }
 
 void ScOrcusStyles::set_border_style(
