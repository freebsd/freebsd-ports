--- Source/FramePICDiagram.pas.orig	2021-08-01 06:56:07 UTC
+++ Source/FramePICDiagram.pas
@@ -573,13 +573,13 @@ begin
   //Cuerpo
   col := GetThevCol(nodParent.vt, nodParent.rt);  //Se supone que el nodo padre ya está actualizado
   v2d.SetPen(psSolid, 1, col);
-  v2d.Linea(pcBEGIN.x, pcBEGIN.y, pcEND.x, pcEND.y);
+  v2d.Line(pcBEGIN.x, pcBEGIN.y, pcEND.x, pcEND.y);
   //Implementamos nosotros el remarcado y selección, para personalizar mejor
   //---------------Draw mark --------------
   if Marked and Highlight then begin
     //Resaltado
     v2d.SetPen(psSolid, 2, clBlue);   //RGB(128, 128, 255)
-    v2d.Linea(pcBEGIN.x, pcBEGIN.y, pcEND.x, pcEND.y);
+    v2d.Line(pcBEGIN.x, pcBEGIN.y, pcEND.x, pcEND.y);
     //Marcador de Voltaje
     v2d.SetPen(psSolid, 1, clBlack);   //RGB(128, 128, 255)
     v2d.SetBrush(clYellow);
@@ -824,8 +824,8 @@ begin
   //Dibuja cuerpo
   v2d.SetPen(psSolid, 2, COL_GND);
   //Línea vertioal y conexión a tierra
-  v2d.Linea(x+12, y, x+12, y2);
-  v2d.Linea(x+5, y2, x+19, y2);
+  v2d.Line(x+12, y, x+12, y2);
+  v2d.Line(x+5, y2, x+19, y2);
   //Resistencia
   v2d.SetPen(psSolid, 1, COL_GND);
   v2d.SetBrush(COL_RES);
@@ -932,15 +932,15 @@ begin
   //conexión a tierra
   v2d.SetPen(psSolid, 1, COL_GND);
   y2 := y + height + 10;
-  v2d.Linea(x+30, y+height, x+30, y2);
-  v2d.Linea(x+24, y2, x+36, y2);
+  v2d.Line(x+30, y+height, x+30, y2);
+  v2d.Line(x+24, y2, x+36, y2);
   //Dibuja los pines
   v2d.SetPen(psSolid, 1, COL_GND);
   for pCnx in PtosConex do begin
     pin := TPinGraph(pCnx);
     //En el PIC, los pines se pintan con el color del modelo interno
     v2d.SetBrush(clWhite);  //Rellena de acuerdo al estado
-    v2d.Linea(pin.x, pin.y, pin.x+7, pin.y);
+    v2d.Line(pin.x, pin.y, pin.x+7, pin.y);
     v2d.Texto(x+pin.xLbl, y+pin.yLbl, pin.lbl);
   end;
   inherited;
@@ -999,8 +999,8 @@ begin
 
   //Línea vertioal y conexión a tierra
   v2d.SetPen(psSolid, 2, COL_GND);
-  v2d.Linea(x+12, y, x+12, y2);
-  v2d.Linea(x+5, y2, x+19, y2);
+  v2d.Line(x+12, y, x+12, y2);
+  v2d.Line(x+5, y2, x+19, y2);
   //Resistencia
   v2d.SetPen(psSolid, 1, COL_GND);
   v2d.SetBrush(COL_RES);
@@ -1044,7 +1044,7 @@ begin
       nod.UpdateModel;
     end;
   end; //Protección
-  motEdi.Refrescar;
+  motEdi.Refresh;
 end;
 procedure TfraPICDiagram.SetCompiler(cxp0: TCompilerBase);
 begin
@@ -1135,7 +1135,7 @@ var
 begin
   nodeList.Clear;
   //Explora objetos gráfiocs
-  for og in motEdi.objetos do begin
+  for og in motEdi.objects do begin
     if og is TOgConector then begin
       ogCon := TOgConector(og);
       AddConnectorToNodes(ogCon);
@@ -1151,7 +1151,7 @@ function TfraPICDiagram.ExistsName(AName: string): boo
 var
   og: TObjGraf;
 begin
-  for og in motEdi.objetos do begin
+  for og in motEdi.objects do begin
     if og.Name = AName then exit(true);
   end;
   exit(false);
@@ -1174,7 +1174,7 @@ function TfraPICDiagram.ExistsRef(ARef: string): TOgCo
 var
   og: TObjGraf;
 begin
-  for og in motEdi.objetos do begin
+  for og in motEdi.objects do begin
     if not(og is TOgComponent) then continue;
     if TOgComponent(og).Ref = ARef then exit(TOgComponent(og));
   end;
@@ -1201,7 +1201,7 @@ var
   //oc: TOgConector;
   //xv, yv: Single;
 begin
-  if motEdi.seleccion.Count = 1 then begin
+  if motEdi.selection.Count = 1 then begin
     //Hay uno seleccionado
     if motEdi.Selected.IsSelectedBy(X,Y) then begin
       //Click sobre un objeto seleccionado
@@ -1240,7 +1240,7 @@ procedure TfraPICDiagram.motEdi_MouseUp(Sender: TObjec
 var
   LogInp: TOgLogicState;
 begin
-  if motEdi.seleccion.Count = 1 then begin
+  if motEdi.selection.Count = 1 then begin
     //Hay un componente seleccionado
     if motEdi.Selected.IsSelectedBy(X,Y) then begin
       if motEdi.Selected is TOgLogicState then begin
@@ -1267,15 +1267,15 @@ var
   pCnx, pCnx2: TPtoConx;
 begin
   //Verifica el estado para activar acciones
-  acGenDelObject.Visible := motEdi.seleccion.Count>0;
-  if motEdi.seleccion.Count = 0 then begin
+  acGenDelObject.Visible := motEdi.selection.Count>0;
+  if motEdi.selection.Count = 0 then begin
     //Ninguno seleccionado
     mnReset.Visible   := true;
     mnRun.Visible     := true;
     mnStepOver.Visible:= false;
     //mnAddLogicTog.Visible := true;
     VisibActionsAdd(true);
-  end else if (motEdi.seleccion.Count = 1) and (motEdi.Selected is TOgComponent) then begin
+  end else if (motEdi.selection.Count = 1) and (motEdi.Selected is TOgComponent) then begin
     //Hay un componente seleccionado
     comp1 := TOgComponent(motEdi.Selected);  //Componente fuente
     mnReset.Visible   := true;
@@ -1308,7 +1308,7 @@ begin
     mnConnect.Caption := Format('Connect %s to', [pin1.lbl]);
     //Actualiza menú de Conexión, con objetos gráficos
     mnConnect.Clear;
-    for og in motEdi.objetos do begin
+    for og in motEdi.objects do begin
       if not(og is TOgComponent) then continue;
       if og is TOgConector then continue;;
       it := AddItemToMenu(mnConnect, og.Name, nil);
@@ -1454,7 +1454,7 @@ var
 begin
   nodeList.Clear;
   //Explora objetos gráfiocs
-  for og in motEdi.objetos do begin
+  for og in motEdi.objects do begin
     if og is TOgConector then begin
       ogCon := TOgConector(og);
       if ogCon.pcBEGIN.ConnectedTo = nil then begin
