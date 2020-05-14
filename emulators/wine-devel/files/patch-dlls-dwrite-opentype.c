The following is a backport of code contributed between Wine 5.8 and 5.9;
it should be included in Wine 5.9 released later this month at which point
this patch can (and should) go again.

commit 23543f20058d1655d3ad552474ce99c01bbd78ea
Author: Gijs Vermeulen <gijsvrm@gmail.com>
Date:   Mon May 11 15:43:59 2020 +0200

    dwrite: Set ret on unimplemented lookup in opentype_layout_apply_gsub_lookup.
    
    Signed-off-by: Gijs Vermeulen <gijsvrm@gmail.com>
    Signed-off-by: Nikolay Sivov <nsivov@codeweavers.com>
    Signed-off-by: Alexandre Julliard <julliard@winehq.org>

--- UTC
diff --git dlls/dwrite/opentype.c dlls/dwrite/opentype.c
index 0feb2feadc..f22cd7469b 100644
--- dlls/dwrite/opentype.c
+++ dlls/dwrite/opentype.c
@@ -4478,6 +4478,7 @@ static void opentype_layout_apply_gsub_lookup(struct scriptshaping_context *cont
             case GSUB_LOOKUP_LIGATURE_SUBST:
             case GSUB_LOOKUP_CONTEXTUAL_SUBST:
             case GSUB_LOOKUP_REVERSE_CHAINING_CONTEXTUAL_SUBST:
+                ret = FALSE;
                 WARN("Unimplemented lookup %d.\n", lookup_type);
                 break;
             default:
