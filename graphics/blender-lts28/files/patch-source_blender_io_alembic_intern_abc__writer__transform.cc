--- source/blender/io/alembic/intern/abc_writer_transform.cc.orig	2021-05-17 18:04:27 UTC
+++ source/blender/io/alembic/intern/abc_writer_transform.cc
@@ -21,7 +21,7 @@
 #include "abc_writer_transform.h"
 #include "abc_util.h"
 
-#include <OpenEXR/ImathBoxAlgo.h>
+#include <Imath/ImathBoxAlgo.h>
 
 extern "C" {
 #include "DNA_object_types.h"
