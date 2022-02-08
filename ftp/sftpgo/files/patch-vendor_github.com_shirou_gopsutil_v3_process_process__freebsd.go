--- vendor/github.com/shirou/gopsutil/v3/process/process_freebsd.go.orig	2022-02-06 14:12:45 UTC
+++ vendor/github.com/shirou/gopsutil/v3/process/process_freebsd.go
@@ -115,7 +115,8 @@ func (p *Process) createTimeWithContext(ctx context.Co
 	if err != nil {
 		return 0, err
 	}
-	return k.Start.Sec*1000 + k.Start.Usec/1000, nil
+	// Pull request: https://github.com/shirou/gopsutil/pull/1246
+	return int64(k.Start.Sec)*1000 + int64(k.Start.Usec)/1000, nil
 }
 
 func (p *Process) StatusWithContext(ctx context.Context) ([]string, error) {
