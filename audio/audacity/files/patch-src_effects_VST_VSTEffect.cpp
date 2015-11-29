--- src/effects/VST/VSTEffect.cpp.orig	2015-07-11 10:02:22 UTC
+++ src/effects/VST/VSTEffect.cpp
@@ -2576,7 +2576,7 @@ bool VSTEffect::Load()
    // symbols.
    //
    // Once we define a proper external API, the flags can be removed.
-   void *lib = dlopen((const char *)wxString(realPath).ToUTF8(), RTLD_NOW | RTLD_LOCAL | RTLD_DEEPBIND);
+   void *lib = dlopen((const char *)wxString(realPath).ToUTF8(), RTLD_NOW | RTLD_LOCAL);
    if (!lib) 
    {
       return false;
