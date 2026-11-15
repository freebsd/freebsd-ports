--- electron/shell/browser/api/electron_api_clipboard.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/api/electron_api_clipboard.cc
@@ -107,7 +107,7 @@ void EnumerateAvailableTypes(ui::ClipboardBuffer buffe
   // clipboard) to discover them before finalizing.
   TypesCallback add_bookmark = base::BindOnce(
       [](TypesCallback finalize, std::vector<std::string> types) {
-#if !BUILDFLAG(IS_LINUX)
+#if !BUILDFLAG(IS_LINUX) && !BUILDFLAG(IS_BSD)
         ui::Clipboard::GetForCurrentThread()->ReadURL(
             /* data_dst = */ std::nullopt,
             base::BindOnce(
@@ -439,7 +439,7 @@ void Initialize(v8::Local<v8::Object> exports,
   PopulateClipboardObject(isolate, context, exports,
                           ui::ClipboardBuffer::kCopyPaste);
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   auto selection = v8::Object::New(isolate);
   PopulateClipboardObject(isolate, context, selection,
                           ui::ClipboardBuffer::kSelection);
