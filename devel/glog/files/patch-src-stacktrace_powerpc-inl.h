--- src/stacktrace_powerpc-inl.h.orig	2019-12-01 18:35:43 UTC
+++ src/stacktrace_powerpc-inl.h
@@ -107,7 +107,7 @@ int GetStackTrace(void** result, int max_depth, int sk
       // Link Register is.  For DARWIN and AIX (used by apple and
       // linux ppc64), it's in sp[2].  For SYSV (used by linux ppc),
       // it's in sp[1].
-#if defined(_CALL_AIX) || defined(_CALL_DARWIN)
+#if defined(_CALL_AIX) || defined(_CALL_DARWIN) || defined(_CALL_ELF)
       result[n++] = *(sp+2);
 #elif defined(_CALL_SYSV)
       result[n++] = *(sp+1);
