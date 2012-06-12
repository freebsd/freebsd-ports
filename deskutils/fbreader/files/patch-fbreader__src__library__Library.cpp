--- ./fbreader/src/library/Library.cpp	2010-04-01 15:14:24.000000000 +0200
+++ ./fbreader/src/library/Library.cpp	2010-04-13 13:34:06.000000000 +0200
@@ -39,7 +39,7 @@
 shared_ptr<Library> Library::ourInstance;
 const size_t Library::MaxRecentListSize = 10;
 
-Library::Library &Library::Instance() {
+Library &Library::Instance() {
 	if (ourInstance.isNull()) {
 		ourInstance = new Library();
 	}
