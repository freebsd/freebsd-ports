--- create_config.sh.orig	2013-10-13 02:39:16.000000000 -0700
+++ create_config.sh	2014-04-11 12:04:57.000000000 -0700
@@ -61,43 +61,45 @@
 fi
 
 # Checking for QT
-info "--- Checking for QT..."
-if which pkg-config > /dev/null 2>&1; then
-  if pkg-config QtCore; then
-    QT_MODULES="QtCore QtGui QtNetwork"
-    info "yes (pkg-config QtCore)\n"
-    output "QT_LIBPATH=$(pkg-config $QT_MODULES --libs-only-L)"
-    output "QT_LIBS=$(pkg-config $QT_MODULES --libs-only-l)"
-    output "QT_INCPATH=$(pkg-config $QT_MODULES --cflags-only-I)"
-    output "QT_CFLAGS=$(pkg-config $QT_MODULES --cflags-only-other)"
-    QT_PREFIX=$(pkg-config QtCore --variable=prefix)
-    QT_BIN="${QT_PREFIX}/bin"
-    output "QT_BIN=${QT_BIN}"
-    QT_MOC=$(pkg-config QtCore --variable=moc_location)
-    if [ ! -x "$QT_MOC" ]; then
-      QT_MOC="$QT_BIN/moc"
-    fi
-    QT_UIC=$(pkg-config QtCore --variable=uic_location)
-    if [ ! -x "$QT_UIC" ]; then
-      QT_UIC="$QT_BIN/uic"
-    fi
-    QT_RCC=$(pkg-config QtCore --variable=rcc_location)
-    if [ ! -x "$QT_RCC" ]; then
-      QT_RCC="$QT_BIN/rcc"
+if [ "$WITHOUT_QT" != "yes" ]; then
+  info "--- Checking for QT..."
+  if which pkg-config > /dev/null 2>&1; then
+    if pkg-config QtCore; then
+      QT_MODULES="QtCore QtGui QtNetwork"
+      info "yes (pkg-config QtCore)\n"
+      output "QT_LIBPATH=$(pkg-config $QT_MODULES --libs-only-L)"
+      output "QT_LIBS=$(pkg-config $QT_MODULES --libs-only-l)"
+      output "QT_INCPATH=$(pkg-config $QT_MODULES --cflags-only-I)"
+      output "QT_CFLAGS=$(pkg-config $QT_MODULES --cflags-only-other)"
+      #QT_PREFIX=$(pkg-config QtCore --variable=prefix)
+      QT_BIN="${QT_PREFIX}/bin"
+      output "QT_BIN=${QT_BIN}"
+      QT_MOC=$(pkg-config QtCore --variable=moc_location)
+      if [ ! -x "$QT_MOC" ]; then
+        QT_MOC="$QT_BIN/moc"
+      fi
+      QT_UIC=$(pkg-config QtCore --variable=uic_location)
+      if [ ! -x "$QT_UIC" ]; then
+        QT_UIC="$QT_BIN/uic"
+      fi
+      QT_RCC=$(pkg-config QtCore --variable=rcc_location)
+      if [ ! -x "$QT_RCC" ]; then
+        QT_RCC="$QT_BIN/rcc"
+      fi
+      QT_LRELEASE=$(pkg-config QtCore --variable=lrelease_location)
+      if [ ! -x "$QT_LRELEASE" ]; then
+        QT_LRELEASE="$QT_BIN/lrelease"
+      fi
+      output "QT_MOC=$MOC"
+      output "QT_UIC=$UIC"
+      output "QT_RCC=$RCC"
+      output "QT_LRELEASE=$LRELEASE"
+    else
+      info "no (optional)\n"
     fi
-    QT_LRELEASE=$(pkg-config QtCore --variable=lrelease_location)
-    if [ ! -x "$QT_LRELEASE" ]; then
-      QT_LRELEASE="$QT_BIN/lrelease"
-    fi
-    output "QT_MOC=${QT_MOC}"
-    output "QT_UIC=${QT_UIC}"
-    output "QT_RCC=${QT_RCC}"
-    output "QT_LRELEASE=${QT_LRELEASE}"
   else
     info "no (optional)\n"
   fi
-else
-  info "no (optional)\n"
 fi
 
 # Checking for libsigc++
@@ -120,9 +122,7 @@
 
 # Checking for tcl development library
 info "--- Checking for TCL development library..."
-tclConfig=$(ls /usr/lib/tclConfig.sh /usr/lib/tcl8.*/tclConfig.sh \
-	       /usr/lib64/tclConfig.sh /usr/lib64/tcl8.*/tclConfig.sh \
-	    2>/dev/null | head -1)
+tclConfig=$(ls ${TCL_LIBDIR}/tclConfig.sh 2>/dev/null | head -1)
 if [ -n "$tclConfig" -a -r "$tclConfig" ]; then
   . $tclConfig
   info "${TCL_VERSION}\n"
