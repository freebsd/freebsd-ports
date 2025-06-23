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

@@ -427,11 +428,6 @@ else
       -fflags +discardcorrupt \
       -i "${playlist_uri}" \
       -nodisp
-fi
-ret=$?
-if [ ${ret} -ne 0 ]; then
-  echo "Record failed" >&2
-  exit 1
 fi

 # Finish
