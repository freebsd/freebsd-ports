--- kernel/drv/oss_hdaudio/.devices	Wed Jul 20 03:52:16 2011 +0300
+++ kernel/drv/oss_hdaudio/.devices	Tue Feb 07 05:25:23 2012 +0200
@@ -2,13 +2,15 @@
 oss_hdaudio	pci8086,27d8	Intel High Definition Audio (ICH7)
 oss_hdaudio	pci8086,269a	Intel High Definition Audio (ESB2)
 oss_hdaudio	pci8086,284b	Intel High Definition Audio (ICH8)
-oss_hdaudio	pci8086,293e	Intel High Definition Audio (P35)
-oss_hdaudio	pci8086,293f	Intel High Definition Audio (ICH9)
+oss_hdaudio	pci8086,293e	Intel High Definition Audio (ICH9)
+oss_hdaudio	pci8086,293f	Intel High Definition Audio (ICH9_B)
 oss_hdaudio	pci8086,3a3e	Intel High Definition Audio (ICH10)
-oss_hdaudio	pci8086,3a6e	Intel High Definition Audio (ICH10)
+oss_hdaudio	pci8086,3a6e	Intel High Definition Audio (ICH10_B)
 oss_hdaudio	pci8086,3b56	Intel High Definition Audio (PCH)
-oss_hdaudio	pci8086,3b57    Intel High Definition Audio (PCH)
+oss_hdaudio	pci8086,3b57    Intel High Definition Audio (PCH_B)
 oss_hdaudio	pci8086,1c20	Intel High Definition Audio (CPT)
+oss_hdaudio	pci8086,1d20	Intel High Definition Audio (PBG)
+oss_hdaudio	pci8086,1e20	Intel High Definition Audio (PPT)
 oss_hdaudio	pci8086,811b    Intel High Definition Audio (SCH)
 oss_hdaudio	pci10de,26c	Nvidia High Definition Audio (MCP51)
 oss_hdaudio	pci10de,371	Nvidia High Definition Audio (MCP55)
@@ -21,6 +23,7 @@
 oss_hdaudio	pci10de,ac0	Nvidia High Definition Audio (MCP79)
 oss_hdaudio	pci1002,437b	ATI High Definition Audio (SB450)
 oss_hdaudio	pci1002,4383	ATI High Definition Audio (SB600)
+oss_hdaudio	pci1022,780d	AMD High Definition Audio (Hudson)
 oss_hdaudio	pci1106,3288	VIA High Definition Audio
 oss_hdaudio	pci1039,7502	SiS High Definition Audio
 oss_hdaudio	pci10b9,5461	ULI High Definition Audio
--- kernel/drv/oss_hdaudio/oss_hdaudio.c	Sat Jan 28 17:37:44 2012 +0200
+++ kernel/drv/oss_hdaudio/oss_hdaudio.c	Tue Feb 07 05:25:23 2012 +0200
@@ -27,14 +27,16 @@
 #define INTEL_DEVICE_ICH7       0x27d8
 #define INTEL_DEVICE_ESB2       0x269a
 #define INTEL_DEVICE_ICH8       0x284b
-#define INTEL_DEVICE_ICH9       0x293f
-#define INTEL_DEVICE_ICH10		0x3a3e
-#define INTEL_DEVICE_ICH10_B	0x3a6e
-#define INTEL_DEVICE_CPT	0x1c20
-#define INTEL_DEVICE_PCH		0x3b56
-#define INTEL_DEVICE_PCH2		0x3b57
-#define INTEL_DEVICE_SCH		0x811b
-#define INTEL_DEVICE_P35        0x293e
+#define INTEL_DEVICE_ICH9       0x293e
+#define INTEL_DEVICE_ICH9_B     0x293f
+#define INTEL_DEVICE_ICH10      0x3a3e
+#define INTEL_DEVICE_ICH10_B    0x3a6e
+#define INTEL_DEVICE_PCH        0x3b56
+#define INTEL_DEVICE_PCH_B      0x3b57
+#define INTEL_DEVICE_CPT        0x1c20
+#define INTEL_DEVICE_PBG        0x1d20
+#define INTEL_DEVICE_PPT        0x1e20
+#define INTEL_DEVICE_SCH        0x811b
 
 #define NVIDIA_VENDOR_ID        0x10de
 #define NVIDIA_DEVICE_MCP51     0x026c
