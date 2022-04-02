--- util.c.orig	2021-01-09 12:14:56 UTC
+++ util.c
@@ -3079,7 +3079,7 @@ void
 
 #define PERL_REPEATCPY_LINEAR 4
 void
-Perl_repeatcpy(char *to, const char *from, I32 len, IV count)
+Perl_repeatcpy(char *to, const char *from, I32 len, IVINT count)
 {
     PERL_ARGS_ASSERT_REPEATCPY;
 
@@ -5414,7 +5414,7 @@ Perl_xs_handshake(const U32 key, void * v_my_perl, con
     va_start(args, file);
 
     got = INT2PTR(void*, (UV)(key & HSm_KEY_MATCH));
-    need = (void *)(HS_KEY(FALSE, FALSE, "", "") & HSm_KEY_MATCH);
+    need = (void *)(UV)(HS_KEY(FALSE, FALSE, "", "") & HSm_KEY_MATCH);
     if (UNLIKELY(got != need))
 	goto bad_handshake;
 /* try to catch where a 2nd threaded perl interp DLL is loaded into a process
