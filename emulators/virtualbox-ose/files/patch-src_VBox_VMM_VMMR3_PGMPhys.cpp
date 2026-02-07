--- src/VBox/VMM/VMMR3/PGMPhys.cpp.orig	2022-01-13 18:58:38 UTC
+++ src/VBox/VMM/VMMR3/PGMPhys.cpp
@@ -3179,7 +3179,7 @@ VMMR3_INT_DECL(int) PGMR3PhysMmio2Register(PVM pVM, PP
             else
 #endif
             {
-#ifndef VBOX_WITH_LINEAR_HOST_PHYS_MEM
+#if defined(VBOX_WITH_RAM_IN_KERNEL) && !defined(VBOX_WITH_LINEAR_HOST_PHYS_MEM)
                 rc = SUPR3PageAllocEx(cPages, 0 /*fFlags*/, &pvPages, &pvPagesR0, paPages);
 #else
                 rc = SUPR3PageAllocEx(cPages, 0 /*fFlags*/, &pvPages, NULL /*pR0Ptr*/, paPages);
