--- regex_internal.h.orig	2020-12-28 19:25:52 UTC
+++ regex_internal.h
@@ -481,7 +481,7 @@ static unsigned int re_string_context_at (const re_str
 #define re_string_skip_bytes(pstr,idx) ((pstr)->cur_idx += (idx))
 #define re_string_set_index(pstr,idx) ((pstr)->cur_idx = (idx))
 
-#if defined _LIBC || HAVE_ALLOCA
+#if defined _LIBC || (HAVE_ALLOCA && HAVE_ALLOCA_H)
 # include <alloca.h>
 #endif
 
