--- void-zones-update.sh.orig	2017-08-26 23:00:56 UTC
+++ void-zones-update.sh
@@ -47,6 +47,8 @@ fi
 ZONES_DIR="/usr/local/etc/void-zones"
 if [ ! -d "$ZONES_DIR" ]; then
    mkdir -p "$ZONES_DIR"
+fi
+if [ ! -f "$ZONES_DIR/my_void_hosts.txt" ]; then
    echo "# white list"          > "$ZONES_DIR/my_void_hosts.txt"
    echo "1.1.1.1 my.white.dom" >> "$ZONES_DIR/my_void_hosts.txt"
    echo ""                     >> "$ZONES_DIR/my_void_hosts.txt"
