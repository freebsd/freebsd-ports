--- README.md.orig	2021-03-08 03:32:35 UTC
+++ README.md
@@ -16,9 +16,8 @@ Installing manually will require the contrib be regist
 ```
 (add-to-list 'sly-contribs 'sly-asdf 'append)
 ```
+
 ## Experimental
-SLY-ASDF currently supports a very experimental system-aware checker that builds on flymake. This loads the system in a separate process and highlights any compilation/load errors for currently opened buffers. Only tested with SBCL. Enable this with 
-```
-(setq sly-asdf-enable-experimental-syntax-checking t)
-(require 'sly-asdf-flymake)
-```
+Upstream currently supports a very experimental system-aware checker that
+builds on flymake. It is not available in this port (please use some ELPA
+package instead).
