--- sc/inc/document.hxx	2013-06-11 05:33:38.000000000 -0400
+++ sc/inc/document.hxx	2013-06-24 19:08:23.000000000 -0400
@@ -750,6 +750,7 @@
     SC_DLLPUBLIC bool           SetString(
         SCCOL nCol, SCROW nRow, SCTAB nTab, const rtl::OUString& rString,
         ScSetStringParam* pParam = NULL );
+    SC_DLLPUBLIC bool SetString( const ScAddress& rPos, const OUString& rString, ScSetStringParam* pParam = NULL );
     SC_DLLPUBLIC void           SetValue( SCCOL nCol, SCROW nRow, SCTAB nTab, const double& rVal );
     void            SetError( SCCOL nCol, SCROW nRow, SCTAB nTab, const sal_uInt16 nError);
 
--- sc/inc/orcusfilters.hxx	2013-06-11 05:33:38.000000000 -0400
+++ sc/inc/orcusfilters.hxx	2013-06-24 19:08:23.000000000 -0400
@@ -30,6 +30,10 @@
 
     virtual bool importGnumeric(ScDocument& rDoc, const rtl::OUString& rPath) const = 0;
 
+    virtual bool importXLSX(ScDocument& rDoc, const rtl::OUString& rPath) const = 0;
+
+    virtual bool importODS(ScDocument& rDoc, const rtl::OUString& rPath) const = 0;
+
     /**
      * Create a context for XML file.  The context object stores session
      * information for each unique XML file.  You must create a new context
--- sc/inc/stringutil.hxx	2013-06-11 05:33:38.000000000 -0400
+++ sc/inc/stringutil.hxx	2013-06-24 19:08:23.000000000 -0400
@@ -72,16 +72,26 @@
     TextFormatPolicy meSetTextNumFormat;
 
     /**
-     * When true, treat input with a leading apostrophe / single quote special
-     * in that it escapes numeric or date/time input such that it is not
-     * interpreted and the input string is taken instead. This can be used
-     * during text file import so the leading apostrophe is not lost if it
-     * precedes a numeric value.
-     * Usually set mbHandleApostrophe = !mbSetTextCellFormat
+     * When true, treat input with a leading apostrophe as an escape character
+     * for a numeric value content, to treat the numeric value as a text. When
+     * false, the whole string input including the leading apostrophe will be
+     * entered literally as string.
      */
     bool mbHandleApostrophe;
 
     ScSetStringParam();
+
+    /**
+     * Call this whenever you need to unconditionally set input as text, no
+     * matter what the input is.
+     */
+    void setTextInput();
+
+    /**
+     * Call this whenever you need to maximize the chance of input being
+     * detected as a numeric value (numbers, dates, times etc).
+     */
+    void setNumericInput();
 };
 
 // ============================================================================
--- sc/source/core/data/document.cxx	2013-06-11 05:33:38.000000000 -0400
+++ sc/source/core/data/document.cxx	2013-06-24 19:08:23.000000000 -0400
@@ -2940,6 +2940,12 @@
         return false;
 }
 
