--- ./src/toolkit/tests+examples/tsimpleinst.sml.orig	Fri Mar 30 23:40:06 2001
+++ src/toolkit/tests+examples/tsimpleinst.sml	Sun Jan 13 11:03:51 2008
@@ -344,7 +344,7 @@
                    let
                      fun read_file si = 
                        if TextIO.endOfStream si then ""
-                       else (TextIO.inputLine si)^(read_file si)
+                       else (valOf (TextIO.inputLine si))^(read_file si)
                      val is  = TextIO.openIn filenm
                      val txt = read_file is
                      val _   = TextIO.closeIn is
