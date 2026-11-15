--- components/search_engines/template_url_service.cc.orig	2026-10-19 21:50:55 UTC
+++ components/search_engines/template_url_service.cc
@@ -3815,7 +3815,7 @@ TemplateURLService::GetEnterpriseSearchManager(PrefSer
 std::unique_ptr<EnterpriseSearchManager>
 TemplateURLService::GetEnterpriseSearchManager(PrefService* prefs) {
 #if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || \
-    BUILDFLAG(IS_CHROMEOS)
+    BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   return std::make_unique<EnterpriseSearchManager>(
       prefs, base::BindRepeating(&TemplateURLService::EnterpriseSearchChanged,
                                  base::Unretained(this)));
