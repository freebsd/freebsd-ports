--- src/slic3r/GUI/UnsavedChangesDialog.cpp.orig	2025-10-02 17:32:12 UTC
+++ src/slic3r/GUI/UnsavedChangesDialog.cpp
@@ -28,7 +28,7 @@ using boost::optional;
 
 using boost::optional;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 #define wxLinux true
 #else
 #define wxLinux false
@@ -110,7 +110,7 @@ ModelNode::ModelNode(ModelNode* parent, const wxString
     UpdateIcons();
 }
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
 wxIcon ModelNode::get_bitmap(const wxString& color)
 #else
 wxBitmap ModelNode::get_bitmap(const wxString& color)
@@ -128,7 +128,7 @@ wxBitmap ModelNode::get_bitmap(const wxString& color)
     ColorRGB rgb;
     decode_color(into_u8(color), rgb);
     // there is no need to scale created solid bitmap
-#ifndef __linux__
+#if !defined(__linux__) && !defined(__FreeBSD__)
     return bmp_cache.mksolid(icon_width, icon_height, rgb, true);
 #else
     wxIcon icon;
@@ -211,7 +211,7 @@ void ModelNode::UpdateIcons()
     if (m_icon_name.empty())
         return;
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     m_icon.CopyFromBitmap(create_scaled_bitmap(m_icon_name, m_parent_win, 16, !m_toggle));
 #else
     m_icon = create_scaled_bitmap(m_icon_name, m_parent_win, 16, !m_toggle);
@@ -362,7 +362,7 @@ void DiffModel::GetValue(wxVariant& variant, const wxD
     case colToggle:
         variant = node->m_toggle;
         break;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     case colIconText:
         variant << wxDataViewIconText(node->m_text, node->m_icon);
         break;
@@ -399,7 +399,7 @@ bool DiffModel::SetValue(const wxVariant& variant, con
     case colToggle:
         node->m_toggle = variant.GetBool();
         return true;
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     case colIconText: {
         wxDataViewIconText data;
         data << variant;
@@ -609,7 +609,7 @@ void DiffViewCtrl::AppendBmpTextColumn(const wxString&
 void DiffViewCtrl::AppendBmpTextColumn(const wxString& label, unsigned model_column, int width, bool set_expander/* = false*/)
 {
     m_columns_width.emplace(this->GetColumnCount(), width);
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
     wxDataViewIconTextRenderer* rd = new wxDataViewIconTextRenderer();
 #ifdef SUPPORTS_MARKUP
     rd->EnableMarkup(true);
