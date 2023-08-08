From 0a4e3146cc97517ae09c1d854973ca26e46af33b Mon Sep 17 00:00:00 2001
From: Khem Raj <raj.khem@gmail.com>
Date: Tue, 30 Aug 2022 22:33:46 -0700
Subject: [PATCH] scope: Use FALSE instead of NULL for gboolean

Fixes warnings with clang 15+

scope/src/stack.c:168:11: error: incompatible pointer to integer conversion initializing 'gboolean' (aka 'int') with an expression of type 'void *' [-Wint-conversion]
        gboolean entry = NULL;
                 ^       ~~~~
1 error generated.

Signed-off-by: Khem Raj <raj.khem@gmail.com>
---
 scope/src/stack.c | 2 +-
 1 file changed, 1 insertion(+), 1 deletion(-)

diff --git a/scope/src/stack.c b/scope/src/stack.c
index b03909feb..ce6e2a472 100644
--- scope/src/stack.c
+++ scope/src/stack.c
@@ -165,7 +165,7 @@ void on_stack_follow(GArray *nodes)
 gboolean stack_entry(void)
 {
 	GtkTreeIter iter;
-	gboolean entry = NULL;
+	gboolean entry = FALSE;
 
 	if (gtk_tree_selection_get_selected(selection, NULL, &iter))
 	{
