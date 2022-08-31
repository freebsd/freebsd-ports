Reference:  https://github.com/Blosc/caterva/commit/d34818b6fde503b13edee9654852559932bf0390

--- caterva/caterva_ext.pyx.orig	2022-01-28 12:38:26 UTC
+++ caterva/caterva_ext.pyx
@@ -48,7 +48,7 @@ cdef extern from "blosc2.h":
         BLOSC2_MAX_FILTERS
         BLOSC2_MAX_METALAYERS
         BLOSC2_MAX_VLMETALAYERS
-        BLOSC_MAX_OVERHEAD
+        BLOSC2_MAX_OVERHEAD
         BLOSC_ALWAYS_SPLIT = 1,
         BLOSC_NEVER_SPLIT = 2,
         BLOSC_AUTO_SPLIT = 3,
@@ -130,7 +130,7 @@ cdef extern from "caterva.h":
     ctypedef struct caterva_storage_t:
         int32_t chunkshape[CATERVA_MAX_DIM]
         int32_t blockshape[CATERVA_MAX_DIM]
-        bool sequencial
+        bool contiguous
         char* urlpath
         caterva_metalayer_t metalayers[CATERVA_MAX_METALAYERS]
         int32_t nmetalayers
@@ -195,8 +195,8 @@ cdef extern from "caterva.h":
                                  int64_t *start, int64_t *stop, caterva_array_t *array);
     int caterva_copy(caterva_ctx_t *ctx, caterva_array_t *src, caterva_storage_t *storage,
                      caterva_array_t ** array);
-    int caterva_resize(caterva_array_t *array,
-                             int64_t *new_shape);
+    int caterva_resize(caterva_ctx_t *ctx, caterva_array_t *array, int64_t *new_shape,
+                       const int64_t *start);
 
 # Defaults for compression params
 config_dflts = {
@@ -269,7 +269,7 @@ cdef create_caterva_storage(caterva_storage_t *storage
     chunks = kwargs.get('chunks', None)
     blocks = kwargs.get('blocks', None)
     urlpath = kwargs.get('urlpath', None)
-    sequential = kwargs.get('sequential', False)
+    contiguous = kwargs.get('contiguous', False)
     meta = kwargs.get('meta', None)
 
     if not chunks:
@@ -282,7 +282,7 @@ cdef create_caterva_storage(caterva_storage_t *storage
         storage.urlpath = urlpath
     else:
         storage.urlpath = NULL
-    storage.sequencial = sequential
+    storage.contiguous = contiguous
     for i in range(len(chunks)):
         storage.chunkshape[i] = chunks[i]
         storage.blockshape[i] = blocks[i]
@@ -321,7 +321,7 @@ cdef class NDArray:
     @property
     def cratio(self):
         """The compression ratio for this container."""
-        return self.size / (self.array.sc.cbytes + BLOSC_MAX_OVERHEAD * self.nchunks)
+        return self.size / (self.array.sc.cbytes + BLOSC2_MAX_OVERHEAD * self.nchunks)
 
     @property
     def clevel(self):
@@ -517,10 +517,11 @@ def copy(NDArray arr, NDArray src, **kwargs):
     return arr
 
 def resize(NDArray arr, new_shape):
+    ctx = Context(**arr.kwargs)
     cdef int64_t new_shape_[CATERVA_MAX_DIM]
     for i, s in enumerate(new_shape):
         new_shape_[i] = s
-    caterva_resize(arr.array, new_shape_)
+    caterva_resize(ctx.context_, arr.array, new_shape_, NULL)
     return arr
 
 def from_file(NDArray arr, urlpath, **kwargs):
