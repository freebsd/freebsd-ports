--- autosetup/pkg-config.tcl.orig	2025-07-02 07:23:27 UTC
+++ autosetup/pkg-config.tcl
@@ -78,7 +78,7 @@ proc pkg-config-init {{required 1}} {
 			# but it doesn't seem to work that way in practice
 			set env(PKG_CONFIG_PATH) ""
 			# Do we need to try /usr/local as well or instead?
-			set env(PKG_CONFIG_LIBDIR) $sysroot/usr/lib/pkgconfig:$sysroot/usr/share/pkgconfig
+			set env(PKG_CONFIG_LIBDIR) $system/usr/libdata/pkgconfig:$sysroot/usr/local/libdata/pkgconfig
 			set env(PKG_CONFIG_SYSROOT_DIR) $sysroot
 		}
 	}
