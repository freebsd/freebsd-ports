--- ui/gfx/font_list.cc.orig	2019-09-10 10:43:23 UTC
+++ ui/gfx/font_list.cc
@@ -24,7 +24,7 @@ base::LazyInstance<scoped_refptr<gfx::FontListImpl>>::
 bool g_default_impl_initialized = false;
 
 bool IsFontFamilyAvailable(const std::string& family, SkFontMgr* fontManager) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   return !!fontManager->legacyMakeTypeface(family.c_str(), SkFontStyle());
 #else
   sk_sp<SkFontStyleSet> set(fontManager->matchFamily(family.c_str()));
