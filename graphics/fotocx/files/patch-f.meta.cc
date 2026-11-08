--- f.meta.cc.orig	2026-09-30 11:06:25 UTC
+++ f.meta.cc
@@ -975,7 +975,9 @@ void m_meta_edit_main(GtkWidget *, ch *menu)
       zdialog_add_widget(zd,"button","geofind","hbgeo",TX("Find"),"space=5");
       zdialog_add_widget(zd,"button","geoprev","hbgeo",TX("Previous"),"space=5");      //  25.1
       zdialog_add_widget(zd,"button","geoclear","hbgeo",TX("Clear"),"space=5");
+#ifdef NETMAP_SUPPORT
       zdialog_add_widget(zd,"button","geomap","hbgeo",TX("Map"),"space=5");            //  26.7
+#endif
 
       zdialog_add_widget(zd,"hsep","sep","dialog",0,"space=3");
 
@@ -1018,7 +1020,9 @@ void m_meta_edit_main(GtkWidget *, ch *menu)
       zdialog_add_ttip(zd,"geofind",TX("search known locations"));
       zdialog_add_ttip(zd,"geoprev",TX("use previous location"));
       zdialog_add_ttip(zd,"geoclear",TX("clear inputs"));
+#ifdef NETMAP_SUPPORT
       zdialog_add_ttip(zd,"geomap",TX("set location from world map"));                 //  26.7
+#endif
 
       load_defkeywords(0);                                                             //  stuff defined keywords into dialog
       defkeywords_stuff(zd,"ALL");
@@ -1230,6 +1234,7 @@ int editmeta_dialog_event(zdialog *zd, ch *event)
       return 1;
    }
    
+#ifdef NETMAP_SUPPORT
    if (strmatch(event,"geomap")) {                                                     //  choose geocoordinates from map        26.7
       m_show_on_map(0,0);
       return 1;
@@ -1239,6 +1244,7 @@ int editmeta_dialog_event(zdialog *zd, ch *event)
       Fmetamod++;
       return 1;
    }
+#endif
    
    if (strmatch(event,"geoprev"))                                                      //  [previous] use previous location      25.1
    {
@@ -4537,10 +4543,12 @@ int batch_geotags_dialog_event(zdialog *zd, ch *event)
    if (zstat == 1)                                                                     //  [find]
    {
       nn = find_location(zd);                                                          //  search image location data            26.0
+#ifdef NETMAP_SUPPORT
       if (nn < 2) {                                                                    //  multiple geocoordinates?
          zmessage_post(Mwin,"40/40",3,TX("choose location"));                          //  inform user                           26.7
          m_show_on_map(0,0);                                                           //  resolve multiple geocoordinates       26.7
       }
+#endif
       return 1;
    }
 
