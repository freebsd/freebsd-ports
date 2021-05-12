--- headless/lib/browser/headless_request_context_manager.cc.orig	2021-04-14 01:08:50 UTC
+++ headless/lib/browser/headless_request_context_manager.cc
@@ -34,7 +34,7 @@ namespace {
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
 constexpr char kProductName[] = "HeadlessChrome";
 #endif
 
@@ -72,7 +72,7 @@ void SetCryptConfigOnce(const base::FilePath& user_dat
 
 // TODO(crbug.com/1052397): Revisit the macro expression once build flag switch
 // of lacros-chrome is complete.
-#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS)
+#if defined(OS_LINUX) || BUILDFLAG(IS_CHROMEOS_LACROS) || defined(OS_BSD)
   ::network::mojom::CryptConfigPtr config =
       ::network::mojom::CryptConfig::New();
   config->store = base::CommandLine::ForCurrentProcess()->GetSwitchValueASCII(
