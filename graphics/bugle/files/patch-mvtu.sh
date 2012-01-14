--- mvtu.sh~
+++ mvtu.sh
@@ -5,6 +5,7 @@ rm -f "$2"
 for i in "$1.tu" "$1.t00.tu" "$1.001t.tu"
 do
     test -f "$i" && mv -f "$i" "$2"
+    test -f "${2%/*}/$i" && mv -f "${2%/*}/$i" "$2"
 done
 if ! test -f "$2"
 then
