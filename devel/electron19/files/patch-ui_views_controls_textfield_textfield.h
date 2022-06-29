--- ui/views/controls/textfield/textfield.h.orig	2022-05-19 05:18:02 UTC
+++ ui/views/controls/textfield/textfield.h
@@ -443,7 +443,7 @@ class VIEWS_EXPORT Textfield : public View,
   // Set whether the text should be used to improve typing suggestions.
   void SetShouldDoLearning(bool value) { should_do_learning_ = value; }
 
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
