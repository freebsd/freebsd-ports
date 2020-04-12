--- src/routemanagerdialog.cpp.orig	2020-01-13 18:06:15 UTC
+++ src/routemanagerdialog.cpp
@@ -948,7 +948,7 @@ void RouteManagerDialog::UpdateRouteListCtrl()
         list_index++;
     }
 
-    m_pRouteListCtrl->SortItems( SortRoutesOnName, NULL );
+    m_pRouteListCtrl->SortItems( SortRoutesOnName, 0 );
 
     m_pRouteListCtrl->SetColumnWidth(0, 4 * m_charWidth);
     
@@ -1356,11 +1356,11 @@ void RouteManagerDialog::OnRteColumnClicked( wxListEve
     if( event.m_col == 1 ) {
         sort_route_name_dir++;
 
-        m_pRouteListCtrl->SortItems( SortRoutesOnName, NULL );
+        m_pRouteListCtrl->SortItems( SortRoutesOnName, 0 );
     } else
         if( event.m_col == 2 ) {
             sort_route_to_dir++;
-            m_pRouteListCtrl->SortItems( SortRoutesOnTo, NULL );
+            m_pRouteListCtrl->SortItems( SortRoutesOnTo, 0 );
         }
 }
 
@@ -1635,11 +1635,11 @@ void RouteManagerDialog::UpdateTrkListCtrl()
 
     switch( sort_track_key ){
             case SORT_ON_DISTANCE:
-                m_pTrkListCtrl->SortItems( SortTracksOnDistance, NULL );
+                m_pTrkListCtrl->SortItems( SortTracksOnDistance, 0 );
                 break;
             case SORT_ON_NAME:
             default:
-                m_pTrkListCtrl->SortItems( SortTracksOnName, NULL );
+                m_pTrkListCtrl->SortItems( SortTracksOnName, 0 );
                 break;
     }
 
@@ -1668,12 +1668,12 @@ void RouteManagerDialog::OnTrkColumnClicked( wxListEve
     if( event.m_col == 1 ) {
         sort_track_key = SORT_ON_NAME;
         sort_track_name_dir++;
-        m_pTrkListCtrl->SortItems( SortTracksOnName, NULL );
+        m_pTrkListCtrl->SortItems( SortTracksOnName, 0 );
     } else
         if( event.m_col == 2 ) {
             sort_track_key = SORT_ON_DISTANCE;
             sort_track_len_dir++;
-            m_pTrkListCtrl->SortItems( SortTracksOnDistance, NULL );
+            m_pTrkListCtrl->SortItems( SortTracksOnDistance, 0 );
         }
 }
 
@@ -2372,11 +2372,11 @@ void RouteManagerDialog::OnLayColumnClicked( wxListEve
 {
     if( event.m_col == 1 ) {
         sort_layer_name_dir++;
-        m_pLayListCtrl->SortItems( SortLayersOnName, NULL );
+        m_pLayListCtrl->SortItems( SortLayersOnName, 0 );
     } else
         if( event.m_col == 2 ) {
             sort_layer_len_dir++;
-            m_pLayListCtrl->SortItems( SortLayersOnSize, NULL );
+            m_pLayListCtrl->SortItems( SortLayersOnSize, 0 );
         }
 }
 
