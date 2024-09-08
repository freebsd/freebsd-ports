--- src/cmd/go/internal/modload/vendor.go.orig	2024-02-02 18:09:55 UTC
+++ src/cmd/go/internal/modload/vendor.go
@@ -159,7 +159,7 @@ func checkVendorConsistency(indexes []*modFileIndex, m
 			panic(fmt.Errorf("not in workspace mode but number of indexes is %v, not 1", len(indexes)))
 		}
 		index := indexes[0]
-		if gover.Compare(index.goVersion, "1.14") < 0 {
+		if gover.Compare(index.goVersion, "1.14") < 0 || os.Getenv("GO_NO_VENDOR_CHECKS") == "1" {
 			// Go versions before 1.14 did not include enough information in
 			// vendor/modules.txt to check for consistency.
 			// If we know that we're on an earlier version, relax the consistency check.
