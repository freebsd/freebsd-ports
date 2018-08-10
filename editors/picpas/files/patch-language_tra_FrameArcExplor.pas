--- language/tra_FrameArcExplor.pas	2018-08-10 03:04:43.663098000 -0500
+++ language/tra_FrameArcExplor.pas	2018-08-10 03:07:17.558532000 -0500
@@ -19,33 +19,33 @@
   TXT_DELFILE     := Trans('Delete file "%s"?', '¿Eliminar archivo "%s"?', '',
                            ''              , ''            , '',
                            'Supprimer fichier "%s" ?');
-  mnCarAbrirExpWin.Caption := Trans('Open on &Windows Explorer', 'Abrir en Explor. de &Windows', '',
+  mnFolOpenInExplor.Caption := Trans('Open on &Windows Explorer', 'Abrir en Explor. de &Windows', '',
                            ''              , ''            , '',
                            'Ouvrir dans l''Explorateur &Windows');
-  mnCarNueArc.Caption      := Trans('&New File'               , '&Nuevo Archivo', '',
+  mnFolNewFile.Caption      := Trans('&New File'               , '&Nuevo Archivo', '',
                            ''              , ''            , '',
                            '&Nouveau Fichier');
-  mnCarNueCar.Caption      := Trans('New &Folder'             , 'Nueva &Carpeta', '',
+  mnFolNewFolder.Caption      := Trans('New &Folder'             , 'Nueva &Carpeta', '',
                            ''              , ''            , '',
                            'Nouveau &Répertoire');
-  mnCarCamNom.Caption      := Trans('Cha&nge Name'            , 'Ca&mbiar Nombre', '',
+  mnFolChanName.Caption      := Trans('Cha&nge Name'            , 'Ca&mbiar Nombre', '',
                            ''              , ''            , '',
                            '&Renommer');
-  mnCarElimin.Caption      := Trans('&Delete'                 , 'El&iminar', '',
+  mnFolDelete.Caption      := Trans('&Delete'                 , 'El&iminar', '',
                            ''              , ''            , '',
                            '&Supprimer');
-  mnCarRefrescar.Caption   := Trans('&Refresh'                , '&Refrescar', '',
+  mnFolRefresh.Caption   := Trans('&Refresh'                , '&Refrescar', '',
                            ''              , ''            , '',
                            '&Rafraîchir');
-  mnArcAbrir.Caption       := Trans('&Open'                   , '&Abrir', '',
+  mnFilOpen.Caption       := Trans('&Open'                   , '&Abrir', '',
                            ''              , ''            , '',
                            '&Ouvrir');
-  mnArcCamNom.Caption      := Trans('Cha&nge Name'            , 'Ca&mbiar Nombre', '',
+  mnFilChanName.Caption      := Trans('Cha&nge Name'            , 'Ca&mbiar Nombre', '',
                            ''              , ''            , '',
                            '&Renommer');
-  mnArcElimin.Caption      := Trans('&Delete'                 , 'El&iminar', '',
+  mnFilDelete.Caption      := Trans('&Delete'                 , 'El&iminar', '',
                            ''              , ''            , '',
                            '&Supprimer');
-  mnArcRefrescar.Caption   := Trans('&Refresh'                 , '&Refrescar', '',
+  mnFilRefrescar.Caption   := Trans('&Refresh'                 , '&Refrescar', '',
                            ''              , ''            , '',
                            '&Rafraîchir');