+bool ScDocument::SetString(
+    const ScAddress& rPos, const OUString& rString, ScSetStringParam* pParam )
+{
+    return SetString(rPos.Col(), rPos.Row(), rPos.Tab(), rString, pParam);
+}
+
 
 void ScDocument::SetValue( SCCOL nCol, SCROW nRow, SCTAB nTab, const double& rVal )
 {
--- sc/source/core/tool/stringutil.cxx	2013-06-11 05:33:38.000000000 -0400
+++ sc/source/core/tool/stringutil.cxx	2013-06-24 19:08:23.000000000 -0400
@@ -32,6 +32,20 @@
 {
 }
 
+void ScSetStringParam::setTextInput()
+{
+    mbDetectNumberFormat = false;
+    mbHandleApostrophe = false;
+    meSetTextNumFormat = Always;
+}
+
+void ScSetStringParam::setNumericInput()
+{
+    mbDetectNumberFormat = true;
+    mbHandleApostrophe = true;
+    meSetTextNumFormat = Never;
+}
+
 // ============================================================================-
 
 bool ScStringUtil::parseSimpleNumber(
--- sc/source/filter/inc/orcusfiltersimpl.hxx	2013-06-11 05:33:38.000000000 -0400
+++ sc/source/filter/inc/orcusfiltersimpl.hxx	2013-06-24 19:08:23.000000000 -0400
@@ -22,6 +22,8 @@
 
     virtual bool importCSV(ScDocument& rDoc, const rtl::OUString& rPath) const;
     virtual bool importGnumeric(ScDocument& rDoc, const rtl::OUString& rPath) const;
+    virtual bool importXLSX(ScDocument& rDoc, const rtl::OUString& rPath) const;
+    virtual bool importODS(ScDocument& rDoc, const rtl::OUString& rPath) const;
 
     virtual ScOrcusXMLContext* createXMLContext(ScDocument& rDoc, const rtl::OUString& rPath) const;
 };
--- sc/source/filter/inc/orcusinterface.hxx	2013-06-11 05:33:38.000000000 -0400
+++ sc/source/filter/inc/orcusinterface.hxx	2013-06-24 19:08:23.000000000 -0400
@@ -21,13 +21,26 @@
 
 class ScDocument;
 class ScOrcusSheet;
+class ScOrcusFactory;
 class ScRangeData;
 
+class ScOrcusGlobalSettings : public orcus::spreadsheet::iface::import_global_settings
+{
+    ScDocument& mrDoc;
+
+public:
+    ScOrcusGlobalSettings(ScDocument& rDoc);
+
+    virtual void set_origin_date(int year, int month, int day);
+};
+
 class ScOrcusSharedStrings : public orcus::spreadsheet::iface::import_shared_strings
 {
-    std::vector<OUString> maSharedStrings;
+    std::vector<OUString>& mrStrings;
 
 public:
+    ScOrcusSharedStrings(std::vector<OUString>& rStrings);
+
     virtual size_t append(const char* s, size_t n);
     virtual size_t add(const char* s, size_t n);
 
@@ -38,50 +51,49 @@
     virtual void append_segment(const char* s, size_t n);
 
     virtual size_t commit_segments();
-
-    const OUString& getByIndex(size_t index) const;
-};
-
-class ScOrcusFactory : public orcus::spreadsheet::iface::import_factory
-{
-    ScDocument& mrDoc;
-    boost::ptr_vector<ScOrcusSheet> maSheets;
-    ScOrcusSharedStrings maSharedStrings;
-
-public:
-    ScOrcusFactory(ScDocument& rDoc);
-
-    virtual orcus::spreadsheet::iface::import_sheet* append_sheet(const char *sheet_name, size_t sheet_name_length);
-    virtual orcus::spreadsheet::iface::import_sheet* get_sheet(const char *sheet_name, size_t sheet_name_length);
-    virtual orcus::spreadsheet::iface::import_shared_strings* get_shared_strings();
-    virtual orcus::spreadsheet::iface::import_styles* get_styles();
 };
 
 class ScOrcusSheet : public orcus::spreadsheet::iface::import_sheet
 {
     ScDocument& mrDoc;
     SCTAB mnTab;
-    ScOrcusSharedStrings& mrSharedStrings;
+    ScOrcusFactory& mrFactory;
 
     typedef std::map<size_t, ScRangeData*> SharedFormulaContainer;
     SharedFormulaContainer maSharedFormulas;
 public:
-    ScOrcusSheet(ScDocument& rDoc, SCTAB nTab, ScOrcusSharedStrings& rSharedStrings);
+    ScOrcusSheet(ScDocument& rDoc, SCTAB nTab, ScOrcusFactory& rFactory);
 
     // Orcus import interface
     virtual void set_auto(orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, const char* p, size_t n);
+    virtual void set_string(orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, size_t sindex);
+    virtual void set_value(orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, double value);
+    virtual void set_bool(orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, bool value);
+    virtual void set_date_time(
+        orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, int year, int month, int day, int hour, int minute, double second);
+
     virtual void set_format(orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, size_t xf_index);
+
     virtual void set_formula(orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, orcus::spreadsheet::formula_grammar_t grammar, const char* p, size_t n);
     virtual void set_formula_result(orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, const char* p, size_t n);
+
     virtual void set_shared_formula(
         orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, orcus::spreadsheet::formula_grammar_t grammar, size_t sindex,
         const char* p_formula, size_t n_formula);
+
     virtual void set_shared_formula(
         orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, orcus::spreadsheet::formula_grammar_t grammar, size_t sindex,
         const char* p_formula, size_t n_formula, const char* p_range, size_t n_range);
+
     virtual void set_shared_formula(orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, size_t sindex);
-    virtual void set_string(orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, size_t sindex);
-    virtual void set_value(orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, double value);
+
+    virtual void set_array_formula(
+        orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, orcus::spreadsheet::formula_grammar_t grammar,
+        const char* p, size_t n, orcus::spreadsheet::row_t array_rows, orcus::spreadsheet::col_t array_cols);
+
+    virtual void set_array_formula(
+        orcus::spreadsheet::row_t row, orcus::spreadsheet::col_t col, orcus::spreadsheet::formula_grammar_t grammar,
+        const char* p, size_t n, const char* p_range, size_t n_range);
 
     SCTAB getIndex() const { return mnTab; }
 };
@@ -119,6 +131,10 @@
     virtual void set_cell_locked(bool b);
     virtual size_t commit_cell_protection();
 
+    // number format
+    virtual void set_number_format(const char* s, size_t n);
+    virtual size_t commit_number_format();
+
     // cell style xf
 
     virtual void set_cell_style_xf_count(size_t n);
@@ -147,5 +163,38 @@
     virtual size_t commit_cell_style();
 };
 
