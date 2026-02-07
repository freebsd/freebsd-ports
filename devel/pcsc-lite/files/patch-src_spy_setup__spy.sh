--- src/spy/setup_spy.sh.orig	2024-05-08 09:57:49 UTC
+++ src/spy/setup_spy.sh
@@ -5,7 +5,7 @@ PATH="$PATH:/usr/sbin"
 
 # ldconfig --print-cache will return something like
 # libpcsclite.so.1 (libc6,x86-64) => /usr/lib/x86_64-linux-gnu/libpcsclite.so.1
-DIR=$(ldconfig --print-cache | grep libpcsclite.so.1)
+DIR=$(ldconfig -r | grep libpcsclite.so.1)
 
 # get the right part only: /usr/lib/x86_64-linux-gnu/libpcsclite.so.1
 DIR=$(echo "$DIR" | cut -d'=' -f2 | cut -d' ' -f2)
