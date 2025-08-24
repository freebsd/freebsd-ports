--- usecases/cluster/disk_use_unix.go.orig	2025-08-14 19:49:00 UTC
+++ usecases/cluster/disk_use_unix.go
@@ -26,6 +26,6 @@ func diskSpace(path string) (DiskUsage, error) {
 	}
 	return DiskUsage{
 		Total:     fs.Blocks * uint64(fs.Bsize),
-		Available: fs.Bavail * uint64(fs.Bsize),
+		Available: uint64(fs.Bavail) * fs.Bsize,
 	}, nil
 }
