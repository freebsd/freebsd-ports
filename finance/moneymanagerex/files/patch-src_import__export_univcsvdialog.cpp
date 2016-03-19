--- src/import_export/univcsvdialog.cpp.orig	2016-03-05 06:10:45 UTC
+++ src/import_export/univcsvdialog.cpp
@@ -37,6 +37,13 @@
 
 #include "csv_parser/csv_parser.hpp"
 
+#ifdef _LIBCPP_VERSION
+#define TO_WSTRING(x) std::to_wstring(x)
+#else
+#include <boost/lexical_cast.hpp>
+#define TO_WSTRING(x) boost::lexical_cast<std::wstring>(x)
+#endif
+
 wxIMPLEMENT_DYNAMIC_CLASS(mmUnivCSVDialog, wxDialog);
 
 wxBEGIN_EVENT_TABLE(mmUnivCSVDialog, wxDialog)
@@ -409,7 +416,7 @@ void mmUnivCSVDialog::SetSettings(const 
     csvFieldOrder_.clear();
     for (int i = 0; i < 99; i++)
     {
-        const std::wstring w = to_wstring(i);
+        const std::wstring w = TO_WSTRING(i);
         const wxString& value = wxString(json::String(o[w]));
         if (!value.empty())
         {
@@ -536,7 +543,7 @@ void mmUnivCSVDialog::OnSave(wxCommandEv
     int count = 0;
     for (std::vector<int>::const_iterator it = csvFieldOrder_.begin(); it != csvFieldOrder_.end(); ++it)
     {
-        const auto w = to_wstring(count++);
+        const auto w = TO_WSTRING(count++);
         int i = *it;
         o[w] = json::String(CSVFieldName_[i].ToStdWstring());
         wxLogDebug("%i - %i - %s", count-1, i, CSVFieldName_[i]);
@@ -669,7 +676,7 @@ void mmUnivCSVDialog::OnImport(wxCommand
                 payeeID_ = -1;
                 categID_ = -1;
                 subCategID_ = -1;
-                val_ = NULL;
+                val_ = 0;
 
                 this->csv2tab_separated_values(line, delimit_);
                 wxStringTokenizer tkz(line, "\t", wxTOKEN_RET_EMPTY_ALL);
