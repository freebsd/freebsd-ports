Fix ich9 bios to correctly configure pci bridge1 and pci bridge2

avg: I think that it is a valid report, the patch is not perfect, but
avg: it fixes the problem for most configurations and demonstrates the problem well
avg: the explanation for them is that FreeBSD (unlike Linux and maybe other OSes)
avg: entirely relies on platform doing correct bus numbering
avg: currently we can not do any re-numbering/corrections

See:		http://article.gmane.org/gmane.os.freebsd.devel.emulation/10438
Submitted by:	Gustau Perez i Querol <gperez@entel.upc.edu>
--- src/VBox/Devices/Bus/DevPciIch9.cpp.orig	2012-06-15 21:22:15.000000000 +0200
+++ src/VBox/Devices/Bus/DevPciIch9.cpp	2012-09-02 14:17:49.804118887 +0200
@@ -1812,7 +1812,8 @@
         PICH9PCIBUS pChildBus = PDMINS_2_DATA(pBridge->pDevIns, PICH9PCIBUS);
         ich9pciInitBridgeTopology(pGlobals, pChildBus);
     }
-    PCIDevSetByte(pBridgeDev, VBOX_PCI_SUBORDINATE_BUS, pGlobals->uBus);
+    PCIDevSetByte(pBridgeDev, VBOX_PCI_PRIMARY_BUS, 0);
+    PCIDevSetByte(pBridgeDev, VBOX_PCI_SUBORDINATE_BUS, (pGlobals->uBus)-1);
     Log2(("ich9pciInitBridgeTopology: for bus %p: primary=%d secondary=%d subordinate=%d\n",
           pBus,
           PCIDevGetByte(pBridgeDev, VBOX_PCI_PRIMARY_BUS),
