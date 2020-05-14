--- Source/FramePICDiagram.pas	2020-05-13 15:24:28.472849000 -0500
+++ Source/FramePICDiagram.pas	2020-05-13 15:21:41.106017000 -0500
@@ -1135,7 +1135,7 @@
 begin
   nodeList.Clear;
   //Explora objetos gráfiocs
-  for og in motEdi.objetos do begin
+  for og in motEdi.objects do begin
     if og is TOgConector then begin
       ogCon := TOgConector(og);
       AddConnectorToNodes(ogCon);
@@ -1151,7 +1151,7 @@
 var
   og: TObjGraf;
 begin
-  for og in motEdi.objetos do begin
+  for og in motEdi.objects do begin
     if og.Name = AName then exit(true);
   end;
   exit(false);
@@ -1174,7 +1174,7 @@
 var
   og: TObjGraf;
 begin
-  for og in motEdi.objetos do begin
+  for og in motEdi.objects do begin
     if not(og is TOgComponent) then continue;
     if TOgComponent(og).Ref = ARef then exit(TOgComponent(og));
   end;
@@ -1201,7 +1201,7 @@
   //oc: TOgConector;
   //xv, yv: Single;
 begin
-  if motEdi.seleccion.Count = 1 then begin
+  if motEdi.selection.Count = 1 then begin
     //Hay uno seleccionado
     if motEdi.Selected.IsSelectedBy(X,Y) then begin
       //Click sobre un objeto seleccionado
@@ -1240,7 +1240,7 @@
 var
   LogInp: TOgLogicState;
 begin
-  if motEdi.seleccion.Count = 1 then begin
+  if motEdi.selection.Count = 1 then begin
     //Hay un componente seleccionado
     if motEdi.Selected.IsSelectedBy(X,Y) then begin
       if motEdi.Selected is TOgLogicState then begin
@@ -1267,15 +1267,15 @@
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
@@ -1308,7 +1308,7 @@
     mnConnect.Caption := Format('Connect %s to', [pin1.lbl]);
     //Actualiza menú de Conexión, con objetos gráficos
     mnConnect.Clear;
-    for og in motEdi.objetos do begin
+    for og in motEdi.objects do begin
       if not(og is TOgComponent) then continue;
       if og is TOgConector then continue;;
       it := AddItemToMenu(mnConnect, og.Name, nil);
@@ -1454,7 +1454,7 @@
 begin
   nodeList.Clear;
   //Explora objetos gráfiocs
-  for og in motEdi.objetos do begin
+  for og in motEdi.objects do begin
     if og is TOgConector then begin
       ogCon := TOgConector(og);
       if ogCon.pcBEGIN.ConnectedTo = nil then begin
