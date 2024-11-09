--- src/slic3r/GUI/EditGCodeDialog.cpp.orig	2024-10-15 09:06:23 UTC
+++ src/slic3r/GUI/EditGCodeDialog.cpp
@@ -566,7 +566,7 @@ void ParamsModel::GetValue(wxVariant& variant, const w
 
     ParamsNode* node = static_cast<ParamsNode*>(item.GetID());
     if (col == (unsigned int)0)
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         variant << wxDataViewIconText(node->text, get_bmp_bundle(node->icon_name)->GetIconFor(m_ctrl->GetParent()));
 #else
         variant << DataViewBitmapText(node->text, get_bmp_bundle(node->icon_name)->GetBitmapFor(m_ctrl->GetParent()));
@@ -581,7 +581,7 @@ bool ParamsModel::SetValue(const wxVariant& variant, c
 
     ParamsNode* node = static_cast<ParamsNode*>(item.GetID());
     if (col == (unsigned int)0) {
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
         wxDataViewIconText data;
         data << variant;
         node->icon = data.GetIcon();
@@ -658,7 +658,7 @@ ParamsViewCtrl::ParamsViewCtrl(wxWindow *parent, wxSiz
     this->AssociateModel(model);
     model->SetAssociatedControl(this);
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxDataViewIconTextRenderer* rd = new wxDataViewIconTextRenderer();
 #ifdef SUPPORTS_MARKUP
     rd->EnableMarkup(true);
