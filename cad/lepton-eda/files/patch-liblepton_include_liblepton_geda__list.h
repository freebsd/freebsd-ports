--- liblepton/include/liblepton/geda_list.h.orig	2019-10-03 20:45:55 UTC
+++ liblepton/include/liblepton/geda_list.h
@@ -1,7 +1,8 @@
-/* gEDA - GPL Electronic Design Automation
- * libgeda - gEDA's library
+/* Lepton EDA library
  * Copyright (C) 1998-2010 Ales Hvezda
  * Copyright (C) 2007-2010 Peter Clifton
+ * Copyright (C) 2011-2015 gEDA Contributors
+ * Copyright (C) 2017-2019 Lepton EDA Contributors
  *
  * This library is free software; you can redistribute it and/or
  * modify it under the terms of the GNU Library General Public
@@ -56,6 +57,9 @@ void geda_list_add_glist( GedaList *list
 void geda_list_remove( GedaList *list, gpointer item );
 /*void geda_list_remove_glist( GedaList *list, GList *items ); */ /* Undemanded as yet */
 void geda_list_remove_all( GedaList *list );
+void geda_list_move_item( GedaList* list, gpointer item, gint newpos );
+
+
 
 /*const GList *geda_list_get_glist( GedaList *list ); */
 #define geda_list_get_glist(list) (list->glist)
