--- vendor/github.com/charmbracelet/bubbletea/cancelreader_bsd.go.orig	2021-12-11 06:31:30 UTC
+++ vendor/github.com/charmbracelet/bubbletea/cancelreader_bsd.go
@@ -134,9 +134,9 @@ func (r *kqueueCancelReader) wait() error {
 	}
 
 	switch events[0].Ident {
-	case uint64(r.file.Fd()):
+	case uint32(r.file.Fd()):
 		return nil
-	case uint64(r.cancelSignalReader.Fd()):
+	case uint32(r.cancelSignalReader.Fd()):
 		return errCanceled
 	}
 
