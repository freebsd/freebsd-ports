--- include/denemo/denemo_types.h.orig	2020-08-28 18:35:58 UTC
+++ include/denemo/denemo_types.h
@@ -429,7 +429,7 @@ enum
   COL_ROW,
   COL_SCHEME,
   N_COLUMNS
-} COMMAND_COLS;
+};
 
 typedef enum { TYPESET_EXCERPT, TYPESET_MOVEMENT, TYPESET_ALL_MOVEMENTS} typeset_type;
 
@@ -1212,6 +1212,7 @@ struct DenemoRoot
   gboolean *fatal_scheme_errors; /** Abort on scheme errors */
   gboolean *silent; /** Don't log any message */
   gboolean *verbose; /** Display every messages */
-}  Denemo; /**< The root object. */
+};
 
+extern struct DenemoRoot Denemo; /**< The root object. */
 #endif
