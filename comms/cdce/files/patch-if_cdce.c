
$FreeBSD$

--- if_cdce.c
+++ if_cdce.c
@@ -158,11 +158,12 @@
     usb_interface_descriptor_t *id;
     usb_endpoint_descriptor_t *ed;
     usb_cdc_union_descriptor_t *ud;
+    usb_config_descriptor_t *cd;
     struct ifnet *ifp;
     int data_ifcno;
     u_int16_t macaddr_hi;
     char devinfo[1024];
-    int i;
+    int i, j, numalts;
 
     bzero(sc, sizeof(struct cdce_softc));
     sc->cdce_udev = uaa->device;
@@ -206,29 +207,52 @@
 	USB_ATTACH_ERROR_RETURN;
     }
     
-    /* Find endpoints. */
+    /*
+     * In the case of my CDCEthernet modem, there are several alternate
+     * interface possibilities -- the default first one does not work
+     * (though in the original code it probably worked for those devices
+     * which were supported), and in my case, the next alternate setting
+     * gives me the desired interface.  There's another one that also
+     * does not work, so we loop through the possibilities and take the
+     * first one that works.
+     */
     id = usbd_get_interface_descriptor(sc->cdce_data_iface);
-    sc->cdce_bulkin_no = sc->cdce_bulkout_no = -1;
-    for (i = 0; i < id->bNumEndpoints; i++) {
-	ed = usbd_interface2endpoint_descriptor(sc->cdce_data_iface, i);
-	if (!ed) {
-	    printf("%s: could not read endpoint descriptor\n",
-		   sc->cdce_name);
-	    USB_ATTACH_ERROR_RETURN;
-	}
-	if (UE_GET_DIR(ed->bEndpointAddress) == UE_DIR_IN &&
-		UE_GET_XFERTYPE(ed->bmAttributes) == UE_BULK) {
-	    sc->cdce_bulkin_no = ed->bEndpointAddress;
-	} else if (UE_GET_DIR(ed->bEndpointAddress) == UE_DIR_OUT &&
-		UE_GET_XFERTYPE(ed->bmAttributes) == UE_BULK) {
-	    sc->cdce_bulkout_no = ed->bEndpointAddress;
-	} else if (UE_GET_DIR(ed->bEndpointAddress) == UE_DIR_IN &&
-		UE_GET_XFERTYPE(ed->bmAttributes) == UE_INTERRUPT) {
-	    /* XXX: CDC spec defines an interrupt pipe, but it is not
-	     * needed for simple host-to-host applications. */
-	} else {
-	    printf("%s: unexpected endpoint\n", sc->cdce_name);
-	}
+    cd = usbd_get_config_descriptor(sc->cdce_udev);
+    numalts = usbd_get_no_alts(cd, id->bInterfaceNumber);
+
+    for (j = 0; j < numalts; j++) {
+        if (usbd_set_interface(sc->cdce_data_iface, j)) {
+            printf("%s: setting alternate interface failed\n",
+                sc->cdce_name);
+            USB_ATTACH_ERROR_RETURN;
+        }
+        /* Find endpoints. */
+        id = usbd_get_interface_descriptor(sc->cdce_data_iface);
+        sc->cdce_bulkin_no = sc->cdce_bulkout_no = -1;
+        for (i = 0; i < id->bNumEndpoints; i++) {
+	    ed = usbd_interface2endpoint_descriptor(sc->cdce_data_iface, i);
+	    if (!ed) {
+	        printf("%s: could not read endpoint descriptor\n",
+		       sc->cdce_name);
+	        USB_ATTACH_ERROR_RETURN;
+	    }
+	    if (UE_GET_DIR(ed->bEndpointAddress) == UE_DIR_IN &&
+		    UE_GET_XFERTYPE(ed->bmAttributes) == UE_BULK) {
+	        sc->cdce_bulkin_no = ed->bEndpointAddress;
+	    } else if (UE_GET_DIR(ed->bEndpointAddress) == UE_DIR_OUT &&
+		    UE_GET_XFERTYPE(ed->bmAttributes) == UE_BULK) {
+	        sc->cdce_bulkout_no = ed->bEndpointAddress;
+	    } else if (UE_GET_DIR(ed->bEndpointAddress) == UE_DIR_IN &&
+		    UE_GET_XFERTYPE(ed->bmAttributes) == UE_INTERRUPT) {
+	        /* XXX: CDC spec defines an interrupt pipe, but it is not
+	         * needed for simple host-to-host applications. */
+	    } else {
+	        printf("%s: unexpected endpoint\n", sc->cdce_name);
+	    }
+        }
+        /* If we found something, try and use it... */
+        if ((sc->cdce_bulkin_no != -1) && (sc->cdce_bulkout_no != -1))
+            break;
     }
 
     if (sc->cdce_bulkin_no == -1) {
