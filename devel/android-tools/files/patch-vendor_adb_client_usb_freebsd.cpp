--- vendor/adb/client/usb_freebsd.cpp	1970-01-01 01:00:00.000000000 +0100
+++ vendor/adb/client/usb_freebsd.cpp	2026-03-21 19:23:46.144092000 +0100
@@ -0,0 +1,63 @@
+/*
+ * Copyright (C) 2026 Baptiste Daroussin <bapt@FreeBSD.org>
+ *
+ * Redistribution and use in source and binary forms, with or without
+ * modification, are permitted provided that the following conditions
+ * are met:
+ *  * Redistributions of source code must retain the above copyright
+ *    notice, this list of conditions and the following disclaimer.
+ *  * Redistributions in binary form must reproduce the above copyright
+ *    notice, this list of conditions and the following disclaimer in
+ *    the documentation and/or other materials provided with the
+ *    distribution.
+ *
+ * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
+ * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
+ * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
+ * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
+ * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
+ * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
+ * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
+ * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
+ * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
+ * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
+ * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
+ * SUCH DAMAGE.
+ */
+
+/*
+ * On FreeBSD, the libusb backend (usb_libusb.cpp) is always used for USB
+ * device communication via LibusbConnection. These stub implementations of
+ * the native USB interface satisfy the linker for UsbConnection, which is
+ * only used on Linux and macOS.
+ */
+
+#include "client/usb.h"
+
+void usb_init() {
+}
+
+void usb_cleanup() {
+}
+
+int usb_write(usb_handle*, const void*, int) {
+    return -1;
+}
+
+int usb_read(usb_handle*, void*, int) {
+    return -1;
+}
+
+int usb_close(usb_handle*) {
+    return -1;
+}
+
+void usb_reset(usb_handle*) {
+}
+
+void usb_kick(usb_handle*) {
+}
+
+size_t usb_get_max_packet_size(usb_handle*) {
+    return 0;
+}
