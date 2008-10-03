--- src/devices/bus_pci.c.orig	2008-10-03 14:11:25.000000000 -0700
+++ src/devices/bus_pci.c	2008-10-03 14:11:34.000000000 -0700
@@ -776,6 +776,8 @@
 	void *wdc1 = ((struct piix_ide_extra *)pd->extra)->wdc1;
 	int enabled = 0;
 
+	PCI_SET_DATA(reg, value);
+
 	switch (reg) {
 	case PCI_COMMAND_STATUS_REG:
 		if (value & PCI_COMMAND_IO_ENABLE)
