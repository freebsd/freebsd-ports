-- Replace the bundled jemalloc/mimalloc global allocators with the Rust
-- system allocator. The jemalloc allocator's pthread_create interposer
-- aborts on FreeBSD when the extension is loaded into Python because
-- dlsym(RTLD_NEXT, "pthread_create") fails in this context.
--- src/lib.rs.orig	2026-07-08 12:44:00 UTC
+++ src/lib.rs
@@ -100,11 +100,11 @@ use crate::writer::to_lazy_table;
     not(target_os = "emscripten"),
     not(target_os = "freebsd")
 ))]
-static ALLOC: tikv_jemallocator::Jemalloc = tikv_jemallocator::Jemalloc;
+static ALLOC: std::alloc::System = std::alloc::System;
 
 #[global_allocator]
 #[cfg(any(not(target_family = "unix"), target_os = "emscripten"))]
-static ALLOC: mimalloc::MiMalloc = mimalloc::MiMalloc;
+static ALLOC: std::alloc::System = std::alloc::System;
 
 // On FreeBSD, neither jemallocator nor mimalloc is set as global allocator.
 // jemallocator fails its dlsym(RTLD_NEXT, "pthread_create") init under
