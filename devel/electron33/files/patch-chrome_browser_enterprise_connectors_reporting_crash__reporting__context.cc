--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2024-10-16 21:30:58 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -20,7 +20,7 @@ namespace enterprise_connectors {
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
