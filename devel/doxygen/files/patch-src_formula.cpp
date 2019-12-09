Upstream git commit 03daff4 resolving a problem with Ghostscript 9.50.

--- src/formula.cpp
+++ src/formula.cpp
@@ -193,8 +193,8 @@ void FormulaList::generateBitmaps(const char *path)
       // used.  
 
       char gsArgs[4096];
-      sprintf(gsArgs,"-q -g%dx%d -r%dx%dx -sDEVICE=ppmraw "
-                    "-sOutputFile=%s.pnm -dNOPAUSE -dBATCH -- %s.ps",
+      sprintf(gsArgs,"-q -g%dx%d -r%dx%d -sDEVICE=ppmraw "
+                    "-sOutputFile=%s.pnm -dNOPAUSE -dBATCH -dNOSAFER %s.ps",
                     gx,gy,(int)(scaleFactor*72),(int)(scaleFactor*72),
                     formBase.data(),formBase.data()
              );
