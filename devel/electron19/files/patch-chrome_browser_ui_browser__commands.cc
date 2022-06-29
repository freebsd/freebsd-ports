--- chrome/browser/ui/browser_commands.cc.orig	2022-05-25 04:00:50 UTC
+++ chrome/browser/ui/browser_commands.cc
@@ -176,7 +176,7 @@
 #include "chromeos/lacros/lacros_service.h"
 #endif
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 #include "ui/accessibility/ax_action_data.h"
 #include "ui/accessibility/ax_enums.mojom.h"
 #endif
@@ -1859,7 +1859,7 @@ void UnfollowSite(content::WebContents* web_contents) 
   feed::UnfollowSite(web_contents);
 }
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 void RunScreenAi(Browser* browser) {
   ui::AXActionData ad;
   ad.action = ax::mojom::Action::kRunScreenAi;
