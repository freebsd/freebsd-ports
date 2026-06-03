--- vendor/core/fastboot/usb_freebsd.cpp	1970-01-01 01:00:00.000000000 +0100
+++ vendor/core/fastboot/usb_freebsd.cpp	2026-03-21 19:36:02.025480000 +0100
@@ -0,0 +1,254 @@
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
+#include <cstring>
+#include <memory>
+#include <thread>
+#include <chrono>
+
+#include <libusb.h>
+
+#include "usb.h"
+
+using namespace std::chrono_literals;
+
+#define MAX_RETRIES 2
+#define MAX_BULK_TRANSFER_SIZE (16 * 1024)
+
+static libusb_context *usb_context = nullptr;
+
+struct usb_handle {
+    libusb_device_handle *devh;
+    uint8_t ep_in;
+    uint8_t ep_out;
+    uint8_t iface;
+};
+
+class FreeBSDUsbTransport : public UsbTransport {
+  public:
+    FreeBSDUsbTransport(std::unique_ptr<usb_handle> handle, uint32_t ms_timeout = 0)
+        : handle_(std::move(handle)), ms_timeout_(ms_timeout) {}
+    ~FreeBSDUsbTransport() override;
+
+    ssize_t Read(void* data, size_t len) override;
+    ssize_t Write(const void* data, size_t len) override;
+    int Close() override;
+    int Reset() override;
+
+  private:
+    std::unique_ptr<usb_handle> handle_;
+    const uint32_t ms_timeout_;
+};
+
+FreeBSDUsbTransport::~FreeBSDUsbTransport() {
+    Close();
+}
+
+ssize_t FreeBSDUsbTransport::Read(void* data, size_t len) {
+    unsigned char *buf = static_cast<unsigned char*>(data);
+    ssize_t total = 0;
+
+    if (!handle_ || !handle_->devh || handle_->ep_in == 0) {
+        return -1;
+    }
+
+    while (len > 0) {
+        int xfer = (len > MAX_BULK_TRANSFER_SIZE) ? MAX_BULK_TRANSFER_SIZE : len;
+        int transferred = 0;
+        int retry = 0;
+        int rc;
+
+        do {
+            rc = libusb_bulk_transfer(handle_->devh, handle_->ep_in,
+                                      buf, xfer, &transferred,
+                                      ms_timeout_ ? ms_timeout_ : 0);
+            if (rc == LIBUSB_ERROR_TIMEOUT) {
+                if (++retry > MAX_RETRIES) return -1;
+                std::this_thread::sleep_for(100ms);
+            } else if (rc != 0) {
+                return -1;
+            }
+        } while (rc != 0);
+
+        total += transferred;
+        len -= transferred;
+        buf += transferred;
+
+        if (transferred < xfer) break;
+    }
+
+    return total;
+}
+
+ssize_t FreeBSDUsbTransport::Write(const void* data, size_t len) {
+    const unsigned char *buf = static_cast<const unsigned char*>(data);
+    ssize_t total = 0;
+
+    if (!handle_ || !handle_->devh || handle_->ep_out == 0) {
+        return -1;
+    }
+
+    while (len > 0) {
+        int xfer = (len > MAX_BULK_TRANSFER_SIZE) ? MAX_BULK_TRANSFER_SIZE : len;
+        int transferred = 0;
+
+        int rc = libusb_bulk_transfer(handle_->devh, handle_->ep_out,
+                                      const_cast<unsigned char*>(buf),
+                                      xfer, &transferred,
+                                      ms_timeout_ ? ms_timeout_ : 0);
+        if (rc != 0) return -1;
+
+        total += transferred;
+        len -= transferred;
+        buf += transferred;
+    }
+
+    return total;
+}
+
+int FreeBSDUsbTransport::Close() {
+    if (handle_ && handle_->devh) {
+        libusb_release_interface(handle_->devh, handle_->iface);
+        libusb_close(handle_->devh);
+        handle_->devh = nullptr;
+    }
+    return 0;
+}
+
+int FreeBSDUsbTransport::Reset() {
+    if (!handle_ || !handle_->devh) return -1;
+    return libusb_reset_device(handle_->devh);
+}
+
+static std::unique_ptr<usb_handle> find_usb_device(ifc_match_func callback) {
+    libusb_device **devs;
+    ssize_t cnt = libusb_get_device_list(usb_context, &devs);
+    if (cnt < 0) return nullptr;
+
+    std::unique_ptr<usb_handle> result;
+
+    for (ssize_t i = 0; i < cnt && !result; i++) {
+        libusb_device *dev = devs[i];
+        struct libusb_device_descriptor desc;
+
+        if (libusb_get_device_descriptor(dev, &desc) != 0) continue;
+
+        struct libusb_config_descriptor *config;
+        if (libusb_get_active_config_descriptor(dev, &config) != 0) {
+            if (libusb_get_config_descriptor(dev, 0, &config) != 0) continue;
+        }
+
+        for (int j = 0; j < config->bNumInterfaces && !result; j++) {
+            const struct libusb_interface *iface = &config->interface[j];
+            for (int k = 0; k < iface->num_altsetting && !result; k++) {
+                const struct libusb_interface_descriptor *altsetting = &iface->altsetting[k];
+
+                usb_ifc_info info = {};
+                info.dev_vendor = desc.idVendor;
+                info.dev_product = desc.idProduct;
+                info.dev_class = desc.bDeviceClass;
+                info.dev_subclass = desc.bDeviceSubClass;
+                info.dev_protocol = desc.bDeviceProtocol;
+                info.ifc_class = altsetting->bInterfaceClass;
+                info.ifc_subclass = altsetting->bInterfaceSubClass;
+                info.ifc_protocol = altsetting->bInterfaceProtocol;
+                info.writable = 1;
+
+                uint8_t ep_in = 0, ep_out = 0;
+                for (int e = 0; e < altsetting->bNumEndpoints; e++) {
+                    const struct libusb_endpoint_descriptor *ep = &altsetting->endpoint[e];
+                    if ((ep->bmAttributes & LIBUSB_TRANSFER_TYPE_MASK) != LIBUSB_TRANSFER_TYPE_BULK)
+                        continue;
+                    if (ep->bEndpointAddress & LIBUSB_ENDPOINT_IN) {
+                        ep_in = ep->bEndpointAddress;
+                    } else {
+                        ep_out = ep->bEndpointAddress;
+                    }
+                }
+
+                info.has_bulk_in = (ep_in != 0);
+                info.has_bulk_out = (ep_out != 0);
+
+                snprintf(info.device_path, sizeof(info.device_path),
+                         "usb:%d:%d", libusb_get_bus_number(dev),
+                         libusb_get_device_address(dev));
+
+                /*
+                 * Open device once, read serial, then decide whether to
+                 * keep it based on callback result.
+                 */
+                libusb_device_handle *devh;
+                int rc = libusb_open(dev, &devh);
+                if (rc != 0) continue;
+
+                /* Detach kernel driver (ugen) before any operations */
+                libusb_set_auto_detach_kernel_driver(devh, 1);
+
+                info.serial_number[0] = '\0';
+                if (desc.iSerialNumber) {
+                    libusb_get_string_descriptor_ascii(
+                        devh, desc.iSerialNumber,
+                        (unsigned char *)info.serial_number,
+                        sizeof(info.serial_number));
+                }
+
+                info.interface[0] = '\0';
+
+                if (callback(&info) == 0) {
+                    rc = libusb_claim_interface(devh, altsetting->bInterfaceNumber);
+                    if (rc != 0) {
+                        libusb_close(devh);
+                        continue;
+                    }
+
+                    result = std::make_unique<usb_handle>();
+                    result->devh = devh;
+                    result->ep_in = ep_in;
+                    result->ep_out = ep_out;
+                    result->iface = altsetting->bInterfaceNumber;
+                } else {
+                    libusb_close(devh);
+                }
+            }
+        }
+        libusb_free_config_descriptor(config);
+    }
+
+    libusb_free_device_list(devs, 1);
+    return result;
+}
+
+std::unique_ptr<UsbTransport> usb_open(ifc_match_func callback, uint32_t timeout_ms) {
+    if (!usb_context) {
+        if (libusb_init(&usb_context) != 0) return nullptr;
+    }
+
+    auto handle = find_usb_device(callback);
+    if (!handle) return nullptr;
+
+    return std::make_unique<FreeBSDUsbTransport>(std::move(handle), timeout_ms);
+}
