--- src/slic3r/GUI/Mouse3DController.cpp.orig	2021-07-16 10:14:03 UTC
+++ src/slic3r/GUI/Mouse3DController.cpp
@@ -66,7 +66,7 @@ void update_maximum(std::atomic<T>& maximum_value, T c
 
 void Mouse3DController::State::append_translation(const Vec3d& translation, size_t input_queue_max_size)
 {
-	tbb::mutex::scoped_lock lock(m_input_queue_mutex);
+    std::scoped_lock<std::mutex> lock(m_input_queue_mutex);
     while (m_input_queue.size() >= input_queue_max_size)
         m_input_queue.pop_front();
     m_input_queue.emplace_back(QueueItem::translation(translation));
@@ -77,7 +77,7 @@ void Mouse3DController::State::append_translation(cons
 
 void Mouse3DController::State::append_rotation(const Vec3f& rotation, size_t input_queue_max_size)
 {
-	tbb::mutex::scoped_lock lock(m_input_queue_mutex);
+    std::scoped_lock<std::mutex> lock(m_input_queue_mutex);
     while (m_input_queue.size() >= input_queue_max_size)
         m_input_queue.pop_front();
     m_input_queue.emplace_back(QueueItem::rotation(rotation.cast<double>()));
@@ -92,7 +92,7 @@ void Mouse3DController::State::append_rotation(const V
 
 void Mouse3DController::State::append_button(unsigned int id, size_t /* input_queue_max_size */)
 {
-	tbb::mutex::scoped_lock lock(m_input_queue_mutex);
+    std::scoped_lock<std::mutex> lock(m_input_queue_mutex);
     m_input_queue.emplace_back(QueueItem::buttons(id));
 #if ENABLE_3DCONNEXION_DEVICES_DEBUG_OUTPUT
     update_maximum(input_queue_max_size_achieved, m_input_queue.size());
@@ -277,7 +277,7 @@ void Mouse3DController::device_attached(const std::str
 #if ENABLE_CTRL_M_ON_WINDOWS
             m_device_str = format_device_string(vid, pid);
             if (auto it_params = m_params_by_device.find(m_device_str); it_params != m_params_by_device.end()) {
-                tbb::mutex::scoped_lock lock(m_params_ui_mutex);
+                std::scoped_lock<std::mutex> lock(m_params_ui_mutex);
                 m_params = m_params_ui = it_params->second;
             }
             else
@@ -295,7 +295,7 @@ void Mouse3DController::device_detached(const std::str
     int pid = 0;
     if (sscanf(device.c_str(), "\\\\?\\HID#VID_%x&PID_%x&", &vid, &pid) == 2) {
         if (std::find(_3DCONNEXION_VENDORS.begin(), _3DCONNEXION_VENDORS.end(), vid) != _3DCONNEXION_VENDORS.end()) {
-            tbb::mutex::scoped_lock lock(m_params_ui_mutex);
+            std::scoped_lock<std::mutex> lock(m_params_ui_mutex);
             m_params_by_device[format_device_string(vid, pid)] = m_params_ui;
         }
     }
@@ -307,12 +307,12 @@ void Mouse3DController::device_detached(const std::str
 // Filter out mouse scroll events produced by the 3DConnexion driver.
 bool Mouse3DController::State::process_mouse_wheel()
 {
-	tbb::mutex::scoped_lock lock(m_input_queue_mutex);
-	if (m_mouse_wheel_counter == 0)
-    	// No 3DConnexion rotation has been captured since the last mouse scroll event.
+    std::scoped_lock<std::mutex> lock(m_input_queue_mutex);
+    if (m_mouse_wheel_counter == 0)
+        // No 3DConnexion rotation has been captured since the last mouse scroll event.
         return false;
     if (std::find_if(m_input_queue.begin(), m_input_queue.end(), [](const QueueItem &item){ return item.is_rotation(); }) != m_input_queue.end()) {
-    	// There is a rotation stored in the queue. Suppress one mouse scroll event.
+        // There is a rotation stored in the queue. Suppress one mouse scroll event.
         -- m_mouse_wheel_counter;
         return true;
     }
@@ -329,7 +329,7 @@ bool Mouse3DController::State::apply(const Mouse3DCont
     std::deque<QueueItem> input_queue;
     {
     	// Atomically move m_input_queue to input_queue.
-    	tbb::mutex::scoped_lock lock(m_input_queue_mutex);
+    	std::scoped_lock<std::mutex> lock(m_input_queue_mutex);
     	input_queue = std::move(m_input_queue);
         m_input_queue.clear();
     }
@@ -418,7 +418,7 @@ bool Mouse3DController::apply(Camera& camera)
 #if ENABLE_CTRL_M_ON_WINDOWS
 #ifdef _WIN32
     {
-        tbb::mutex::scoped_lock lock(m_params_ui_mutex);
+        std::scoped_lock<std::mutex> lock(m_params_ui_mutex);
         if (m_params_ui_changed) {
             m_params = m_params_ui;
             m_params_ui_changed = false;
@@ -447,7 +447,7 @@ void Mouse3DController::render_settings_dialog(GLCanva
     Params params_copy;
     bool   params_changed = false;
     {
-    	tbb::mutex::scoped_lock lock(m_params_ui_mutex);
+    	std::scoped_lock<std::mutex> lock(m_params_ui_mutex);
     	params_copy = m_params_ui;
     }
 
@@ -565,7 +565,7 @@ void Mouse3DController::render_settings_dialog(GLCanva
 
     if (params_changed) {
         // Synchronize front end parameters to back end.
-    	tbb::mutex::scoped_lock lock(m_params_ui_mutex);
+    	std::scoped_lock<std::mutex> lock(m_params_ui_mutex);
         auto pthis = const_cast<Mouse3DController*>(this);
 #if ENABLE_3DCONNEXION_DEVICES_DEBUG_OUTPUT
         if (params_copy.input_queue_max_size != params_copy.input_queue_max_size)
@@ -586,7 +586,7 @@ void Mouse3DController::connected(std::string device_n
 	m_device_str = device_name;
     // Copy the parameters for m_device_str into the current parameters.
     if (auto it_params = m_params_by_device.find(m_device_str); it_params != m_params_by_device.end()) {
-    	tbb::mutex::scoped_lock lock(m_params_ui_mutex);
+    	std::scoped_lock<std::mutex> lock(m_params_ui_mutex);
     	m_params = m_params_ui = it_params->second;
     }
     m_connected = true;
@@ -597,7 +597,7 @@ void Mouse3DController::disconnected()
     // Copy the current parameters for m_device_str into the parameter database.
     assert(m_connected == ! m_device_str.empty());
     if (m_connected) {
-        tbb::mutex::scoped_lock lock(m_params_ui_mutex);
+        std::scoped_lock<std::mutex> lock(m_params_ui_mutex);
         m_params_by_device[m_device_str] = m_params_ui;
 	    m_device_str.clear();
 	    m_connected = false;
@@ -621,7 +621,7 @@ bool Mouse3DController::handle_input(const DataPacketA
     {
     	// Synchronize parameters between the UI thread and the background thread.
     	//FIXME is this necessary on OSX? Are these notifications triggered from the main thread or from a worker thread?
-    	tbb::mutex::scoped_lock lock(m_params_ui_mutex);
+    	std::scoped_lock<std::mutex> lock(m_params_ui_mutex);
     	if (m_params_ui_changed) {
     		m_params = m_params_ui;
     		m_params_ui_changed = false;
@@ -733,7 +733,7 @@ void Mouse3DController::run()
 
     for (;;) {
         {
-        	tbb::mutex::scoped_lock lock(m_params_ui_mutex);
+        	std::scoped_lock<std::mutex> lock(m_params_ui_mutex);
         	if (m_stop)
         		break;
         	if (m_params_ui_changed) {
@@ -998,7 +998,7 @@ bool Mouse3DController::connect_device()
 #endif // ENABLE_3DCONNEXION_DEVICES_DEBUG_OUTPUT
         // Copy the parameters for m_device_str into the current parameters.
         if (auto it_params = m_params_by_device.find(m_device_str); it_params != m_params_by_device.end()) {
-	    	tbb::mutex::scoped_lock lock(m_params_ui_mutex);
+	    	std::scoped_lock<std::mutex> lock(m_params_ui_mutex);
 	    	m_params = m_params_ui = it_params->second;
 	    }
     }
@@ -1023,7 +1023,7 @@ void Mouse3DController::disconnect_device()
 	    BOOST_LOG_TRIVIAL(info) << "Disconnected device: " << m_device_str;
         // Copy the current parameters for m_device_str into the parameter database.
         {
-	        tbb::mutex::scoped_lock lock(m_params_ui_mutex);
+	        std::scoped_lock<std::mutex> lock(m_params_ui_mutex);
 	        m_params_by_device[m_device_str] = m_params_ui;
 	    }
 	    m_device_str.clear();
