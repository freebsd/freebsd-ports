--- chrome/browser/web_applications/isolated_web_apps/remove_isolated_web_app_data.cc.orig	2026-10-19 21:50:55 UTC
+++ chrome/browser/web_applications/isolated_web_apps/remove_isolated_web_app_data.cc
@@ -57,6 +57,8 @@ void CloseBundle(Profile* profile,
 void CloseBundle(Profile* profile,
                  const IwaSource& source,
                  base::OnceClosure callback) {
+// XXX crubit
+#if 0
   if (!content::AreIsolatedWebAppsEnabled(profile)) {
     // A previously installed IWA can be uninstalled even if the IWA feature
     // flag is off; in this case the reader registry will not exist.
@@ -71,6 +73,7 @@ void CloseBundle(Profile* profile,
           [&](const IwaSourceProxy& proxy) { std::move(callback).Run(); },
       },
       source.variant());
+#endif
 }
 
 }  // namespace
