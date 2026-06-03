--- chrome/browser/devtools/devtools_policy_dialog.cc.orig	2026-03-13 16:54:03 UTC
+++ chrome/browser/devtools/devtools_policy_dialog.cc
@@ -32,7 +32,7 @@ namespace {
 
 namespace {
 
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
 constexpr int kIconPadding = 4;
 #else
 constexpr int kIconPadding = 2;
