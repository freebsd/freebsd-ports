--- lib/qof/qofgobj.c.orig	Mon May 24 19:55:16 2004
+++ lib/qof/qofgobj.c	Mon May 24 20:01:38 2004
@@ -57,10 +57,11 @@
 void 
 qof_gobject_shutdown (void)
 {
+  GSList *n;
+
   if (!initialized) return;
   initialized = FALSE;
                                                                                 
-  GSList *n;
   for (n=paramList; n; n=n->next) g_free(n->data);
   g_slist_free (paramList);
 
@@ -83,11 +84,14 @@
 void 
 qof_gobject_register_instance (QofBook *book, QofType type, GObject *gob)
 {
+  QofCollection *coll;
+  GSList * instance_list;
+
   if (!book || !type) return;
 
-  QofCollection *coll = qof_book_get_collection (book, type);
+  coll = qof_book_get_collection (book, type);
 
-  GSList * instance_list = qof_collection_get_data (coll);
+  instance_list = qof_collection_get_data (coll);
   instance_list = g_slist_prepend (instance_list, gob);
   qof_collection_set_data (coll, instance_list);
 }
@@ -101,6 +105,8 @@
 
   GParamSpec *gps = getter->param_userdata;
 
+  const char * str;
+
   /* Note that the return type must actually be of type
    * getter->param_type but we just follow the hard-coded 
    * mapping below ... */
@@ -110,37 +116,40 @@
     g_value_init (&gval, G_TYPE_STRING);
     g_object_get_property (gob, getter->param_name, &gval);
 
-    const char * str = g_value_get_string (&gval);
+    str = g_value_get_string (&gval);
     return (gpointer) str;
   }
   else
   if (G_IS_PARAM_SPEC_INT(gps))
   {
+    int ival;
     GValue gval = {G_TYPE_INVALID};
     g_value_init (&gval, G_TYPE_INT);
     g_object_get_property (gob, getter->param_name, &gval);
 
-    int ival = g_value_get_int (&gval);
+    ival = g_value_get_int (&gval);
     return (gpointer) ival;
   }
   else
   if (G_IS_PARAM_SPEC_UINT(gps))
   {
+    int ival;
     GValue gval = {G_TYPE_INVALID};
     g_value_init (&gval, G_TYPE_UINT);
     g_object_get_property (gob, getter->param_name, &gval);
 
-    int ival = g_value_get_uint (&gval);
+    ival = g_value_get_uint (&gval);
     return (gpointer) ival;
   }
   else
   if (G_IS_PARAM_SPEC_BOOLEAN(gps))
   {
+    int ival;
     GValue gval = {G_TYPE_INVALID};
     g_value_init (&gval, G_TYPE_BOOLEAN);
     g_object_get_property (gob, getter->param_name, &gval);
 
-    int ival = g_value_get_boolean (&gval);
+    ival = g_value_get_boolean (&gval);
     return (gpointer) ival;
   }
 
@@ -161,21 +170,23 @@
    * mapping below ... */
   if (G_IS_PARAM_SPEC_FLOAT(gps))
   {
+    double fval;
     GValue gval = {G_TYPE_INVALID};
     g_value_init (&gval, G_TYPE_FLOAT);
     g_object_get_property (gob, getter->param_name, &gval);
 
-    double fval = g_value_get_float (&gval);
+    fval = g_value_get_float (&gval);
     return fval;
   }
   else
   if (G_IS_PARAM_SPEC_DOUBLE(gps))
   {
+    double fval;
     GValue gval = {G_TYPE_INVALID};
     g_value_init (&gval, G_TYPE_DOUBLE);
     g_object_get_property (gob, getter->param_name, &gval);
 
-    double fval = g_value_get_double (&gval);
+    fval = g_value_get_double (&gval);
     return fval;
   } 
 
@@ -208,13 +219,16 @@
   /* Get the GObject properties, convert to QOF properties */
   GParamSpec **prop_list;
   int n_props;
+  int i, j=0;
+  QofParam * qof_param_list;
+  QofObject *class_def;
+
   prop_list = g_object_class_list_properties (obclass, &n_props);
 
-  QofParam * qof_param_list = g_new0 (QofParam, n_props);
+  qof_param_list = g_new0 (QofParam, n_props);
   paramList = g_slist_prepend (paramList, qof_param_list);
 
   PINFO ("object %s has %d props", e_type, n_props);
-  int i, j=0;
   for (i=0; i<n_props; i++)
   {
     GParamSpec *gparam = prop_list[i];
@@ -288,7 +302,7 @@
 
   /* ------------------------------------------------------ */
    /* Now do the class itself */
-  QofObject *class_def = g_new0 (QofObject, 1);
+  class_def = g_new0 (QofObject, 1);
   classList = g_slist_prepend (classList, class_def);
 
   class_def->interface_version = QOF_OBJECT_VERSION;
