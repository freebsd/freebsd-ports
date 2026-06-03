===>  Building gowall from .
# github.com/gen2brain/go-fitz
vendor/github.com/gen2brain/go-fitz/fitz_cgo.go:546:103: cannot use _Ctype_int(len(buf)) (value of int32 type _Ctype_int) as _Ctype_size_t value in variable declaration
*** Error code 1

--- vendor/github.com/gen2brain/go-fitz/fitz_cgo.go.orig	2025-10-12 16:34:24 UTC
+++ vendor/github.com/gen2brain/go-fitz/fitz_cgo.go
@@ -543,7 +543,7 @@ func (f *Document) Metadata() map[string]string {
		defer C.free(unsafe.Pointer(ckey))

		buf := make([]byte, 256)
-		C.fz_lookup_metadata(f.ctx, f.doc, ckey, (*C.char)(unsafe.Pointer(&buf[0])), C.int(len(buf)))
+		C.fz_lookup_metadata(f.ctx, f.doc, ckey, (*C.char)(unsafe.Pointer(&buf[0])), C.size_t(len(buf)))

		return string(buf)
	}
