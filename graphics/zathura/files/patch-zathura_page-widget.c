X-Git-Url: https://git.pwmt.org/?p=zathura.git;a=blobdiff_plain;f=zathura%2Fpage-widget.c;h=ad27c273f1ba04b66dd8a84337febec3729a68af;hp=309f63321cdbc27694fcba964faa3c4ecc48295f;hb=8d71a755d648c5856ef91d214bfdb46925f6c2f0;hpb=10f3da57c65a8ed7d4d3beff3e49da2bcddcf7a7

diff --git zathura/page-widget.c zathura/page-widget.c.orig
index 309f633..ad27c27 100644
--- zathura/page-widget.c
+++ zathura/page-widget.c.orig
@@ -28,8 +28,8 @@ typedef struct zathura_page_widget_private_s {
 
   struct {
     girara_list_t* list; /**< List of links on the page */
-    bool retrieved; /**< True if we already tried to retrieve the list of links */
-    bool draw; /**< True if links should be drawn */
+    gboolean retrieved; /**< True if we already tried to retrieve the list of links */
+    gboolean draw; /**< True if links should be drawn */
     unsigned int offset; /**< Offset to the links */
     unsigned int n; /**< Number */
   } links;
@@ -37,12 +37,12 @@ typedef struct zathura_page_widget_private_s {
   struct {
     girara_list_t* list; /**< A list if there are search results that should be drawn */
     int current; /**< The index of the current search result */
-    bool draw; /**< Draw search results */
+    gboolean draw; /**< Draw search results */
   } search;
 
   struct {
     girara_list_t* list; /**< List of images on the page */
-    bool retrieved; /**< True if we already tried to retrieve the list of images */
+    gboolean retrieved; /**< True if we already tried to retrieve the list of images */
     zathura_image_t* current; /**< Image data of selected image */
   } images;
 
@@ -52,7 +52,7 @@ typedef struct zathura_page_widget_private_s {
       int x; /**< X coordinate */
       int y; /**< Y coordinate */
     } selection_basepoint;
-    bool over_link;
+    gboolean over_link;
   } mouse;
 } zathura_page_widget_private_t;
 
@@ -313,13 +313,13 @@ zathura_page_widget_set_property(GObject* object, guint prop_id, const GValue* v
     case PROP_DRAW_LINKS:
       priv->links.draw = g_value_get_boolean(value);
       /* get links */
-      if (priv->links.draw == true && priv->links.retrieved == false) {
+      if (priv->links.draw == TRUE && priv->links.retrieved == FALSE) {
         priv->links.list      = zathura_page_links_get(priv->page, NULL);
-        priv->links.retrieved = true;
+        priv->links.retrieved = TRUE;
         priv->links.n         = (priv->links.list == NULL) ? 0 : girara_list_size(priv->links.list);
       }
 
-      if (priv->links.retrieved == true && priv->links.list != NULL) {
+      if (priv->links.retrieved == TRUE && priv->links.list != NULL) {
         GIRARA_LIST_FOREACH(priv->links.list, zathura_link_t*, iter, link)
         if (link != NULL) {
           zathura_rectangle_t rectangle = recalc_rectangle(priv->page, zathura_link_get_position(link));
@@ -338,7 +338,7 @@ zathura_page_widget_set_property(GObject* object, guint prop_id, const GValue* v
       }
       priv->search.list = g_value_get_pointer(value);
       if (priv->search.list != NULL && priv->search.draw) {
-        priv->links.draw = false;
+        priv->links.draw = FALSE;
         redraw_all_rects(pageview, priv->search.list);
       }
       priv->search.current = -1;
@@ -355,7 +355,7 @@ zathura_page_widget_set_property(GObject* object, guint prop_id, const GValue* v
         priv->search.current = girara_list_size(priv->search.list);
       } else {
         priv->search.current = val;
-        if (priv->search.draw == true && val >= 0 && val < (signed) girara_list_size(priv->search.list)) {
+        if (priv->search.draw == TRUE && val >= 0 && val < (signed) girara_list_size(priv->search.list)) {
           zathura_rectangle_t* rect = girara_list_nth(priv->search.list, priv->search.current);
           zathura_rectangle_t rectangle = recalc_rectangle(priv->page, *rect);
           redraw_rect(pageview, &rectangle);
