From: aurelien@aurel32.net (Aurelien Jarno)
Subject: [Qemu-devel] [PATCH] pcnet-pci: mark I/O and MMIO as LITTLE_ENDIAN
Date: Wed, 28 Aug 2013 14:17:39 +0200
Message-ID: <1377692259-19959-1-git-send-email-aurelien@aurel32.net>
To: qemu-devel@nongnu.org
Cc: Paolo Bonzini <pbonzini@redhat.com>, qemu-stable@nongnu.org,
        Aurelien Jarno <aurelien@aurel32.net>

Now that the memory subsystem is propagating the endianness correctly,
the pcnet-pci device should have its I/O ports and MMIO memory marked
as LITTLE_ENDIAN, as PCI devices are little endian.

This makes the pcnet-pci NIC to work again on big endian MIPS Malta
(default NIC).

Cc: qemu-stable@nongnu.org
Signed-off-by: Aurelien Jarno <aurelien@aurel32.net>
---
 hw/net/pcnet-pci.c |    4 ++--
 1 file changed, 2 insertions(+), 2 deletions(-)

diff --git a/hw/net/pcnet-pci.c b/hw/net/pcnet-pci.c
index a893165..865f2f0 100644
--- a/hw/net/pcnet-pci.c
+++ b/hw/net/pcnet-pci.c
@@ -134,7 +134,7 @@ static void pcnet_ioport_write(void *opaque, hwaddr addr,
 static const MemoryRegionOps pcnet_io_ops = {
     .read = pcnet_ioport_read,
     .write = pcnet_ioport_write,
-    .endianness = DEVICE_NATIVE_ENDIAN,
+    .endianness = DEVICE_LITTLE_ENDIAN,
 };
 
 static void pcnet_mmio_writeb(void *opaque, hwaddr addr, uint32_t val)
@@ -256,7 +256,7 @@ static const MemoryRegionOps pcnet_mmio_ops = {
         .read = { pcnet_mmio_readb, pcnet_mmio_readw, pcnet_mmio_readl },
         .write = { pcnet_mmio_writeb, pcnet_mmio_writew, pcnet_mmio_writel },
     },
-    .endianness = DEVICE_NATIVE_ENDIAN,
+    .endianness = DEVICE_LITTLE_ENDIAN,
 };
 
 static void pci_physical_memory_write(void *dma_opaque, hwaddr addr,
-- 
1.7.10.4



