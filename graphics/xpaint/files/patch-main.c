The XtGetApplicationResources() function uses the 'resources' array instead
of the 'options' array to obtain resources.

--- main.c.orig	2020-09-03 07:06:19 UTC
+++ main.c
@@ -146,7 +146,7 @@ static XtResource resources[] =
     {"winsize", "WinSize", XtRString, sizeof(String),
      XtOffset(AppInfo *, winsize), XtRImmediate, (XtPointer) "0x0"},
     {"shareDir", "ShareDir", XtRString, sizeof(String),
-     XtOffset(AppInfo *, shareDir), XtRImmediate, (XtPointer) NULL},   
+     XtOffset(AppInfo *, shareDir), XtRImmediate, (XtPointer) SHAREDIR},   
     {"rcFile", "RcFile", XtRString, sizeof(String),
      XtOffset(AppInfo *, rcFile), XtRImmediate, (XtPointer) NULL},
     {"help", "Help", XtRString, sizeof(String),
@@ -206,7 +206,7 @@ static XrmOptionDescRec options[] =
     {"-hilitcolor", ".hilitcolor", XrmoptionSepArg, (XtPointer) NULL},
     {"-canvassize", ".canvassize", XrmoptionSepArg, (XtPointer) NULL},
     {"-winsize", ".winsize", XrmoptionSepArg, (XtPointer) "0x0"},
-    {"-sharedir", ".shareDir", XrmoptionSepArg, (XtPointer) SHAREDIR},   
+    {"-sharedir", ".shareDir", XrmoptionSepArg, (XtPointer) NULL},   
     {"-rcfile", ".rcFile", XrmoptionSepArg, (XtPointer) NULL},
     {"-helpfile", ".helpFile", XrmoptionSepArg, (XtPointer) NULL},
     {"-msgfile", ".msgFile", XrmoptionSepArg, (XtPointer) NULL},
