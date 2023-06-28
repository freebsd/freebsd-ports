--- libraries/source/spidermonkey/patch.sh.orig	2022-09-23 20:36:41 UTC
+++ libraries/source/spidermonkey/patch.sh
@@ -84,4 +84,6 @@ then
     patch -p1 < ../FixFreeBSDCargoChecksum.diff
     # https://svnweb.freebsd.org/ports/head/lang/spidermonkey78/files/patch-third__party_rust_cc_src_lib.rs?view=log
     patch -p1 < ../FixFreeBSDRustThirdPartyOSDetection.diff
+    # Remove now unknown compiler option causing problems
+    patch -p1 < ../FixFreeBSDClang16.diff
 fi
