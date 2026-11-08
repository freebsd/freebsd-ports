Description: Wrap dict.items() in list() before slicing, so the go2gene
  check raises its intended error instead of a TypeError from slicing a
  dict view.
Issue ID: none (not yet reported)
Changeset: none (still present on upstream main 4cd1c71)
TODO: Report upstream (upstream is alive); drop once a release fixes it.

--- goatools/ratio.py.orig	2024-05-05 14:48:29 UTC
+++ goatools/ratio.py
@@ -64,7 +64,7 @@ def _chk_gene2go(assoc):
     for key in assoc:
         if isinstance(key, str) and key[:3] == "GO:":
             raise Exception("ASSOCIATIONS EXPECTED TO BE gene2go, NOT go2gene: {EX}".format(
-                EX=assoc.items()[:2]))
+                EX=list(assoc.items())[:2]))
         return
 
 # Copyright (C) 2010-2018, H Tang et al., All rights reserved.
