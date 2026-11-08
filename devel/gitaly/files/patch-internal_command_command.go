--- internal/command/command.go.orig	2026-10-15 00:35:47 UTC
+++ internal/command/command.go
@@ -773,10 +773,10 @@ func (c *Command) logProcessComplete() {
 
 	if ok {
 		attributes = append(attributes,
-			attribute.Int64("inblock", rusage.Inblock),
-			attribute.Int64("oublock", rusage.Oublock),
-			attribute.Int64("minflt", rusage.Minflt),
-			attribute.Int64("majflt", rusage.Majflt),
+			attribute.Int64("inblock", int64(rusage.Inblock)),
+			attribute.Int64("oublock", int64(rusage.Oublock)),
+			attribute.Int64("minflt", int64(rusage.Minflt)),
+			attribute.Int64("majflt", int64(rusage.Majflt)),
 		)
 	}
 	if signal != 0 {
