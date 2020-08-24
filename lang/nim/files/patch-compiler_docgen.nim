--- compiler/docgen.nim.orig	2020-08-21 12:50:46 UTC
+++ compiler/docgen.nim
@@ -1163,7 +1163,7 @@ proc writeOutput*(d: PDoc, useWarning = false) =
       rawMessage(d.conf, if useWarning: warnCannotOpenFile else: errCannotOpenFile,
         outfile.string)
     elif not d.wroteCss:
-      let cssSource = $d.conf.getPrefixDir() / "doc" / "nimdoc.css"
+      let cssSource = $d.conf.getPrefixDir() / "share/doc/nim" / "nimdoc.css"
       let cssDest = $dir / nimdocOutCss
       copyFile(cssSource, cssDest)
       d.wroteCss = true
