--- plv8_allocator.h.orig	2026-06-01 05:04:31 UTC
+++ plv8_allocator.h
@@ -22,7 +22,7 @@ class ArrayAllocator : public v8::ArrayBuffer::Allocat
 	void* Allocate(size_t length) final;
 	void* AllocateUninitialized(size_t length) final;
 	void Free(void* data, size_t length) final;
-	void* Reallocate(void *data, size_t old_length, size_t new_length) final;
+	void* Reallocate(void *data, size_t old_length, size_t new_length);
 };
 
 #endif //PLV8_PLV8_ALLOCATOR_H
