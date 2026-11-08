--- f.widgets.cc.orig	2026-09-30 11:06:25 UTC
+++ f.widgets.cc
@@ -454,8 +454,10 @@ void build_widgets()
    MENU(mGallery,  TX("Select Files"), 0,          select_files_tip,             m_select_files, 0 );
    MENU(mGallery,  TX("Bookmarks"), 0,             bookmarks_tip,                m_bookmarks, 0 );
 
+#ifdef NETMAP_SUPPORT
    mMaps = create_popmenu();
    MENU(mMaps,     TX("Show on Map"), 0,         show_on_map_tip,              m_show_on_map,  0 );                          //  26.7
+#endif
 
    mAlbums = create_popmenu();                                                                                               //  25.1
    MENU(mAlbums,   TX("Create Album"), 0,        create_album_tip,             m_album_create, 0 );
@@ -828,7 +830,9 @@ void build_widgets()
    KBshort(TX("Set Colors"),            m_set_colors,              0     );
    KBshort(TX("Settings"),              m_settings,                0     );
    KBshort(TX("Sharpen"),               m_sharpen,                 0     );
+#ifdef NETMAP_SUPPORT
    KBshort(TX("Show on Map"),           m_show_on_map,             0     );
+#endif
    KBshort(TX("Show Resources"),        m_resources,               0     );
    KBshort(TX("Metadata Tags"),         m_meta_tags,               0     );
    KBshort(TX("Timeline"),              m_meta_timeline,           0     );
@@ -968,7 +972,9 @@ void popup_menufunc(GtkWidget *, ch *menu)
    if (strmatch(menu,"local contrast")) m_localcon(0,0);
    if (strmatch(menu,"amplify contrast")) m_amplifycon(0,0);
    if (strmatch(menu,"saturation")) m_saturation(0,0);
+#ifdef NETMAP_SUPPORT
    if (strmatch(menu,"show on map")) m_show_on_map(0,0);
+#endif
    if (strmatch(menu,"add to selection")) add_file_to_selection(curr_file);
    if (strmatch(menu,"popimage")) gallery_popimage();
    if (strmatch(menu,"albumaddselfiles")) album_add_selfiles(2);
@@ -1138,7 +1144,9 @@ void viewmode(ch fgm)                                 
       Cdrawin = 0;
       Fgdkwin = 0;
 
+#ifdef NETMAP_SUPPORT
       m_load_netmap(0,0);                                                              //  show internet map
+#endif
    }
 
    return;
