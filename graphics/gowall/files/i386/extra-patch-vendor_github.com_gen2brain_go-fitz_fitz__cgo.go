===>  Building gowall from .
# github.com/gen2brain/go-fitz
vendor/github.com/gen2brain/go-fitz/fitz_cgo.go:100:79: cannot use _Ctype_store(MaxStore) (value of uint32 type _Ctype_store) as _Ctype_size_t value in argument to (_Cfunc_fz_new_context_imp)
vendor/github.com/gen2brain/go-fitz/fitz_cgo.go:133:79: cannot use _Ctype_store(MaxStore) (value of uint32 type _Ctype_store) as _Ctype_size_t value in argument to (_Cfunc_fz_new_context_imp)

--- vendor/github.com/gen2brain/go-fitz/fitz_cgo.go.orig	2025-10-13 13:52:34 UTC
+++ vendor/github.com/gen2brain/go-fitz/fitz_cgo.go
@@ -97,7 +97,7 @@ func New(filename string) (f *Document, err error) {
		return
	}

-	f.ctx = (*C.struct_fz_context)(unsafe.Pointer(C.fz_new_context_imp(nil, nil, C.store(MaxStore), C.fz_version)))
+	f.ctx = (*C.struct_fz_context)(unsafe.Pointer(C.fz_new_context_imp(nil, nil, C.size_t(MaxStore), C.fz_version)))
	if f.ctx == nil {
		err = ErrCreateContext
		return
@@ -130,7 +130,7 @@ func NewFromMemory(b []byte) (f *Document, err error)
	}
	f = &Document{}

-	f.ctx = (*C.struct_fz_context)(unsafe.Pointer(C.fz_new_context_imp(nil, nil, C.store(MaxStore), C.fz_version)))
+	f.ctx = (*C.struct_fz_context)(unsafe.Pointer(C.fz_new_context_imp(nil, nil, C.size_t(MaxStore), C.fz_version)))
	if f.ctx == nil {
		err = ErrCreateContext
		return
