--- mojo/public/c/system/message_pipe.h.orig	2019-03-19 09:06:10 UTC
+++ mojo/public/c/system/message_pipe.h
@@ -35,7 +35,7 @@ struct MOJO_ALIGNAS(8) MojoCreateMessagePipeOptions {
   // See |MojoCreateMessagePipeFlags|.
   MojoCreateMessagePipeFlags flags;
 };
-MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) == 8, "int64_t has weird alignment");
+MOJO_STATIC_ASSERT(MOJO_ALIGNOF(int64_t) <= 8, "int64_t has weird alignment");
 MOJO_STATIC_ASSERT(sizeof(MojoCreateMessagePipeOptions) == 8,
                    "MojoCreateMessagePipeOptions has wrong size");
 
