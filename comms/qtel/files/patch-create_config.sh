--- create_config.sh.orig	2009-04-19 14:10:53.000000000 -0700
+++ create_config.sh	2012-06-24 10:20:20.000000000 -0700
@@ -121,12 +121,15 @@
 # Checking for tcl development library
 info "--- Checking for TCL development library..."
 tclConfig=$(ls /usr/lib/tclConfig.sh /usr/lib/tcl8.*/tclConfig.sh \
-	       /usr/lib64/tclConfig.sh /usr/lib64/tcl8.*/tclConfig.sh \
+	       /usr/lib64/tclConfig.sh /usr/lib64/tcl8.*/tclConfig.sh /usr/local/lib/tcl8.*/tclConfig.sh \
 	    2>/dev/null | head -1)
 if [ -n "$tclConfig" -a -r "$tclConfig" ]; then
   . $tclConfig
   info "${TCL_VERSION}\n"
-  output "TCL_LIBS=-ltcl${TCL_VERSION}"
+  TCL_SVER=`echo ${TCL_VERSION} | tr -d .`
+  output "TCL_LIBPATH=-L/usr/local/lib"
+  output "TCL_LIBS=-ltcl${TCL_SVER}"
+  output "TCL_INCPATH=-I/usr/local/include/tcl${TCL_VERSION}"
 else
   info "no (required)\n"
   exit_error
@@ -137,8 +140,8 @@
 if which pkg-config > /dev/null 2>&1; then
   if pkg-config speex; then
     ver=$(pkg-config speex --modversion)
-    ver_major=$(echo $ver | sed -r 's/^([0-9]+)\..*$/\1/')
-    ver_minor=$(echo $ver | sed -r 's/^([0-9]+)\.([0-9]+).*$/\2/')
+    ver_major=$(echo $ver | sed -E 's/^([0-9]+)\..*$/\1/')
+    ver_minor=$(echo $ver | sed -E 's/^([0-9]+)\.([0-9]+).*$/\2/')
     info "$ver\n"
     output "SPEEX_LIBPATH=$(pkg-config speex --libs-only-L)"
     output "SPEEX_LIBS=$(pkg-config speex --libs-only-l)"
