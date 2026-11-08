--- extension/spatial/src/spatial/modules/gdal/gdal_module.cpp.orig	2026-11-08 00:30:39 UTC
+++ extension/spatial/src/spatial/modules/gdal/gdal_module.cpp
@@ -168,9 +168,9 @@ class DuckDBFileHandle final : public VSIVirtualHandle
 		    -1);
 	}
 
-	size_t Read(void *buffer, size_t size, size_t count) override {
+	size_t Read(void *buffer, size_t nbytes) override {
 		auto bytes_data = static_cast<char *>(buffer);
-		auto bytes_left = size * count;
+		auto bytes_left = nbytes;
 
 		try {
 			while (bytes_left > 0) {
@@ -197,7 +197,7 @@ class DuckDBFileHandle final : public VSIVirtualHandle
 			VSIError(VSIE_FileError, "Unknown error reading file");
 		}
 
-		return count - (bytes_left / size);
+		return nbytes - bytes_left;
 	}
 
 	int Eof() override {
@@ -213,16 +213,16 @@ class DuckDBFileHandle final : public VSIVirtualHandle
 		is_error = false;
 	}
 
-	size_t Write(const void *buffer, size_t size, size_t count) override {
+	size_t Write(const void *buffer, size_t nbytes) override {
 		size_t written_bytes = 0;
 		try {
-			written_bytes = file_handle->Write(const_cast<void *>(buffer), size * count);
+			written_bytes = file_handle->Write(const_cast<void *>(buffer), nbytes);
 		} catch (std::exception &ex) {
 			VSIError(VSIE_FileError, "%s", CleanGDALMessage(ex.what()).c_str());
 		} catch (...) {
 			VSIError(VSIE_FileError, "Unknown error writing file");
 		}
-		return written_bytes / size;
+		return written_bytes;
 	}
 
 	int Flush() override {
@@ -2273,7 +2273,7 @@ void RegisterGDALModule(ExtensionLoader &loader) {
 	static std::once_flag loaded;
 	std::call_once(loaded, [&]() {
 		// Register all embedded drivers (dont go looking for plugins)
-		OGRRegisterAllInternal();
+		OGRRegisterAll();
 
 		// GDAL error handler. For ordinary failures we MUST NOT throw from here: GDAL is not exception-safe and an
 		// exception thrown from the handler unwinds through GDAL's own frames, leaking memory and potentially
