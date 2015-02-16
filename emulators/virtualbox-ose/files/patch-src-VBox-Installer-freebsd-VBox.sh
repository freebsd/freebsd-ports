--- src/VBox/Installer/freebsd/VBox.sh.orig	2015-02-16 12:58:52.951032000 -0500
+++ src/VBox/Installer/freebsd/VBox.sh	2015-02-16 13:00:48.096063000 -0500
@@ -0,0 +1,58 @@
+#!/bin/sh
+#
+# Oracle VM VirtualBox startup script, FreeBSD hosts.
+#
+# Copyright (C) 2006-2012 Oracle Corporation
+#
+# This file is part of VirtualBox Open Source Edition (OSE), as
+# available from http://www.virtualbox.org. This file is free software;
+# you can redistribute it and/or modify it under the terms of the GNU
+# General Public License (GPL) as published by the Free Software
+# Foundation, in version 2 as it comes in the "COPYING" file of the
+# VirtualBox OSE distribution. VirtualBox OSE is distributed in the
+# hope that it will be useful, but WITHOUT ANY WARRANTY of any kind.
+#
+
+PATH="/usr/bin:/bin:/usr/sbin:/sbin"
+CONFIG="/usr/local/etc/vbox/vbox.cfg"
+
+test -r "${CONFIG}" &&
+    . "${CONFIG}"
+test -z "${INSTALL_DIR}" &&
+    if test -d /usr/local/lib/virtualbox &&
+        test -f /usr/local/lib/virtualbox/VBoxRT.so; then
+        INSTALL_DIR=/usr/local/lib/virtualbox
+    else
+        echo "Could not find VirtualBox installation. Please reinstall."
+        exit 1
+    fi
+
+APP=`basename $0`
+case "$APP" in
+    VirtualBox|virtualbox)
+        exec "$INSTALL_DIR/VirtualBox" "$@"
+        ;;
+    VBoxManage|vboxmanage)
+        exec "$INSTALL_DIR/VBoxManage" "$@"
+        ;;
+    VBoxSDL|vboxsdl)
+        exec "$INSTALL_DIR/VBoxSDL" "$@"
+        ;;
+    VBoxVRDP|VBoxHeadless|vboxheadless)
+        exec "$INSTALL_DIR/VBoxHeadless" "$@"
+        ;;
+    VBoxAutostart|vboxautostart)
+        exec "$INSTALL_DIR/VBoxAutostart" "$@"
+        ;;
+    VBoxBalloonCtrl|vboxballoonctrl)
+        exec "$INSTALL_DIR/VBoxBalloonCtrl" "$@"
+        ;;
+    vboxwebsrv)
+        exec "$INSTALL_DIR/vboxwebsrv" "$@"
+        ;;
+    *)
+        echo "Unknown application - $APP"
+        exit 1
+        ;;
+esac
+exit 0
