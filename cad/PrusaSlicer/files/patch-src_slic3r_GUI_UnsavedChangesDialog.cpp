--- src/slic3r/GUI/UnsavedChangesDialog.cpp.orig	2024-06-27 09:25:47 UTC
+++ src/slic3r/GUI/UnsavedChangesDialog.cpp
@@ -31,7 +31,7 @@ using boost::optional;
 
 using boost::optional;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define wxLinux true
 #else
 #define wxLinux false
@@ -111,7 +111,7 @@ ModelNode::ModelNode(ModelNode* parent, const wxString
     UpdateIcons();
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 wxIcon ModelNode::get_bitmap(const wxString& color)
 #else
 wxBitmap ModelNode::get_bitmap(const wxString& color)
@@ -120,7 +120,7 @@ wxBitmap ModelNode::get_bitmap(const wxString& color)
     wxBitmap bmp = get_solid_bmp_bundle(64, 16, into_u8(color))->GetBitmapFor(m_parent_win);
     if (!m_toggle)
         bmp = bmp.ConvertToDisabled();
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
     return bmp;
 #else
     wxIcon icon;
@@ -224,7 +224,7 @@ void ModelNode::UpdateIcons()
     if (!m_toggle)
         bmp = bmp.ConvertToDisabled();
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     m_icon.CopyFromBitmap(bmp);
 #else
     m_icon = bmp;
@@ -376,7 +376,7 @@ void DiffModel::GetValue(wxVariant& variant, const wxD
     case colToggle:
         variant = node->m_toggle;
         break;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     case colIconText:
         variant << wxDataViewIconText(node->m_text, node->m_icon);
         break;
@@ -419,7 +419,7 @@ bool DiffModel::SetValue(const wxVariant& variant, con
     case colToggle:
         node->m_toggle = variant.GetBool();
         return true;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     case colIconText: {
         wxDataViewIconText data;
         data << variant;
@@ -647,7 +647,7 @@ void DiffViewCtrl::AppendBmpTextColumn(const wxString&
 void DiffViewCtrl::AppendBmpTextColumn(const wxString& label, unsigned model_column, int width, bool set_expander/* = false*/)
 {
     m_columns_width.emplace(this->GetColumnCount(), width);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxDataViewIconTextRenderer* rd = new wxDataViewIconTextRenderer();
 #ifdef SUPPORTS_MARKUP
     rd->EnableMarkup(true);
