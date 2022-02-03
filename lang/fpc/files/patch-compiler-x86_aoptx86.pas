--- compiler/x86/aoptx86.pas	2022-01-25 22:18:01.236523000 -0500
+++ compiler/x86/aoptx86.pas	2022-01-25 22:34:15.492397000 -0500
@@ -2761,6 +2761,7 @@
                       if (l<=4) and (l>0) then
                         begin
                           condition:=inverse_cond(taicpu(p).condition);
+                          UpdateUsedRegs(tai(p.next));
                           GetNextInstruction(p,hp1);
                           repeat
                             if not Assigned(hp1) then
@@ -2768,7 +2769,7 @@
 
                             taicpu(hp1).opcode:=A_CMOVcc;
                             taicpu(hp1).condition:=condition;
-                            UpdateUsedRegs(hp1);
+                            UpdateUsedRegs(tai(hp1.next));
                             GetNextInstruction(hp1,hp1);
                           until not(CanBeCMOV(hp1));
 
@@ -2815,6 +2816,7 @@
                           asml.Remove(p);
                           p.Free;
 
+                          UpdateUsedRegs(tai(hp2.next));
                           GetNextInstruction(hp2, p); { Instruction after the label }
 
                           { Remove the label if this is its final reference }
@@ -2878,6 +2880,7 @@
                              FindLabel(tasmlabel(taicpu(hp2).oper[0]^.ref^.symbol),hp1) then
                              begin
                                 condition:=inverse_cond(taicpu(p).condition);
+                                UpdateUsedRegs(tai(p.next));
                                 GetNextInstruction(p,hp1);
                                 repeat
                                   taicpu(hp1).opcode:=A_CMOVcc;
@@ -2888,19 +2891,23 @@
                                   not(CanBeCMOV(hp1));
 
                                 condition:=inverse_cond(condition);
+                                if GetLastInstruction(hpmov2,hp1) then
+                                  UpdateUsedRegs(tai(hp1.next));
+
                                 hp1 := hpmov2;
                                 { hp1 is now at <several movs 2> }
                                 while Assigned(hp1) and CanBeCMOV(hp1) do
                                   begin
                                     taicpu(hp1).opcode:=A_CMOVcc;
                                     taicpu(hp1).condition:=condition;
-                                    UpdateUsedRegs(hp1);
+                                    UpdateUsedRegs(tai(hp1.next));
                                     GetNextInstruction(hp1,hp1);
                                   end;
 
                                 hp1 := p;
 
                                 { Get first instruction after label }
+                                UpdateUsedRegs(tai(hp3.next));
                                 GetNextInstruction(hp3, p);
 
                                 if assigned(p) and (hp3.typ = ait_align) then
@@ -2955,10 +2962,7 @@
                                   end;
 
                                 if Assigned(p) then
-                                  begin
-                                    UpdateUsedRegs(p);
-                                    result:=true;
-                                  end;
+                                  result:=true;
                                 exit;
                              end;
                          end;
