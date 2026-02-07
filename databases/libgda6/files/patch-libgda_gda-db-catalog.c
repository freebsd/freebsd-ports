../libgda/gda-db-catalog.c:832:8: error: variable 'ntables' set but not used [-Werror,-Wunused-but-set-variable]
  832 |   gint ntables = 0;
      |        ^
../libgda/gda-db-catalog.c:833:8: error: variable 'nviews' set but not used [-Werror,-Wunused-but-set-variable]
  833 |   gint nviews = 0;
      |        ^
2 errors generated.

--- libgda/gda-db-catalog.c.orig	2025-03-02 15:03:58 UTC
+++ libgda/gda-db-catalog.c
@@ -829,9 +829,6 @@ gda_db_catalog_parse_cnc (GdaDbCatalog *self,
 
   GSList *it = NULL;
 
-  gint ntables = 0;
-  gint nviews = 0;
-
   for (it=dblist; it; it = it->next)
     {
       if(GDA_META_DB_OBJECT(it->data)->obj_type == GDA_META_DB_TABLE)
@@ -841,7 +838,6 @@ gda_db_catalog_parse_cnc (GdaDbCatalog *self,
             continue;
 
           priv->mp_tables = g_list_append (priv->mp_tables,table);
-	  ntables++;
           continue;
         }
 
@@ -854,7 +850,6 @@ gda_db_catalog_parse_cnc (GdaDbCatalog *self,
 
 	  g_print ("%s:%d Found %s view\n", __FILE__, __LINE__, gda_db_base_get_full_name(GDA_DB_BASE (view)));
           priv->mp_views = g_list_append (priv->mp_views, view);
-	  nviews++;
           continue;
         }
     }
