--- plv8_allocator.cc.orig	2026-06-01 05:04:31 UTC
+++ plv8_allocator.cc
@@ -67,5 +67,6 @@ void* ArrayAllocator::Reallocate(void *data, size_t ol
 			return nullptr;
 		}
 	}
-	return this->allocator->Reallocate(data, old_length, new_length);
+	allocated += delta;
+	return std::realloc(data, new_length);
 }
