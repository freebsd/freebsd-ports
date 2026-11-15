--- electron/shell/browser/app_package.cc.orig	2026-10-26 21:12:45 UTC
+++ electron/shell/browser/app_package.cc
@@ -23,7 +23,7 @@
 #include "third_party/icu/source/common/unicode/normalizer2.h"
 #include "third_party/icu/source/common/unicode/uchar.h"
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "base/environment.h"
 #endif
 
@@ -72,7 +72,7 @@ void Apply(const base::DictValue& manifest) {
   } else if (const std::string* name = manifest.FindString("name")) {
     browser->SetName(Trimmed(*name));
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   const std::string* desktop_name = manifest.FindString("desktopName");
   base::Environment::Create()->SetVar(
       "CHROME_DESKTOP",
