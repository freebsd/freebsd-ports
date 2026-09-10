--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -30,7 +30,7 @@ namespace enterprise_connectors {
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_CHROMEOS)
+#if !BUILDFLAG(IS_CHROMEOS) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
