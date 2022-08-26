--- pvmnet/if_pvmnet.c.orig	2014-02-14 14:09:06 UTC
+++ pvmnet/if_pvmnet.c
@@ -245,20 +245,21 @@ static driver_t pvmnet_driver = {
 	sizeof(struct pvmnet_softc)
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(pvmnet, pci, pvmnet_driver, 0, 0);
+#else
 static devclass_t pvmnet_devclass;
 
 DRIVER_MODULE(pvmnet, pci, pvmnet_driver, pvmnet_devclass, 0, 0);
+#endif
 
 static int
 pvmnet_probe(device_t dev)
 {
 	uint16_t devid, vendor;
-	uint16_t revid, sdevid;
 
 	vendor = pci_get_vendor(dev);
 	devid = pci_get_device(dev);
-	revid = pci_get_revid(dev);
-	sdevid = pci_get_subdevice(dev);
 
 	if (vendor != 0x10ec || devid != 0x8029)
 		return (ENXIO);
@@ -364,12 +365,20 @@ pvmnetintr(void *arg)
 		for (offset = io_get_rcv_offset(sc);
 		    (size = io_get_packet_size(sc, offset)); offset += FULL_PACKET_SIZE(size)) {
 			if (size > ETHER_MAX_LEN) {
+#if __FreeBSD_version >= 1100036
+				if_inc_counter(ifp, IFCOUNTER_IERRORS, 1);
+#else
 				ifp->if_ierrors++;
+#endif
 				continue;
 			}
 			m = m_getcl(M_NOWAIT, MT_DATA, M_PKTHDR);
 			if (m == NULL) {
+#if __FreeBSD_version >= 1100036
+				if_inc_counter(ifp, IFCOUNTER_IERRORS, 1);
+#else
 				ifp->if_ierrors++;
+#endif
 				continue;
 			}
 			m->m_pkthdr.rcvif = ifp;
@@ -379,7 +388,11 @@ pvmnetintr(void *arg)
 			m->m_pkthdr.len = m->m_len = size;
 			io_read_data(sc, offset, m);
 
+#if __FreeBSD_version >= 1100036
+			if_inc_counter(ifp, IFCOUNTER_IPACKETS, 1);
+#else
 			ifp->if_ipackets++;
+#endif
 
 			PVMNET_UNLOCK(sc);
 			(*ifp->if_input)(ifp, m);
@@ -427,8 +440,8 @@ static int pvmnet_alloc_resources(device_t dev)
 
 	error = bus_setup_intr(dev, sc->irq_res, INTR_TYPE_NET | INTR_MPSAFE,
 		NULL, pvmnetintr, sc, &sc->irq_handle);
-	if (!res)
-		return ENXIO;
+	if (error)
+		return error;
 	return (0);
 }
 
@@ -538,7 +551,11 @@ pvmnet_start_locked(struct ifnet *ifp)
 			io_notify_sndbuf_full(sc);
 			break;
 		}
+#if __FreeBSD_version >= 1100036
+		if_inc_counter(ifp, IFCOUNTER_OPACKETS, 1);
+#else
 		ifp->if_opackets++;
+#endif
 		BPF_MTAP(ifp, m);
 		m_freem(m);
 	}
