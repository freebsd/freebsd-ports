--- chrome/browser/devtools/devtools_policy_dialog.cc.orig	2026-06-23 23:37:18 UTC
+++ chrome/browser/devtools/devtools_policy_dialog.cc
@@ -33,7 +33,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr int kIconPadding = 4;
 #else
 constexpr int kIconPadding = 2;
