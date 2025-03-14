--- ui/base/ime/fake_text_input_client.h.orig	2025-01-27 17:37:37 UTC
+++ ui/base/ime/fake_text_input_client.h
@@ -107,7 +107,7 @@ class FakeTextInputClient : public TextInputClient {
   void SetTextEditCommandForNextKeyEvent(TextEditCommand command) override;
   ukm::SourceId GetClientSourceForMetrics() const override;
   bool ShouldDoLearning() override;
-#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   bool SetCompositionFromExistingText(
       const gfx::Range& range,
       const std::vector<ui::ImeTextSpan>& ui_ime_text_spans) override;
