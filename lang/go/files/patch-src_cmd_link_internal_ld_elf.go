Backport https://go-review.googlesource.com/c/go/+/346872/ to go1.17
--- src/cmd/link/internal/ld/elf.go.orig	2021-08-16 16:29:54 UTC
+++ src/cmd/link/internal/ld/elf.go
@@ -2028,6 +2028,11 @@ func asmbElf(ctxt *Link) {
 		ph := newElfPhdr()
 		ph.Type = elf.PT_SUNWSTACK
 		ph.Flags = elf.PF_W + elf.PF_R
+	} else if ctxt.HeadType == objabi.Hfreebsd {
+		ph := newElfPhdr()
+		ph.Type = elf.PT_GNU_STACK
+		ph.Flags = elf.PF_W + elf.PF_R
+		ph.Align = uint64(ctxt.Arch.RegSize)
 	}
 
 elfobj:
