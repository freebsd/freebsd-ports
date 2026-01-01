--- src/cmd/go/internal/modload/vendor.go.orig	2023-08-02 13:51:49 UTC
+++ src/cmd/go/internal/modload/vendor.go
@@ -144,7 +144,7 @@ func checkVendorConsistency(index *modFileIndex, modFi
 	readVendorList(MainModules.mustGetSingleMainModule())
 
 	pre114 := false
-	if gover.Compare(index.goVersion, "1.14") < 0 {
+	if gover.Compare(index.goVersion, "1.14") < 0 || os.Getenv("GO_NO_VENDOR_CHECKS") == "1" {
 		// Go versions before 1.14 did not include enough information in
 		// vendor/modules.txt to check for consistency.
 		// If we know that we're on an earlier version, relax the consistency check.
