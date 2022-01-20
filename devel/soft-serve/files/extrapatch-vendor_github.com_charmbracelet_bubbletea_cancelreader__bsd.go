--- vendor/github.com/charmbracelet/bubbletea/cancelreader_bsd.go.orig	2022-01-07 18:25:29 UTC
+++ vendor/github.com/charmbracelet/bubbletea/cancelreader_bsd.go
@@ -134,11 +134,11 @@ func (r *kqueueCancelReader) wait() error {
 		break
 	}
 
-	ident := uint64(events[0].Ident)
+	ident := uint32(events[0].Ident)
 	switch ident {
-	case uint64(r.file.Fd()):
+	case uint32(r.file.Fd()):
 		return nil
-	case uint64(r.cancelSignalReader.Fd()):
+	case uint32(r.cancelSignalReader.Fd()):
 		return errCanceled
 	}
 
