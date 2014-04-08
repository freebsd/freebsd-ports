--- src/VBox/Devices/Graphics/HGSMI/HGSMIHost.cpp.orig	2014-03-26 15:17:10.000000000 -0400
+++ src/VBox/Devices/Graphics/HGSMI/HGSMIHost.cpp	2014-04-02 16:26:50.000000000 -0400
@@ -1185,6 +1185,8 @@
     return rc;
 }
 
+#ifdef VBOX_WITH_WDDM
+
 static int hgsmiHostSaveGuestCmdCompletedFifoEntryLocked (HGSMIGUESTCOMPLENTRY *pEntry, PSSMHANDLE pSSM)
 {
     return SSMR3PutU32 (pSSM, pEntry->offBuffer);
@@ -1211,6 +1213,8 @@
     return rc;
 }
 
+#endif
+
 static int hgsmiHostLoadFifoEntryLocked (PHGSMIINSTANCE pIns, HGSMIHOSTFIFOENTRY **ppEntry, PSSMHANDLE pSSM)
 {
     HGSMIHOSTFIFOENTRY *pEntry;
@@ -1253,6 +1257,8 @@
     return rc;
 }
 
+#ifdef VBOX_WITH_WDDM
+
 static int hgsmiHostLoadGuestCmdCompletedFifoEntryLocked (PHGSMIINSTANCE pIns, HGSMIGUESTCOMPLENTRY **ppEntry, PSSMHANDLE pSSM)
 {
     HGSMIGUESTCOMPLENTRY *pEntry;
@@ -1306,6 +1312,8 @@
     return rc;
 }
 
+#endif
+
 int HGSMIHostSaveStateExec (PHGSMIINSTANCE pIns, PSSMHANDLE pSSM)
 {
     VBOXHGSMI_SAVE_START(pSSM);
