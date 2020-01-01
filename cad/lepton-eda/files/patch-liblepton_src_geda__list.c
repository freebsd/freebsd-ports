--- liblepton/src/geda_list.c.orig	2019-10-03 20:45:55 UTC
+++ liblepton/src/geda_list.c
@@ -1,7 +1,8 @@
-/* gEDA - GPL Electronic Design Automation
- * libgeda - gEDA's library
+/* Lepton EDA library
  * Copyright (C) 1998-2000 Ales Hvezda
  * Copyright (C) 2007-2010 Peter Clifton
+ * Copyright (C) 2011-2013 gEDA Contributors
+ * Copyright (C) 2017-2019 Lepton EDA Contributors
  *
  * This program is free software; you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
@@ -179,3 +180,22 @@ void geda_list_remove_all( GedaList *lis
   g_signal_emit( list, geda_list_signals[ CHANGED ], 0 );
 }
 
+
+/*! \brief Moves the list data \a item to a new position \a newpos.
+ */
+void geda_list_move_item( GedaList* list, gpointer item, gint newpos )
+{
+  GList* gl = list->glist;
+  GList* node = g_list_find (gl, item);
+
+  if (node != NULL)
+  {
+    gl = g_list_remove_link (gl, node);
+    gl = g_list_insert (gl, item, newpos);
+    g_list_free (node);
+    list->glist = gl;
+
+    g_signal_emit( list, geda_list_signals[ CHANGED ], 0 );
+  }
+}
+
