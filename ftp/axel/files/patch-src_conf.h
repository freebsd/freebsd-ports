- workaround for https://github.com/axel-download-accelerator/axel/issues/399

--- src/conf.h.orig	2023-01-22 20:27:54 UTC
+++ src/conf.h
@@ -65,7 +65,7 @@ typedef struct {
 		AXEL_PROGRESS_STYLE_PERCENTAGE,
 	} progress_style;
 
-	if_t *interfaces;
+	if_t_ *interfaces;
 
 	sa_family_t ai_family;
 
