--- src/effects/VST/VSTEffect.cpp	2015-03-31 23:03:30.000000000 -0700
+++ src/effects/VST/VSTEffect.cpp	2015-03-01 17:06:58.000000000 -0800
@@ -2609,7 +2609,7 @@
    // symbols.
    //
    // Once we define a proper external API, the flags can be removed.
-   void *lib = dlopen((const char *)wxString(realPath).ToUTF8(), RTLD_NOW | RTLD_LOCAL | RTLD_DEEPBIND);
+   void *lib = dlopen((const char *)wxString(realPath).ToUTF8(), RTLD_NOW | RTLD_LOCAL);
    if (!lib) 
    {
       return false;
