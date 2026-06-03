The LIBUSB_SPEED_SUPER_PLUS emum was added in libusb 1.0.24 (December
10, 2020). Support for the LIBUSB_SPEED_SUPER_PLUS enum was much more
recently added to our implementation in [1].

[1] https://cgit.freebsd.org/src/commit/?id=f938c0a90313125a9518307e80ca92d4c71f7745

--- src/usb.c.orig	2025-02-01 20:07:39 UTC
+++ src/usb.c
@@ -625,9 +625,11 @@ static void device_complete_initialization(struct mode
 		case LIBUSB_SPEED_SUPER:
 			usbdev->speed = 5000000000;
 			break;
+#if defined(__FreeBSD__) && __FreeBSD_version >= 1500044
 		case LIBUSB_SPEED_SUPER_PLUS:
 			usbdev->speed = 10000000000;
 			break;
+#endif
 		case LIBUSB_SPEED_HIGH:
 		case LIBUSB_SPEED_UNKNOWN:
 		default:
