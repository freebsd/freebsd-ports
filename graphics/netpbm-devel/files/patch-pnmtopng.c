--- converter/other/pnmtopng.c.orig	2005-12-30 18:17:49.000000000 -0500
+++ converter/other/pnmtopng.c	2005-12-30 18:18:15.000000000 -0500
@@ -267,7 +267,7 @@ parseCommandLine (int argc, char ** argv
     unsigned int option_def_index;
 
     unsigned int alphaSpec, transparentSpec, backgroundSpec;
-    unsigned int textSpec, ztxtSpec, modtimeSpec, paletteSpec;
+    unsigned int textSpec, ztxtSpec, paletteSpec;
     unsigned int filterSpec;
 
     unsigned int nofilter, sub, up, avg, paeth, filter;
@@ -296,7 +296,7 @@ parseCommandLine (int argc, char ** argv
     OPTENT3(0, "ztxt",             OPT_STRING,    &cmdlineP->ztxt,
             &ztxtSpec,             0);
     OPTENT3(0, "modtime",          OPT_STRING,    &modtime,
-            &modtimeSpec,          0);
+            &cmdlineP->modtimeSpec,0);
     OPTENT3(0, "palette",          OPT_STRING,    &cmdlineP->palette,
             &paletteSpec,          0);
     OPTENT3(0, "compression",      OPT_UINT,