+class ScOrcusFactory : public orcus::spreadsheet::iface::import_factory
+{
+    struct StringCellCache
+    {
+        ScAddress maPos;
+        size_t mnIndex;
+
+        StringCellCache(const ScAddress& rPos, size_t nIndex);
+    };
+
+    typedef std::vector<StringCellCache> StringCellCaches;
+
+    ScDocument& mrDoc;
+    std::vector<OUString> maStrings;
+    StringCellCaches maStringCells;
+    ScOrcusGlobalSettings maGlobalSettings;
+    ScOrcusSharedStrings maSharedStrings;
+    boost::ptr_vector<ScOrcusSheet> maSheets;
+    ScOrcusStyles maStyles;
+
+public:
+    ScOrcusFactory(ScDocument& rDoc);
+
+    virtual orcus::spreadsheet::iface::import_sheet* append_sheet(const char *sheet_name, size_t sheet_name_length);
+    virtual orcus::spreadsheet::iface::import_sheet* get_sheet(const char *sheet_name, size_t sheet_name_length);
+    virtual orcus::spreadsheet::iface::import_global_settings* get_global_settings();
+    virtual orcus::spreadsheet::iface::import_shared_strings* get_shared_strings();
+    virtual orcus::spreadsheet::iface::import_styles* get_styles();
+    virtual void finalize();
+
+    void pushStringCell(const ScAddress& rPos, size_t nStrIndex);
+};
+
 #endif
 /* vim:set shiftwidth=4 softtabstop=4 expandtab: */
--- sc/source/filter/orcus/interface.cxx	2013-06-11 05:33:38.000000000 -0400
+++ sc/source/filter/orcus/interface.cxx	2013-06-24 19:08:23.000000000 -0400
@@ -13,14 +13,34 @@
 #include "cell.hxx"
 #include "rangenam.hxx"
 #include "tokenarray.hxx"
-#include <formula/token.hxx>
+#include "stringutil.hxx"
+#include "docoptio.hxx"
 
+#include "formula/token.hxx"
+#include "tools/datetime.hxx"
+
+#define D_TIMEFACTOR              86400.0
 
 using orcus::spreadsheet::row_t;
 using orcus::spreadsheet::col_t;
 using orcus::spreadsheet::formula_grammar_t;
 
-ScOrcusFactory::ScOrcusFactory(ScDocument& rDoc) : mrDoc(rDoc) {}
+ScOrcusGlobalSettings::ScOrcusGlobalSettings(ScDocument& rDoc) : mrDoc(rDoc) {}
+
+void ScOrcusGlobalSettings::set_origin_date(int year, int month, int day)
+{
+    ScDocOptions aOpt = mrDoc.GetDocOptions();
+    aOpt.SetDate(year, month, day);
+    mrDoc.SetDocOptions(aOpt);
+}
+
+ScOrcusFactory::StringCellCache::StringCellCache(const ScAddress& rPos, size_t nIndex) :
+    maPos(rPos), mnIndex(nIndex) {}
+
+ScOrcusFactory::ScOrcusFactory(ScDocument& rDoc) :
+    mrDoc(rDoc),
+    maGlobalSettings(mrDoc),
+    maSharedStrings(maStrings) {}
 
 orcus::spreadsheet::iface::import_sheet* ScOrcusFactory::append_sheet(const char* sheet_name, size_t sheet_name_length)
 {
@@ -29,7 +49,7 @@
         return NULL;
 
     SCTAB nTab = mrDoc.GetTableCount() - 1;
-    maSheets.push_back(new ScOrcusSheet(mrDoc, nTab, maSharedStrings));
+    maSheets.push_back(new ScOrcusSheet(mrDoc, nTab, *this));
     return &maSheets.back();
 }
 
