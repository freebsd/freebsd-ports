--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2024-06-18 21:43:22 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -18,7 +18,7 @@ namespace enterprise_connectors {
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
