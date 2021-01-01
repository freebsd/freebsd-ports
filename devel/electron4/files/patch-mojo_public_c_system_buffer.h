--- mojo/public/c/system/buffer.h.orig	2019-03-19 09:06:10 UTC
+++ mojo/public/c/system/buffer.h
@@ -30,7 +30,7 @@ struct MOJO_ALIGNAS(8) MojoCreateSharedBufferOptions {
   // See |MojoCreateSharedBufferFlags|.
   MojoCreateSharedBufferFlags flags;
 };
-MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) == 8, "int64_t has weird alignment");
+MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) <= 8, "int64_t has weird alignment");
 MOJO_STATIC_ASSERT(sizeof(MojoCreateSharedBufferOptions) == 8,
                    "MojoCreateSharedBufferOptions has wrong size");
 
