--- ui/gl/gl_context.cc.orig	2022-05-19 05:18:01 UTC
+++ ui/gl/gl_context.cc
@@ -416,7 +416,7 @@ bool GLContext::MakeVirtuallyCurrent(
   DCHECK(virtual_context->IsCurrent(surface));
 
   if (switched_real_contexts || virtual_context != current_virtual_context_) {
-#if DCHECK_IS_ON()
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_BSD)
     GLenum error = glGetError();
     // Accepting a context loss error here enables using debug mode to work on
     // context loss handling in virtual context mode.
