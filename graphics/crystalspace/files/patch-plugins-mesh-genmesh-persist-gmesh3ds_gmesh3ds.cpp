--- plugins/mesh/genmesh/persist/gmesh3ds/gmesh3ds.cpp	Mon Sep 10 10:41:09 2007
+++ plugins/mesh/genmesh/persist/gmesh3ds/gmesh3ds.cpp	Mon Sep 10 10:42:20 2007
@@ -278,15 +278,15 @@
 }
 
 
-static int DataReadFunc (void *self, Lib3dsByte *buffer, int size)
+static size_t DataReadFunc (void *self, void *buffer, size_t size)
 {
   iFile* pData = (iFile*)self;
   return (int)pData->Read ((char*)buffer, size );
 }
 
 
-static int DataWriteFunc (void* /*self*/, const Lib3dsByte* /*buffer*/,
-	int /*size*/)
+static size_t DataWriteFunc (void* /*self*/, const void* /*buffer*/,
+	size_t /*size*/)
 {
   // not yet implemented
   return 0;
