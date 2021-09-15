--- src/slic3r/GUI/RemovableDriveManager.cpp.orig	2021-07-16 10:14:03 UTC
+++ src/slic3r/GUI/RemovableDriveManager.cpp
@@ -84,7 +84,7 @@ void RemovableDriveManager::eject_drive()
 	this->update();
 #endif // REMOVABLE_DRIVE_MANAGER_OS_CALLBACKS
 	BOOST_LOG_TRIVIAL(info) << "Ejecting started"; 
-	tbb::mutex::scoped_lock lock(m_drives_mutex);
+	std::scoped_lock<std::mutex> lock(m_drives_mutex);
 	auto it_drive_data = this->find_last_save_path_drive_data();
 	if (it_drive_data != m_current_drives.end()) {
 		// get handle to device
@@ -130,7 +130,7 @@ std::string RemovableDriveManager::get_removable_drive
 	this->update();
 #endif // REMOVABLE_DRIVE_MANAGER_OS_CALLBACKS
 
-	tbb::mutex::scoped_lock lock(m_drives_mutex);
+	std::scoped_lock<std::mutex> lock(m_drives_mutex);
 	if (m_current_drives.empty())
 		return std::string();
 	std::size_t found = path.find_last_of("\\");
@@ -146,7 +146,7 @@ std::string RemovableDriveManager::get_removable_drive
 
 std::string RemovableDriveManager::get_removable_drive_from_path(const std::string& path)
 {
-	tbb::mutex::scoped_lock lock(m_drives_mutex);
+	std::scoped_lock<std::mutex> lock(m_drives_mutex);
 	std::size_t found = path.find_last_of("\\");
 	std::string new_path = path.substr(0, found);
 	int letter = PathGetDriveNumberW(boost::nowide::widen(new_path).c_str());	
@@ -285,7 +285,7 @@ void RemovableDriveManager::eject_drive()
 
 	DriveData drive_data;
 	{
-		tbb::mutex::scoped_lock lock(m_drives_mutex);
+		std::scoped_lock<std::mutex> lock(m_drives_mutex);
 		auto it_drive_data = this->find_last_save_path_drive_data();
 		if (it_drive_data == m_current_drives.end())
 			return;
@@ -341,7 +341,7 @@ void RemovableDriveManager::eject_drive()
 		if (success) {
 			// Remove the drive_data from m_current drives, searching by value, not by pointer, as m_current_drives may get modified during
 			// asynchronous execution on m_eject_thread.
-			tbb::mutex::scoped_lock lock(m_drives_mutex);
+			std::scoped_lock<std::mutex> lock(m_drives_mutex);
 			auto it = std::find(m_current_drives.begin(), m_current_drives.end(), drive_data);
 			if (it != m_current_drives.end())
 				m_current_drives.erase(it);
@@ -361,7 +361,7 @@ std::string RemovableDriveManager::get_removable_drive
 	std::size_t found = path.find_last_of("/");
 	std::string new_path = found == path.size() - 1 ? path.substr(0, found) : path;
 
-	tbb::mutex::scoped_lock lock(m_drives_mutex);
+	std::scoped_lock<std::mutex> lock(m_drives_mutex);
 	for (const DriveData &data : m_current_drives)
 		if (search_for_drives_internal::compare_filesystem_id(new_path, data.path))
 			return path;
@@ -377,7 +377,7 @@ std::string RemovableDriveManager::get_removable_drive
     new_path = new_path.substr(0, found);
     
 	// check if same filesystem
-	tbb::mutex::scoped_lock lock(m_drives_mutex);
+	std::scoped_lock<std::mutex> lock(m_drives_mutex);
 	for (const DriveData &drive_data : m_current_drives)
 		if (search_for_drives_internal::compare_filesystem_id(new_path, drive_data.path))
 			return drive_data.path;
@@ -452,7 +452,7 @@ RemovableDriveManager::RemovableDrivesStatus Removable
 
 	RemovableDriveManager::RemovableDrivesStatus out;
 	{
-		tbb::mutex::scoped_lock lock(m_drives_mutex);
+		std::scoped_lock<std::mutex> lock(m_drives_mutex);
 		out.has_eject = 
 			// Cannot control eject on Chromium.
 			platform_flavor() != PlatformFlavor::LinuxOnChromium &&
@@ -468,17 +468,17 @@ RemovableDriveManager::RemovableDrivesStatus Removable
 // Update is called from thread_proc() and from most of the public methods on demand.
 void RemovableDriveManager::update()
 {
-	tbb::mutex::scoped_lock inside_update_lock;
+	std::unique_lock<std::mutex> inside_update_lock(m_inside_update_mutex, std::defer_lock);
 #ifdef _WIN32
 	// All wake up calls up to now are now consumed when the drive enumeration starts.
 	m_wakeup = false;
 #endif // _WIN32
-	if (inside_update_lock.try_acquire(m_inside_update_mutex)) {
+	if (inside_update_lock.try_lock()) {
 		// Got the lock without waiting. That means, the update was not running.
 		// Run the update.
 		std::vector<DriveData> current_drives = this->search_for_removable_drives();
 		// Post update events.
-		tbb::mutex::scoped_lock lock(m_drives_mutex);
+		std::scoped_lock<std::mutex> lock(m_drives_mutex);
 		std::sort(current_drives.begin(), current_drives.end());
 		if (current_drives != m_current_drives) {
 			assert(m_callback_evt_handler);
@@ -489,7 +489,7 @@ void RemovableDriveManager::update()
 	} else {
 		// Acquiring the m_iniside_update lock failed, therefore another update is running.
 		// Just block until the other instance of update() finishes.
-		inside_update_lock.acquire(m_inside_update_mutex);
+		inside_update_lock.lock();
 	}
 }
 
