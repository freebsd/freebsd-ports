--- void-zones-update.sh.orig	2017-08-22 12:36:14 UTC
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
@@ -63,9 +65,8 @@ $FETCH -o "$ZONES_DIR/mdl_void_hosts.txt
 $FETCH -o "$ZONES_DIR/away_void_hosts.txt"     "https://adaway.org/hosts.txt"
 $FETCH -o "$ZONES_DIR/jdom_void_list.txt"      "http://mirror1.malwaredomains.com/files/justdomains"
 $FETCH -o "$ZONES_DIR/ucky_void_host.txt"     "https://raw.githubusercontent.com/FadeMind/hosts.extras/master/UncheckyAds/hosts"
-$FETCH -o "$ZONES_DIR/w10telm_void_hosts.txt" "https://raw.githubusercontent.com/crazy-max/WindowsSpyBlocker/master/data/hosts/win10/spy.txt"
-$FETCH -o "$ZONES_DIR/w81telm_void_hosts.txt" "https://raw.githubusercontent.com/crazy-max/WindowsSpyBlocker/master/data/hosts/win81/spy.txt"
-$FETCH -o "$ZONES_DIR/w7telm_void_hosts.txt"  "https://raw.githubusercontent.com/crazy-max/WindowsSpyBlocker/master/data/hosts/win7/spy.txt"
+$FETCH -o "$ZONES_DIR/wintelm_void_hosts.txt" "https://raw.githubusercontent.com/crazy-max/WindowsSpyBlocker/master/data/hosts/spy.txt"
+
 
 if [ ! -f "$ZONES_DIR/pgl_void_hosts.txt" ] ; then
    echo "# No hosts from pgl." > "$ZONES_DIR/pgl_void_hosts.txt"
@@ -95,17 +96,10 @@ if [ ! -f "$ZONES_DIR/ucky_void_host.txt
    echo "# No hosts from FadeMind/unchecky." > "$ZONES_DIR/ucky_void_host.txt"
 fi
 
-if [ ! -f "$ZONES_DIR/w10telm_void_hosts.txt" ] ; then
-   echo "# No hosts from WindowsSpyBlocker/win10/spy." > "$ZONES_DIR/w10telm_void_hosts.txt"
-fi
-
-if [ ! -f "$ZONES_DIR/w81telm_void_hosts.txt" ] ; then
-   echo "# No hosts from WindowsSpyBlocker/win81/spy." > "$ZONES_DIR/w81telm_void_hosts.txt"
+if [ ! -f "$ZONES_DIR/wintelm_void_hosts.txt" ] ; then
+   echo "# No hosts from WindowsSpyBlocker/hosts/spy." > "$ZONES_DIR/wintelm_void_hosts.txt"
 fi
 
-if [ ! -f "$ZONES_DIR/w7telm_void_hosts.txt" ] ; then
-   echo "# No hosts from WindowsSpyBlocker/win7/spy." > "$ZONES_DIR/w7telm_void_hosts.txt"
-fi
 
 /usr/local/bin/hosts2zones /tmp/local-void.zones \
                            "$ZONES_DIR/my_void_hosts.txt" \
@@ -116,9 +110,7 @@ fi
                            "$ZONES_DIR/away_void_hosts.txt" \
                            "$ZONES_DIR/jdom_void_list.txt" \
                            "$ZONES_DIR/ucky_void_host.txt" \
-                           "$ZONES_DIR/w10telm_void_hosts.txt" \
-                           "$ZONES_DIR/w81telm_void_hosts.txt" \
-                           "$ZONES_DIR/w7telm_void_hosts.txt" \
+                           "$ZONES_DIR/wintelm_void_hosts.txt" \
                            "$ZONES_DIR/x_void_list.txt" \
                            "$ZONES_DIR/y_void_list.txt" \
                            "$ZONES_DIR/z_void_list.txt" \
