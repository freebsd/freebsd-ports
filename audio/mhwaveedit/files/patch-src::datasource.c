--- src/datasource.c.orig	Tue Dec 23 07:06:26 2003
+++ src/datasource.c	Sat Dec 27 00:59:02 2003
@@ -212,8 +212,8 @@
 
 Datasource *datasource_byteswap(Datasource *source)
 {
-     if (source == NULL) return NULL;
      Datasource *ds;
+     if (source == NULL) return NULL;
      ds = gtk_type_new(datasource_get_type());
      ds->type = DATASOURCE_BYTESWAP;
      memcpy(&(ds->format),&(source->format),sizeof(Dataformat));
