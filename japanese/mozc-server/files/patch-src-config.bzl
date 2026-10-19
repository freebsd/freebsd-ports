--- src/config.bzl.orig	2026-10-16 12:33:33 UTC
+++ src/config.bzl
@@ -37,16 +37,16 @@ BAZEL_TOOLS_PREFIX = "@bazel_tools"
 
 BAZEL_TOOLS_PREFIX = "@bazel_tools"
 
-LINUX_MOZC_BROWSER_COMMAND = "/usr/bin/xdg-open"
-LINUX_MOZC_ICONS_DIR = "/usr/share/icons/mozc"
-LINUX_MOZC_SERVER_DIR = "/usr/lib/mozc"
-LINUX_MOZC_DOCUMENT_DIR = LINUX_MOZC_SERVER_DIR + "/documents"
-IBUS_COMPONENT_DIR = "/usr/share/ibus/component"
-IBUS_MOZC_INSTALL_DIR = "/usr/share/ibus-mozc"
-IBUS_MOZC_ICON_PATH = IBUS_MOZC_INSTALL_DIR + "/product_icon.png"
-IBUS_MOZC_PATH = "/usr/lib/ibus-mozc/ibus-engine-mozc"
-EMACS_MOZC_CLIENT_DIR = "/usr/share/emacs/site-lisp/emacs-mozc"
-EMACS_MOZC_HELPER_DIR = "/usr/bin"
+LINUX_MOZC_BROWSER_COMMAND = "%%LOCALBASE%%/bin/xdg-open"
+LINUX_MOZC_ICONS_DIR = "%%PREFIX%%/share/mozc/icons"
+LINUX_MOZC_SERVER_DIR = "%%PREFIX%%/libexec"
+LINUX_MOZC_DOCUMENT_DIR = "%%DOCSDIR%%"
+IBUS_COMPONENT_DIR = "%%PREFIX%%/share/ibus/component"
+IBUS_MOZC_INSTALL_DIR = "%%LOCALBASE%%/share/mozc/icons"
+IBUS_MOZC_ICON_PATH = IBUS_MOZC_INSTALL_DIR + "/mozc.png"
+IBUS_MOZC_PATH = "%%PREFIX%%/libexec/ibus-engine-mozc"
+EMACS_MOZC_CLIENT_DIR = "%%PREFIX%%/%%EMACS_SITE_LISPDIR%%/mozc"
+EMACS_MOZC_HELPER_DIR = "%%PREFIX%%/libexec"
 
 MACOS_BUNDLE_ID_PREFIX = "org.mozc.inputmethod.Japanese"
 MACOS_MIN_OS_VER = "12.0"
