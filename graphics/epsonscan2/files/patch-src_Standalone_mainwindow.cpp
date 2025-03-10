--- src/Standalone/mainwindow.cpp.orig	2024-09-12 07:10:39 UTC
+++ src/Standalone/mainwindow.cpp
@@ -730,7 +730,7 @@ bool MainWindow::SelectionRestrictions(int value){
         limit_resolution = 300;
     }
     if(obj == ui->Resolution_comb){
-        if(ui->Document_size_comb->current_item == USER_DEFINE){
+        if(ui->Document_size_comb->current_item == (DocumentSize)USER_DEFINE){
             return UserDefineSizeRestrictions();
         }else if(ui->Document_size_comb->current_item == Auto_Detect_long){
             if(ui->Resolution_comb->currentText().toInt() > limit_resolution){
@@ -1436,7 +1436,7 @@ bool MainWindow::CheckAutoFunctionalUnit(bool isPrevie
     if(this->m_viewPreviewWindow){
         if(isPreview && sv->device_data.FunctionalUnit_Auto){
             if(sv->GetPaperLoadedStatus()){
-                if(sv->m_Preview_FunctionalUnit == kSDIFunctionalUnitDocumentFeeder){
+                if(sv->m_Preview_FunctionalUnit == (FunctionalUnit)kSDIFunctionalUnitDocumentFeeder){
                     sv->device_data.FunctionalUnit.select = kSDIFunctionalUnitDocumentFeeder;
                 }else {
                     if(m_messageBox->CreateSelectableMessageBox(TranslationString::GetString().translation_str.C_UI_005, Warning)){
@@ -1449,7 +1449,7 @@ bool MainWindow::CheckAutoFunctionalUnit(bool isPrevie
                     }
                 }
             }else {
-                if(sv->m_Preview_FunctionalUnit == kSDIFunctionalUnitFlatbed){
+                if(sv->m_Preview_FunctionalUnit == (FunctionalUnit)kSDIFunctionalUnitFlatbed){
                     sv->device_data.FunctionalUnit.select = kSDIFunctionalUnitFlatbed;
                 }else {
                     if(m_messageBox->CreateSelectableMessageBox(TranslationString::GetString().translation_str.C_UI_005, Warning)){
@@ -1545,7 +1545,7 @@ bool MainWindow::CheckBeforeScan(bool isPreview)
         }
     }
     if(!sv->device_data.DNShow_LongPaperWarning_dialog){
-        if(ui->Document_size_comb->current_item == USER_DEFINE){
+        if(ui->Document_size_comb->current_item == (DocumentSize)USER_DEFINE){
             if(this->CheckLongPaperMode()){
                 sv->device_data.DNShow_LongPaperWarning_dialog = m_messageBox->CreateMessageBox(TranslationString::GetString().translation_str.A_UI_005, TranslationString::GetString().translation_str.VERSION_003, Information, true);
             }
