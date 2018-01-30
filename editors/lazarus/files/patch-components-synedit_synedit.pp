--- components/synedit/synedit.pp	2018-01-30 13:41:54.904942000 -0500
+++ components/synedit/synedit.pp	2018-01-30 13:40:23.811860000 -0500
@@ -8945,7 +8945,7 @@
       while not Highlighter.GetEol do begin
         Start := Highlighter.GetTokenPos + 1;
         Token := Highlighter.GetToken;
-        if (PosX >= Start) and (PosX <= Start + Length(Token)) then begin
+        if (PosX >= Start) and (PosX < Start + Length(Token)) then begin
           Attri := Highlighter.GetTokenAttribute;
           TokenType := Highlighter.GetTokenKind;
           exit(True);
@@ -8990,7 +8990,7 @@
         //TokenType := Highlighter.GetTokenKind;
         Attri := Highlighter.GetTokenAttribute;
         //DebugLn(['  TCustomSynEdit.CaretAtIdentOrString: Start=', Start, ', Token=', Token]);
-        if (PosX >= Start) and (PosX <= Start + Length(Token)) then
+        if (PosX >= Start) and (PosX < Start + Length(Token)) then
         begin
           AtIdent := Attri = Highlighter.IdentifierAttribute;
           NearString := (Attri = Highlighter.StringAttribute)
