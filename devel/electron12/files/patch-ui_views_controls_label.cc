--- ui/views/controls/label.cc.orig	2021-04-14 01:09:40 UTC
+++ ui/views/controls/label.cc
@@ -806,7 +806,7 @@ bool Label::OnMousePressed(const ui::MouseEvent& event
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   if (event.IsOnlyMiddleMouseButton() && GetFocusManager() && !had_focus)
     GetFocusManager()->SetFocusedView(this);
 #endif
@@ -995,7 +995,7 @@ bool Label::PasteSelectionClipboard() {
 void Label::UpdateSelectionClipboard() {
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   if (!GetObscured()) {
     ui::ScopedClipboardWriter(ui::ClipboardBuffer::kSelection)
         .WriteText(GetSelectedText());
