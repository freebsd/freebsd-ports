--- src/VBox/VMM/VMMR3/CPUM.cpp	(Revision 71439)
+++ src/VBox/VMM/VMMR3/CPUM.cpp	(Revision 71440)
@@ -999,7 +999,8 @@
      */
     if (!fHWVirtExEnabled)
     {
-        Assert(pVM->cpum.s.aGuestCpuIdStd[4].eax == 0);
+        Assert(   pVM->cpum.s.aGuestCpuIdStd[4].eax == 0
+               || pVM->cpum.s.aGuestCpuIdStd[0].eax < 0x4);
         pVM->cpum.s.aGuestCpuIdStd[4].eax = 0;
     }
 }
