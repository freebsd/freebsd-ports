--- misc/run-roh.pl.orig	2017-10-18 09:33:24 UTC
+++ misc/run-roh.pl
@@ -97,7 +97,7 @@ sub cmd
     else 
     {      
         # child
-        exec('/bin/bash', '-o','pipefail','-c', $cmd) or error("Failed to run the command [/bin/sh -o pipefail -c $cmd]: $!");
+        exec('/bin/sh', '-c', $cmd) or error("Failed to run the command [/bin/sh -c $cmd]: $!");
     }
 
     if ( exists($args{exit_on_error}) && !$args{exit_on_error} ) { return @out; }
