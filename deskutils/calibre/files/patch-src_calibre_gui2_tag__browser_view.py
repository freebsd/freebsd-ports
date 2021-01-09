--- src/calibre/gui2/tag_browser/view.py.orig	2021-01-08 03:40:13 UTC
+++ src/calibre/gui2/tag_browser/view.py
@@ -782,8 +782,9 @@ class TagsView(QTreeView):  # {{{
                                 partial(self.context_menu_handler, action='search',
                                         search_state=TAG_SEARCH_STATES['mark_plus'],
                                         index=index))
-                        if add_child_search := (tag.is_hierarchical == '5state' and
-                                                len(tag_item.children)):
+                        add_child_search = (tag.is_hierarchical == '5state' and
+                                            len(tag_item.children))
+                        if add_child_search:
                             search_submenu.addAction(self.search_icon,
                                     _('Search for %s and its children')%display_name(tag),
                                     partial(self.context_menu_handler, action='search',
