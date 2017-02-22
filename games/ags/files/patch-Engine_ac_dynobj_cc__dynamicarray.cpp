--- Engine/ac/dynobj/cc_dynamicarray.cpp.orig	2017-02-21 00:32:02 UTC
+++ Engine/ac/dynobj/cc_dynamicarray.cpp
@@ -32,7 +32,7 @@ int CCDynamicArray::Dispose(const char *
         elementCount[0] &= ~ARRAY_MANAGED_TYPE_FLAG;
         for (int i = 0; i < elementCount[0]; i++)
         {
-            if (elementCount[2 + i] != NULL)
+            if (elementCount[2 + i] != 0)
             {
                 ccReleaseObjectReference(elementCount[2 + i]);
             }
