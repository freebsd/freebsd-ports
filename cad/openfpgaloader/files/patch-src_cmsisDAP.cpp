-- Skip libusb_dev_mem_alloc(): the FreeBSD libusb takes a single argument and
-- does not implement DMA memory allocation. The allocated memory is not used
-- by the code anyway.

--- src/cmsisDAP.cpp.orig	2026-11-09 00:30:34 UTC
+++ src/cmsisDAP.cpp
@@ -496,12 +496,14 @@ bool CmsisDAP::initWithBulk(const cable_t &cable, int8
 	_ep_out = dev.ep_out;
 	_ep_in = dev.ep_in;
 
+#ifndef __FreeBSD__
 	if (!libusb_dev_mem_alloc(_usb_dev, _pkt_sz)) {
 		libusb_close(_usb_dev);
 		libusb_exit(_ctx);
 		disp_error_info("cmsisDAP: failed to alloc DMA memory for device", err_as_info);
 		return false;
 	}
+#endif
 
 	return true;
 }
