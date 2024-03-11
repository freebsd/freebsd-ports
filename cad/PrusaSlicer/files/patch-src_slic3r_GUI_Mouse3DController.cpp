--- src/slic3r/GUI/Mouse3DController.cpp.orig	2023-12-12 14:21:21 UTC
+++ src/slic3r/GUI/Mouse3DController.cpp
@@ -890,7 +890,7 @@ bool Mouse3DController::connect_device()
 
     for (const DetectedDevices::value_type& device : detected_devices) {
         if (device.second.size() == 1) {
-#if defined(__linux__)
+#if defined(__linux__) || defined(__FreeBSD__) 
             hid_device* test_device = hid_open(device.first.first, device.first.second, nullptr);
             if (test_device == nullptr) {
                 BOOST_LOG_TRIVIAL(error) << "3DConnexion device cannot be opened: " << device.second.front().path <<
@@ -915,7 +915,7 @@ bool Mouse3DController::connect_device()
                 std::cout << "Test device: " << std::hex << device.first.first << std::dec << "/" << std::hex << device.first.second << std::dec << " \"" << data.path << "\"";
 #endif // ENABLE_3DCONNEXION_DEVICES_DEBUG_OUTPUT
 
-#ifdef __linux__
+#if defined(__linux__) || defined(__FreeBSD__)
                 hid_device* test_device = hid_open_path(data.path.c_str());
                 if (test_device != nullptr) {
                     path = data.path;
