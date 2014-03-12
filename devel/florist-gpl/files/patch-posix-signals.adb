--- posix-signals.adb.orig	2012-05-10 13:32:11.000000000 +0000
+++ posix-signals.adb
@@ -340,16 +340,18 @@ package body POSIX.Signals is
    begin
       for Sig in Signal loop
          if Reserved_Signal (Sig) then
-            if Sig /= SIGKILL and then Sig /= SIGSTOP and then
-              sigismember (Set.C'Unchecked_Access, int (Sig)) = 1 then
-               Raise_POSIX_Error (Invalid_Argument);
+            if Sig /= SIGKILL and then Sig /= SIGSTOP then
+               if sigismember (Set.C'Unchecked_Access, int (Sig)) = 1 then
+                  Raise_POSIX_Error (Invalid_Argument);
+               end if;
             end if;
          else
             --  This signal might be attached to a
             --  task entry or protected procedure
             if sigismember (Set.C'Unchecked_Access, int (Sig)) = 1
-              and then (SI.Is_Entry_Attached (SIID (Sig))
-                or else SI.Is_Handler_Attached (SIID (Sig))) then
+               and then (SI.Is_Entry_Attached (SIID (Sig))
+               or else SI.Is_Handler_Attached (SIID (Sig)))
+            then
                Raise_POSIX_Error (Invalid_Argument);
             end if;
          end if;
@@ -466,7 +468,8 @@ package body POSIX.Signals is
      (Set : Signal_Set; Sig : Signal) return Boolean is
    begin
       if Sig = Signal_Null
-        or else sigismember (Set.C'Unchecked_Access, int (Sig)) = 1 then
+         or else sigismember (Set.C'Unchecked_Access, int (Sig)) = 1
+      then
          return True;
       end if;
       return False;
@@ -500,8 +503,7 @@ package body POSIX.Signals is
          if not Reserved_Signal (Sig) then
             --  It is OK to modify this signal's masking, using the
             --  interfaces of System.Interrupts.
-            if sigismember
-              (New_Mask.C'Unchecked_Access, int (Sig)) = 1 then
+            if sigismember (New_Mask.C'Unchecked_Access, int (Sig)) = 1 then
                if not SI.Is_Blocked (SIID (Sig)) then
                   Disposition (Sig) := SI_To_Mask;
                end if;
@@ -551,8 +553,7 @@ package body POSIX.Signals is
          if not Reserved_Signal (Sig) then
             --  It is OK to modify this signal's masking, using the
             --  interfaces of System.Interrupts.
-            if sigismember
-              (Mask_to_Add.C'Unchecked_Access, int (Sig)) = 1 then
+            if sigismember (Mask_to_Add.C'Unchecked_Access, int (Sig)) = 1 then
                if not SI.Is_Blocked (SIID (Sig)) then
                   Disposition (Sig) := SI_To_Mask;
                end if;
@@ -602,7 +603,8 @@ package body POSIX.Signals is
             --  It is OK to modify this signal's masking, using the
             --  interfaces of System.Interrupts.
             if sigismember
-              (Mask_to_Subtract.C'Unchecked_Access, int (Sig)) = 1 then
+               (Mask_to_Subtract.C'Unchecked_Access, int (Sig)) = 1
+            then
                if SI.Is_Blocked (SIID (Sig)) then
                   Disposition (Sig) := SI_To_Unmask;
                end if;
@@ -639,7 +641,8 @@ package body POSIX.Signals is
       --  may be more values in POSIX.Signal
       --  than System.Interrupts.Interrupt_ID
       if pthread_sigmask
-        (SIG_BLOCK, null, Old_Mask.C'Unchecked_Access) = 0 then
+         (SIG_BLOCK, null, Old_Mask.C'Unchecked_Access) = 0
+      then
          null;
       end if;
       --  Delete any ublocked signals from System.Interrupts.
@@ -1004,8 +1007,7 @@ package body POSIX.Signals is
       Result   : aliased int;
    begin
       Check_Awaitable (Set);
-      if sigwait
-        (Set.C'Unchecked_Access, Result'Unchecked_Access) = -1 then
+      if sigwait (Set.C'Unchecked_Access, Result'Unchecked_Access) = -1 then
          Raise_POSIX_Error (Fetch_Errno);
       end if;
       return Signal (Result);
@@ -1156,7 +1158,8 @@ begin
 
       if Integer (Sig) <= Integer (SIID'Last) then
          if SI.Is_Reserved (SIID (Sig)) and then (Sig /= SIGKILL
-           and Sig /= SIGSTOP) then
+            and Sig /= SIGSTOP)
+         then
             Reserved_Signal (Sig) := True;
          end if;
       else
