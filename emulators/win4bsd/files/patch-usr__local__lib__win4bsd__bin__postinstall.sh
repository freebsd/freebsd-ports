--- ./usr/local/lib/win4bsd/bin/postinstall.sh.orig	2009-11-13 23:12:52.000000000 -0200
+++ ./usr/local/lib/win4bsd/bin/postinstall.sh	2009-11-13 23:14:36.000000000 -0200
@@ -259,25 +259,6 @@
 		"%u additional user%U for MergePro"
 fi
 
-# build the KQEMU accelerator module if possible
-MERGEPRO_RC_BACK="no"
-case "$SYSTEMTYPE" in
-	uw7)
-		echo "Installing $MERGENAME device driver (kqemu)..."
-		echo "NOTE: you may be prompted to reboot your system!"
-		echo "If a system reboot is not required, $MERGENAME"
-		echo "services will start automatically..."
-		set +e
-		modadmin -U kqemu >/dev/null 2>&1
-		set -e
-		"$STATICMERGE"/etc/Driver.SETUP
-		MRGPRO_RC_BACK="yes"	# background start in case of init 6
-		;;
-	*)
-		KQEMU_NO_FAIL=yes; export KQEMU_NO_FAIL
-		"$STATICMERGE"/bin/build_kqemu.sh
-		;;
-esac
 
 # start the Merge Pro service
 set -e
