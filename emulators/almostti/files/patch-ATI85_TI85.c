--- ATI85/TI85.c.orig	2009-12-17 07:37:54 UTC
+++ ATI85/TI85.c
@@ -61,14 +61,14 @@ int LinkPort         = 8385;       /* Li
 /** Configuration, by model **********************************/
 const TIConfig Config[] =
 {
-  { ATI_TI85,  "TI85.png",  "TI85.ROM",  0x20000, "TI85.RAM",  0x8000  },
-  { ATI_TI86,  "TI86.png",  "TI86.ROM",  0x40000, "TI86.RAM",  0x20000 },
-  { ATI_TI82,  "TI82.png",  "TI82.ROM",  0x20000, "TI82.RAM",  0x8000  },
-  { ATI_TI83,  "TI83.png",  "TI83.ROM",  0x40000, "TI83.RAM",  0x8000  },
-  { ATI_TI83P, "TI83P.png", "TI83P.ROM", 0x80000, "TI83P.RAM", 0x8000  },
-  { ATI_TI83SE,"TI83SE.png","TI83SE.ROM",0x200000,"TI83SE.RAM",0x20000 },
-  { ATI_TI84P, "TI84P.png", "TI84P.ROM", 0x100000,"TI84P.RAM", 0x20000 },
-  { ATI_TI84SE,"TI84SE.png","TI84SE.ROM",0x200000,"TI84SE.RAM",0x20000 },
+  { ATI_TI85,  "./" "TI85.png",  "TI85.ROM",  0x20000, "TI85.RAM",  0x8000  },
+  { ATI_TI86,  "./" "TI86.png",  "TI86.ROM",  0x40000, "TI86.RAM",  0x20000 },
+  { ATI_TI82,  "./" "TI82.png",  "TI82.ROM",  0x20000, "TI82.RAM",  0x8000  },
+  { ATI_TI83,  "./" "TI83.png",  "TI83.ROM",  0x40000, "TI83.RAM",  0x8000  },
+  { ATI_TI83P, "./" "TI83P.png", "TI83P.ROM", 0x80000, "TI83P.RAM", 0x8000  },
+  { ATI_TI83SE,"./" "TI83SE.png","TI83SE.ROM",0x200000,"TI83SE.RAM",0x20000 },
+  { ATI_TI84P, "./" "TI84P.png", "TI84P.ROM", 0x100000,"TI84P.RAM", 0x20000 },
+  { ATI_TI84SE,"./" "TI84SE.png","TI84SE.ROM",0x200000,"TI84SE.RAM",0x20000 },
   { 0,0,0,0,0,0 }
 };
 
@@ -274,6 +274,9 @@ int ResetTI85(int NewMode)
       RAMSize = Config[M].RAMSize;
       ROMSize = Config[M].ROMSize;
 
+      /* Set RAMFile to enable state saving */
+      RAMFile = Config[M].RAMFile;
+
       /* Clear memory contents */
       memset(RAM,NORAM,RAMSize);
 
