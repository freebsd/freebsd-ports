--- salome_adm/unix/config_files/check_cas.m4.orig	2009-10-31 20:35:10.000000000 +0600
+++ salome_adm/unix/config_files/check_cas.m4	2009-10-31 20:37:39.000000000 +0600
@@ -54,7 +54,7 @@
       casdir=Linux
       ;;
    freebsd*)
-      casdir=Linux
+      casdir=FreeBSD
       ;;
    irix5.*)
       casdir=Linux
@@ -153,6 +153,20 @@
       esac
       CAS_CPPFLAGS="$CAS_CPPFLAGS -I$CASROOT/inc"
       ;;
+   freebsd*)
+      CAS_CPPFLAGS="-DOCC_VERSION_MAJOR=$OCC_VERSION_MAJOR -DOCC_VERSION_MINOR=$OCC_VERSION_MINOR -DOCC_VERSION_MAINTENANCE=$OCC_VERSION_MAINTENANCE  -DCSFDB -DNo_exception -DHAVE_CONFIG_H -DHAVE_LIMITS_H -DHAVE_WOK_CONFIG_H  -I$CASROOT/inc"
+
+      OCC_VERSION_STRING="$OCC_VERSION_MAJOR.$OCC_VERSION_MINOR.$OCC_VERSION_MAINTENANCE"
+      case $OCC_VERSION_STRING in
+        [[0-5]].* | 6.0.* | 6.1.0) # catch versions < 6.1.1
+          CAS_CPPFLAGS="$CAS_CPPFLAGS -DNO_CXX_EXCEPTION"
+          ;;
+        *)
+          CAS_CPPFLAGS="$CAS_CPPFLAGS -DOCC_CONVERT_SIGNALS"
+          ;;
+      esac
+      CAS_CPPFLAGS="$CAS_CPPFLAGS -I$CASROOT/inc"
+      ;;
    osf*)
       CAS_CPPFLAGS="-DOCC_VERSION_MAJOR=$OCC_VERSION_MAJOR -DOCC_VERSION_MINOR=$OCC_VERSION_MINOR -DOCC_VERSION_MAINTENANCE=$OCC_VERSION_MAINTENANCE -DLIN -DLINTEL -DCSFDB -DNo_exception -DHAVE_CONFIG_H -DHAVE_LIMITS_H -DHAVE_WOK_CONFIG_H -I$CASROOT/inc"
       ;;
