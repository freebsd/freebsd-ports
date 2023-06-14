--- scanner/scanner.go.orig	2023-06-07 22:14:47 UTC
+++ scanner/scanner.go
@@ -635,9 +635,9 @@ func statCreateTime(info fs.FileInfo) time.Time {
 	if !ok {
 		return time.Time{}
 	}
-	if stat.Ctim.Sec == 0 {
+	if stat.Ctimespec.Sec == 0 {
 		return time.Time{}
 	}
 	//nolint:unconvert // Ctim.Sec/Nsec is int32 on arm/386, etc
-	return time.Unix(int64(stat.Ctim.Sec), int64(stat.Ctim.Nsec))
+	return time.Unix(int64(stat.Ctimespec.Sec), int64(stat.Ctimespec.Nsec))
 }
