--- gok/gok-data.c.orig	Mon Jun  2 21:49:16 2003
+++ gok/gok-data.c	Mon Jun  2 21:49:26 2003
@@ -707,8 +707,8 @@
  */
 void gok_data_set_is_dock (GokDockType val)
 {
-	m_eDockType = val;
 	gchar *typestring;
+	m_eDockType = val;
 	switch (val) {
 	case GOK_DOCK_TOP:
 	  typestring = "top";
