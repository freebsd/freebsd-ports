--- src/tvwidgets2.cc.orig	Tue Jan  1 20:43:01 2002
+++ src/tvwidgets2.cc	Thu Jun 26 02:25:30 2003
@@ -887,7 +887,7 @@
 const char *bfiletype_ext[bfiletype_num] = { "df3" };
 const char *bfiletype_def[bfiletype_num] = { " df3 " };
 
-TvWidget_blendmap::TvWidget_blendmap(  const char *name, const char *sname, const char *tooltip, app_objs *appref, bool is_colmap = false )
+TvWidget_blendmap::TvWidget_blendmap(  const char *name, const char *sname, const char *tooltip, app_objs *appref, bool is_colmap )
  : TvWidget( name, sname, tooltip, appref )
 {
 option_box = NULL;
