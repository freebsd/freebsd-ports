--- src/cmd/go/internal/modload/vendor.go.orig	2020-06-11 12:36:37 UTC
+++ src/cmd/go/internal/modload/vendor.go
@@ -133,7 +133,7 @@ func checkVendorConsistency() {
 	readVendorList()
 
 	pre114 := false
-	if modFile.Go == nil || semver.Compare("v"+modFile.Go.Version, "v1.14") < 0 {
+	if modFile.Go == nil || semver.Compare("v"+modFile.Go.Version, "v1.14") < 0 || (os.Getenv("GO_NO_VENDOR_CHECKS") == "1" && len(vendorMeta) == 0) {
 		// Go versions before 1.14 did not include enough information in
 		// vendor/modules.txt to check for consistency.
 		// If we know that we're on an earlier version, relax the consistency check.
