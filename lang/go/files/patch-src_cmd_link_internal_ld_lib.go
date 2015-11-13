--- src/cmd/link/internal/ld/lib.go.orig	2015-09-09 01:24:02 UTC
+++ src/cmd/link/internal/ld/lib.go
@@ -1765,7 +1765,7 @@ func genasmsym(put func(*LSym, string, i
 	}
 
 	for s := Ctxt.Allsym; s != nil; s = s.Allsym {
-		if s.Hide != 0 || (s.Name[0] == '.' && s.Version == 0 && s.Name != ".rathole") {
+		if s.Hide != 0 || ((s.Name == "" || s.Name[0] == '.') && s.Version == 0 && s.Name != ".rathole") {
 			continue
 		}
 		switch s.Type & obj.SMASK {
