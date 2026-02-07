--- src/include/espeak-ng/speak_lib.h.orig	2024-12-12 13:28:01 UTC
+++ src/include/espeak-ng/speak_lib.h
@@ -544,6 +544,12 @@ extern "C"
 #ifdef __cplusplus
 extern "C"
 #endif
+ESPEAK_API const char *espeak_TextToPhonemesWithTerminator(const void **textptr, int textmode, int phonememode, int *terminator);
+/* Version of espeak_TextToPhonemes that also returns the clause terminator (e.g., CLAUSE_INTONATION_FULL_STOP) */
+
+#ifdef __cplusplus
+extern "C"
+#endif
 ESPEAK_API void espeak_CompileDictionary(const char *path, FILE *log, int flags);
 /* Compile pronunciation dictionary for a language which corresponds to the currently
    selected voice.  The required voice should be selected before calling this function.
