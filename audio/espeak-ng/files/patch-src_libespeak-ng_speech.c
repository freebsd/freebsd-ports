--- src/libespeak-ng/speech.c.orig	2024-12-12 13:28:01 UTC
+++ src/libespeak-ng/speech.c
@@ -850,7 +850,7 @@ ESPEAK_API void espeak_SetPhonemeTrace(int phonememode
 		f_trans = stderr;
 }
 
-ESPEAK_API const char *espeak_TextToPhonemes(const void **textptr, int textmode, int phonememode)
+ESPEAK_API const char* espeak_TextToPhonemesWithTerminator(const void** textptr, int textmode, int phonememode, int* terminator)
 {
 	/* phoneme_mode
 	    bit 1:   0=eSpeak's ascii phoneme names, 1= International Phonetic Alphabet (as UTF-8 characters).
@@ -864,10 +864,15 @@ ESPEAK_API const char *espeak_TextToPhonemes(const voi
 	if (text_decoder_decode_string_multibyte(p_decoder, *textptr, translator->encoding, textmode) != ENS_OK)
 		return NULL;
 
-	TranslateClause(translator, NULL, NULL);
+	TranslateClauseWithTerminator(translator, NULL, NULL, terminator);
 	*textptr = text_decoder_get_buffer(p_decoder);
 
 	return GetTranslatedPhonemeString(phonememode);
+}
+
+ESPEAK_API const char *espeak_TextToPhonemes(const void **textptr, int textmode, int phonememode)
+{
+	return espeak_TextToPhonemesWithTerminator(textptr, textmode, phonememode, NULL);
 }
 
 ESPEAK_NG_API espeak_ng_STATUS espeak_ng_Cancel(void)