@@ -51,6 +53,9 @@
 #define ATI_DEVICE_SB450        0x437b
 #define ATI_DEVICE_SB600        0x4383
 
+#define AMD_VENDOR_ID           0x1022
+#define AMD_DEVICE_HUDSON       0x780d
+
 #define VIA_VENDOR_ID           0x1106
 #define VIA_DEVICE_HDA          0x3288
 
@@ -1769,33 +1774,6 @@
   pci_read_config_word (osdev, PCI_VENDOR_ID, &vendor);
   pci_read_config_word (osdev, PCI_DEVICE_ID, &device);
 
-#if 0
-  // This check is not necessary because the kernel has already checked
-  // the vendor&device ID
-
-  if ((vendor != INTEL_VENDOR_ID && vendor != NVIDIA_VENDOR_ID &&
-       vendor != ATI_VENDOR_ID && vendor != SIS_VENDOR_ID &&
-       vendor != VIA_VENDOR_ID && vendor != ULI_VENDOR_ID) ||
-      (device != INTEL_DEVICE_ICH6 && device != INTEL_DEVICE_ICH7 &&
-       device != INTEL_DEVICE_ESB2 && device != INTEL_DEVICE_ICH8 &&
-       device != INTEL_DEVICE_ICH9 && device != INTEL_DEVICE_P35 &&
-       device != INTEL_DEVICE_ICH10 && device != INTEL_DEVICE_ICH10_B &&
-       device != INTEL_DEVICE_PCH &&
-       device != NVIDIA_DEVICE_MCP51 && device != NVIDIA_DEVICE_MCP55 &&
-       device != NVIDIA_DEVICE_MCP61 && device != NVIDIA_DEVICE_MCP61A &&
-       device != NVIDIA_DEVICE_MCP65 && device != NVIDIA_DEVICE_MCP67 &&
-       device != NVIDIA_DEVICE_MCP73 && device != NVIDIA_DEVICE_MCP78S &&
-       device != NVIDIA_DEVICE_MCP79 &&
-       device != VIA_DEVICE_HDA &&
-       device != SIS_DEVICE_HDA &&
-       device != ULI_DEVICE_HDA &&
-       device != ATI_DEVICE_SB450 && device != ATI_DEVICE_SB600))
-
-    {
-      return 0;
-    }
-#endif
-
   pci_read_config_byte (osdev, PCI_REVISION_ID, &pci_revision);
   pci_read_config_word (osdev, PCI_COMMAND, &pci_command);
   pci_read_config_irq (osdev, PCI_INTERRUPT_LINE, &pci_irq_line);
@@ -1822,6 +1800,9 @@
 
   switch (device)
     {
+    case INTEL_DEVICE_CPT:
+    case INTEL_DEVICE_PBG:
+    case INTEL_DEVICE_PPT:
     case INTEL_DEVICE_SCH:
   	  pci_read_config_word (osdev, 0x78, &devctl);
  	  DDB (cmn_err (CE_CONT, " DEVC register content  0x%04x\n", devctl);)
@@ -1834,12 +1815,11 @@
     case INTEL_DEVICE_ESB2:
     case INTEL_DEVICE_ICH8:
     case INTEL_DEVICE_ICH9:
-    case INTEL_DEVICE_P35:
+    case INTEL_DEVICE_ICH9_B:
     case INTEL_DEVICE_ICH10:
     case INTEL_DEVICE_ICH10_B:
     case INTEL_DEVICE_PCH:
-    case INTEL_DEVICE_PCH2:
-    case INTEL_DEVICE_CPT:
+    case INTEL_DEVICE_PCH_B:
       devc->chip_name = "Intel HD Audio";
       break;
 
@@ -1868,6 +1848,10 @@
       pci_write_config_byte (osdev, 0x42, (btmp & 0xf8) | 0x2);
       break;
 
+    case AMD_DEVICE_HUDSON:
+	devc->chip_name = "AMD HD Audio";
+	break;
+
     case VIA_DEVICE_HDA:
       devc->chip_name = "VIA HD Audio";
       break;
@@ -1888,7 +1872,7 @@
       break;
 
     default:
-      devc->chip_name = "High definition audio device";
+      devc->chip_name = "Azalia High Definition audio device";
     }
 
   pci_read_config_dword (osdev, PCI_MEM_BASE_ADDRESS_0, &devc->membar_addr);
