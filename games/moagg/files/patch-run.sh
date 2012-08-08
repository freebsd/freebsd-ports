--- run.sh.orig	2008-02-08 20:24:00.000000000 +0100
+++ run.sh	2012-08-07 10:41:16.000000000 +0200
@@ -1,5 +1,7 @@
 #!/bin/sh
 
+cd %%JAVASHAREDIR%%/moagg
+
 # Uncomment this line to force usage of the GAGE timer.
 #MOAGG_TIMER="GAGE"
 
