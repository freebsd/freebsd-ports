--- src/vm/properties.cpp.orig	2013-06-28 09:22:27.000000000 -0400
+++ src/vm/properties.cpp	2015-01-14 19:18:40.000000000 -0500
@@ -76,7 +76,11 @@
 
 	p = MNEW(char, 4096);
 
+#if defined(__FreeBSD__)
+	if (os::readlink("/proc/curproc/file", p, 4095) == -1)
+#else
 	if (os::readlink("/proc/self/exe", p, 4095) == -1)
+#endif
 		os::abort_errno("readlink failed");
 
 	/* We have a path like:
@@ -561,7 +565,7 @@
 void Properties::put(const char* key, const char* value)
 {
 	// Try to find the key.
-	std::map<const char*, const char*>::iterator it = _properties.find(key);
+	std::map<const char*, const char*, ltstr>::iterator it = _properties.find(key);
 
 	// The key is already in the map.
 	if (it != _properties.end()) {
@@ -590,7 +594,7 @@
 const char* Properties::get(const char* key)
 {
 	// Try to find the key.
-	std::map<const char*, const char*>::iterator it = _properties.find(key);
+	std::map<const char*, const char*, ltstr>::iterator it = _properties.find(key);
 
 	// The key is not in the map.
 	if (it == _properties.end())
@@ -624,7 +628,7 @@
 		return;
 
 	// Iterator over all properties.
-	for (std::map<const char*, const char*>::iterator it = _properties.begin(); it != _properties.end(); it++) {
+	for (std::map<const char*, const char*, ltstr>::iterator it = _properties.begin(); it != _properties.end(); it++) {
 		// Put into the Java system properties.
 		java_handle_t* key   = JavaString::from_utf8(it->first);
 		java_handle_t* value = JavaString::from_utf8(it->second);
@@ -641,7 +645,7 @@
 #if !defined(NDEBUG)
 void Properties::dump()
 {
-	for (std::map<const char*, const char*>::iterator it = _properties.begin(); it != _properties.end(); it++) {
+	for (std::map<const char*, const char*, ltstr>::iterator it = _properties.begin(); it != _properties.end(); it++) {
 		log_println("[Properties::dump: key=%s, value=%s]", it->first, it->second);
 	}
 }
