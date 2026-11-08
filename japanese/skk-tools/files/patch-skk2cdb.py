--- skk2cdb.py.orig	2026-04-02 19:22:22 UTC
+++ skk2cdb.py
@@ -1,14 +1,14 @@
 #!/usr/bin/env python3
 ##
-##  skk2cdb.py - convertion tool for SKK dictionary.
+##  skk2cdb - convertion tool for SKK dictionary.
 ##  by Yusuke Shinyama
 ##  * public domain *
 ##
-##  usage: skk2cdb.py [-f] outfile [infile ...]
+##  usage: skk2cdb [-f] outfile [infile ...]
 ##  options: -f: force overwriting.
 ##
 ##  example:
-##    $ skk2cdb.py SKK-JISYO.L.cdb SKK-JISYO.L
+##    $ skk2cdb SKK-JISYO.L.cdb SKK-JISYO.L
 ##
 
 # taken from pycdb.py - Python implementation of cdb 
