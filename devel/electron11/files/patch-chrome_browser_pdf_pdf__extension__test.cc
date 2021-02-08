--- chrome/browser/pdf/pdf_extension_test.cc.orig	2021-01-07 00:36:23 UTC
+++ chrome/browser/pdf/pdf_extension_test.cc
@@ -2159,7 +2159,7 @@ class PDFExtensionClipboardTest : public PDFExtensionT
   // Runs `action` and checks the Linux selection clipboard contains `expected`.
   void DoActionAndCheckSelectionClipboard(base::OnceClosure action,
                                           const std::string& expected) {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
     DoActionAndCheckClipboard(std::move(action),
                               ui::ClipboardBuffer::kSelection, expected);
 #else
