--- src/import_export/univcsvdialog.cpp.orig	2016-03-05 06:10:45 UTC
+++ src/import_export/univcsvdialog.cpp
@@ -669,7 +676,7 @@ void mmUnivCSVDialog::OnImport(wxCommand
                 payeeID_ = -1;
                 categID_ = -1;
                 subCategID_ = -1;
-                val_ = NULL;
+                val_ = 0;
 
                 this->csv2tab_separated_values(line, delimit_);
                 wxStringTokenizer tkz(line, "\t", wxTOKEN_RET_EMPTY_ALL);
