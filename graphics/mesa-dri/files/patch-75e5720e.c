commit 75e5720e1a64fac116e19cd9a7682b1d0f530149
Author: Timur Kristóf <timur.kristof@gmail.com>
Date:   Tue Jan 21 16:36:54 2020 +0100

    radeon: Fix multiple definition error with radeon_debug
    
    Signed-off-by: Timur Kristóf <timur.kristof@gmail.com>
    Reviewed-by: Marek Olšák <marek.olsak@amd.com>
    Tested-by: Marge Bot <https://gitlab.freedesktop.org/mesa/mesa/merge_requests/3488>
    Part-of: <https://gitlab.freedesktop.org/mesa/mesa/merge_requests/3488>

diff --git src/mesa/drivers/dri/radeon/radeon_debug.c src/mesa/drivers/dri/radeon/radeon_debug.c
index 91f86a96b52..4ac974473e2 100644
--- src/mesa/drivers/dri/radeon/radeon_debug.c
+++ src/mesa/drivers/dri/radeon/radeon_debug.c
@@ -57,13 +57,17 @@ static const struct debug_control debug_control[] = {
 	{NULL, 0}
 };
 
-radeon_debug_type_t radeon_enabled_debug_types;
+#if defined(RADEON_R200)
+radeon_debug_type_t r200_enabled_debug_types;
+#elif defined(RADEON_R100)
+radeon_debug_type_t r100_enabled_debug_types;
+#endif
 
 void radeon_init_debug(void)
 {
-	radeon_enabled_debug_types = parse_debug_string(getenv("RADEON_DEBUG"), debug_control);
+	RADEON_DEBUG = parse_debug_string(getenv("RADEON_DEBUG"), debug_control);
 
-	radeon_enabled_debug_types |= RADEON_GENERAL;
+	RADEON_DEBUG |= RADEON_GENERAL;
 }
 
 void _radeon_debug_add_indent(void)
diff --git src/mesa/drivers/dri/radeon/radeon_debug.h src/mesa/drivers/dri/radeon/radeon_debug.h
index df2f1abfbf2..8f56ec6769b 100644
--- src/mesa/drivers/dri/radeon/radeon_debug.h
+++ src/mesa/drivers/dri/radeon/radeon_debug.h
@@ -81,18 +81,24 @@ struct radeon_debug {
        char indent[RADEON_MAX_INDENT];
 };
 
-extern radeon_debug_type_t radeon_enabled_debug_types;
-
 /**
  * Compabibility layer for old debug code
  **/
-#define RADEON_DEBUG radeon_enabled_debug_types
+#if defined(RADEON_R200)
+extern radeon_debug_type_t r200_enabled_debug_types;
+#define RADEON_DEBUG r200_enabled_debug_types
+#elif defined(RADEON_R100)
+extern radeon_debug_type_t r100_enabled_debug_types;
+#define RADEON_DEBUG r100_enabled_debug_types
+#else
+#error "Neither RADEON_R100 nor RADEON_R200 are defined."
+#endif
 
 static inline int radeon_is_debug_enabled(const radeon_debug_type_t type,
 	   const radeon_debug_level_t level)
 {
        return RADEON_DEBUG_LEVEL >= level
-		&& (type & radeon_enabled_debug_types);
+		&& (type & RADEON_DEBUG);
 }
 
 extern void _radeon_print(const radeon_debug_type_t type,
