--- chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc.orig	2023-03-30 00:33:42 UTC
+++ chrome/browser/enterprise/connectors/reporting/crash_reporting_context.cc
@@ -18,7 +18,7 @@
 
 namespace enterprise_connectors {
 
-#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS_ASH)
+#if !BUILDFLAG(IS_FUCHSIA) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_BSD)
 
 namespace {
 
