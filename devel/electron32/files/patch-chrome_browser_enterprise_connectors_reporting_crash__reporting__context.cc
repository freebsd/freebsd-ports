--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2024-08-14 20:54:35 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -19,7 +19,7 @@ namespace enterprise_connectors {
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
