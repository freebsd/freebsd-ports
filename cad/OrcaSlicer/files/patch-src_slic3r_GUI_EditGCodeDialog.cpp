--- src/slic3r/GUI/EditGCodeDialog.cpp.orig	2026-03-22 17:56:38 UTC
+++ src/slic3r/GUI/EditGCodeDialog.cpp
@@ -721,7 +721,7 @@ void ParamsModel::GetValue(wxVariant& variant, const w
 
     ParamsNode* node = static_cast<ParamsNode*>(item.GetID());
     if (col == (unsigned int)0)
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 //        variant << wxDataViewIconText(node->GetFormattedText(), get_bmp_bundle(node->icon_name)->GetIconFor(m_ctrl->GetParent())); //TODO: update to bundle with wx update
     {
         wxIcon icon;
@@ -742,7 +742,7 @@ bool ParamsModel::SetValue(const wxVariant& variant, c
 
     ParamsNode* node = static_cast<ParamsNode*>(item.GetID());
     if (col == (unsigned int)0) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         wxDataViewIconText data;
         data << variant;
         node->icon = data.GetIcon();
@@ -802,7 +802,7 @@ wxString     ParamsModel::GetColumnType(unsigned int c
 }
 unsigned int ParamsModel::GetColumnCount() const { return 1; }
 wxString     ParamsModel::GetColumnType(unsigned int col) const {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     return wxT("wxDataViewIconText");
 #else
     return wxT("DataViewBitmapText");
@@ -827,7 +827,7 @@ ParamsViewCtrl::ParamsViewCtrl(wxWindow *parent, wxSiz
     this->AssociateModel(model);
     model->SetAssociatedControl(this);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxDataViewIconTextRenderer* rd = new wxDataViewIconTextRenderer();
 #ifdef SUPPORTS_MARKUP
     rd->EnableMarkup(true);
