--- mono/mini/mini-x86.h.orig	2018-08-24 15:17:13 UTC
+++ mono/mini/mini-x86.h
@@ -139,7 +139,7 @@ struct MonoLMF {
 	 * If the second lowest bit is set to 1, then this is a MonoLMFExt structure, and
 	 * the other fields are not valid.
 	 */
-	guint32    previous_lmf;
+	gpointer    previous_lmf;
 	gpointer    lmf_addr;
 	/* Only set in trampoline LMF frames */
 	MonoMethod *method;
