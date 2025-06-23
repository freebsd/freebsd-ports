--- radish-play.sh.orig	2024-06-17 18:49:28 UTC
+++ radish-play.sh
@@ -22,11 +22,12 @@ Options:
                     lisradi: ListenRadio
                     shiburadi: Shibuya no Radio
   -s STATION ID   Station ID
-  -d MINUTE       Record minute(s)
-  -o FILEPATH     Output file path
   -i ADDRESS      login mail address (radiko only)
   -p PASSWORD     login password (radiko only)
   -l              Show all station ID list
+
+EXAMPLES:
+  radish-play -t nhk -s tokyo-r1
 _EOT_
 }

@@ -415,23 +416,12 @@ if [ "${type}" = "radiko" ]; then

 # Play
 if [ "${type}" = "radiko" ]; then
-  ffplay \
-      -loglevel error \
-      -fflags +discardcorrupt \
-      -headers "X-Radiko-Authtoken: ${radiko_authtoken}" \
-      -i "${playlist_uri}" \
-      -nodisp
+  mpv \
+      --http-header-fields="X-Radiko-Authtoken: ${radiko_authtoken}" \
+      "${playlist_uri}"
 else
-  ffplay \
-      -loglevel error \
-      -fflags +discardcorrupt \
-      -i "${playlist_uri}" \
-      -nodisp
-fi
-ret=$?
-if [ ${ret} -ne 0 ]; then
-  echo "Record failed" >&2
-  exit 1
+  mpv \
+      "${playlist_uri}"
 fi

 # Finish