@@ -61,10 +81,15 @@
         return &(*it);
 
     // Create a new orcus sheet instance for this.
-    maSheets.push_back(new ScOrcusSheet(mrDoc, nTab, maSharedStrings));
+    maSheets.push_back(new ScOrcusSheet(mrDoc, nTab, *this));
     return &maSheets.back();
 }
 
+orcus::spreadsheet::iface::import_global_settings* ScOrcusFactory::get_global_settings()
+{
+    return &maGlobalSettings;
+}
+
 orcus::spreadsheet::iface::import_shared_strings* ScOrcusFactory::get_shared_strings()
 {
     return &maSharedStrings;
@@ -73,11 +98,31 @@
 orcus::spreadsheet::iface::import_styles* ScOrcusFactory::get_styles()
 {
     // We don't support it yet.
-    return new ScOrcusStyles;
+    return &maStyles;
 }
 
-ScOrcusSheet::ScOrcusSheet(ScDocument& rDoc, SCTAB nTab, ScOrcusSharedStrings& rSharedStrings) :
-    mrDoc(rDoc), mnTab(nTab), mrSharedStrings(rSharedStrings) {}
+void ScOrcusFactory::finalize()
+{
+    ScSetStringParam aParam;
+    aParam.setTextInput();
+    StringCellCaches::const_iterator it = maStringCells.begin(), itEnd = maStringCells.end();
+    for (; it != itEnd; ++it)
+    {
+        if (it->mnIndex >= maStrings.size())
+            // String index out-of-bound!  Something is up.
+            continue;
+
+        mrDoc.SetString(it->maPos, maStrings[it->mnIndex], &aParam);
+    }
+}
+
+void ScOrcusFactory::pushStringCell(const ScAddress& rPos, size_t nStrIndex)
+{
+    maStringCells.push_back(StringCellCache(rPos, nStrIndex));
+}
+
+ScOrcusSheet::ScOrcusSheet(ScDocument& rDoc, SCTAB nTab, ScOrcusFactory& rFactory) :
+    mrDoc(rDoc), mnTab(nTab), mrFactory(rFactory) {}
 
 void ScOrcusSheet::set_auto(row_t row, col_t col, const char* p, size_t n)
 {
@@ -85,6 +130,49 @@
     mrDoc.SetString(col, row, mnTab, aVal);
 }
 
+void ScOrcusSheet::set_string(row_t row, col_t col, size_t sindex)
+{
+    // We need to defer string cells since the shared string pool is not yet
+    // populated at the time this method is called.  Orcus imports string
+    // table after the cells get imported.  We won't need to do this once we
+    // implement true shared strings in Calc core.
+
+    mrFactory.pushStringCell(ScAddress(col, row, mnTab), sindex);
+}
+
+void ScOrcusSheet::set_value(row_t row, col_t col, double value)
+{
+    mrDoc.SetValue( col, row, mnTab, value );
+}
+
+void ScOrcusSheet::set_bool(row_t row, col_t col, bool value)
+{
+    mrDoc.SetValue(col, row, mnTab, value ? 1.0 : 0.0);
+}
+
+void ScOrcusSheet::set_date_time(
+    row_t row, col_t col, int year, int month, int day, int hour, int minute, double second)
+{
+    SvNumberFormatter* pFormatter = mrDoc.GetFormatTable();
+
+    Date aDate(day, month, year);
+    sal_uIntPtr nSec = floor(second);
+    sal_uIntPtr nSec100 = (second - nSec) * 100;
+    Time aTime(hour, minute, nSec, nSec100);
+    Date aNullDate(*pFormatter->GetNullDate());
+    long nDateDiff = aDate - aNullDate;
+
+    double fTime =
+        static_cast<double>(aTime.Get100Sec()) / 100.0 +
+        aTime.GetSec() +
+        aTime.GetMin() * 60.0 +
+        aTime.GetHour() * 3600.0;
+
+    fTime /= D_TIMEFACTOR;
+
+    mrDoc.SetValue(col, row, mnTab, nDateDiff + fTime);
+}
+
 void ScOrcusSheet::set_format(row_t /*row*/, col_t /*col*/, size_t /*xf_index*/)
 {
 }
@@ -191,45 +279,35 @@
     mrDoc.PutCell( col, row, mnTab, pCell );
 }
 
-void ScOrcusSheet::set_string(row_t row, col_t col, size_t sindex)
+void ScOrcusSheet::set_array_formula(
+    row_t /*row*/, col_t /*col*/, formula_grammar_t /*grammar*/,
+    const char* /*p*/, size_t /*n*/, row_t /*array_rows*/, col_t /*array_cols*/)
 {
-    // Calc does not yet support shared strings so we have to
-    // workaround by importing shared strings into a temporary
-    // shared string container and writing into calc model as
-    // normal string
-
-    const OUString& rSharedString = mrSharedStrings.getByIndex(sindex);
-    ScBaseCell* pCell = ScBaseCell::CreateTextCell( rSharedString, &mrDoc );
-    mrDoc.PutCell(col, row, mnTab, pCell);
 }
 
-void ScOrcusSheet::set_value(row_t row, col_t col, double value)
+void ScOrcusSheet::set_array_formula(
+    row_t /*row*/, col_t /*col*/, formula_grammar_t /*grammar*/,
+    const char* /*p*/, size_t /*n*/, const char* /*p_range*/, size_t /*n_range*/)
 {
-    mrDoc.SetValue( col, row, mnTab, value );
 }
 
+ScOrcusSharedStrings::ScOrcusSharedStrings(std::vector<OUString>& rStrings) :
+    mrStrings(rStrings) {}
+
 size_t ScOrcusSharedStrings::append(const char* s, size_t n)
 {
     OUString aNewString(s, n, RTL_TEXTENCODING_UTF8);
-    maSharedStrings.push_back(aNewString);
+    mrStrings.push_back(aNewString);
 
-    return maSharedStrings.size() - 1;
+    return mrStrings.size() - 1;
 }
 
 size_t ScOrcusSharedStrings::add(const char* s, size_t n)
 {
     OUString aNewString(s, n, RTL_TEXTENCODING_UTF8);
-    maSharedStrings.push_back(aNewString);
-
-    return maSharedStrings.size() - 1;
-}
-
-const OUString& ScOrcusSharedStrings::getByIndex(size_t nIndex) const
-{
-    if(nIndex < maSharedStrings.size())
-        return maSharedStrings[nIndex];
+    mrStrings.push_back(aNewString);
 
-    throw std::exception();
+    return mrStrings.size() - 1;
 }
 
 void ScOrcusSharedStrings::set_segment_bold(bool /*b*/)
@@ -341,6 +419,14 @@
     return 0;
 }
 
+void ScOrcusStyles::set_number_format(const char* /*s*/, size_t /*n*/)
+{
+}
+
+size_t ScOrcusStyles::commit_number_format()
+{
+    return 0;
+}
 
 // cell style xf
 
--- sc/source/filter/orcus/orcusfiltersimpl.cxx	2013-06-11 05:33:38.000000000 -0400
+++ sc/source/filter/orcus/orcusfiltersimpl.cxx	2013-06-24 19:08:23.000000000 -0400
@@ -17,6 +17,8 @@
 #include <orcus/spreadsheet/import_interface.hpp>
 #include <orcus/orcus_csv.hpp>
 #include <orcus/orcus_gnumeric.hpp>
+#include <orcus/orcus_xlsx.hpp>
+#include <orcus/orcus_ods.hpp>
 #include <orcus/global.hpp>
 
 #ifdef WNT
@@ -71,6 +73,46 @@
     return true;
 }
 
+bool ScOrcusFiltersImpl::importXLSX(ScDocument& rDoc, const rtl::OUString& rPath) const
+{
+    ScOrcusFactory aFactory(rDoc);
+    OString aSysPath = toSystemPath(rPath);
+    const char* path = aSysPath.getStr();
+
+    try
+    {
+        orcus::orcus_xlsx filter(&aFactory);
+        filter.read_file(path);
+    }
+    catch (const std::exception& e)
+    {
+        SAL_WARN("sc", "Unable to load xlsx file! " << e.what());
+        return false;
+    }
+
+    return true;
+}
+
+bool ScOrcusFiltersImpl::importODS(ScDocument& rDoc, const rtl::OUString& rPath) const
+{
+    ScOrcusFactory aFactory(rDoc);
+    OString aSysPath = toSystemPath(rPath);
+    const char* path = aSysPath.getStr();
+
+    try
+    {
+        orcus::orcus_ods filter(&aFactory);
+        filter.read_file(path);
+    }
+    catch (const std::exception& e)
+    {
+        SAL_WARN("sc", "Unable to load ods file! " << e.what());
+        return false;
+    }
+
+    return true;
+}
+
 ScOrcusXMLContext* ScOrcusFiltersImpl::createXMLContext(ScDocument& rDoc, const rtl::OUString& rPath) const
 {
     return new ScOrcusXMLContextImpl(rDoc, rPath);
