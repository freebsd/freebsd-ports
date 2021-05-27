--- extern/audaspace/bindings/python/PySound.cpp.orig	2020-09-02 11:06:51 UTC
+++ extern/audaspace/bindings/python/PySound.cpp
@@ -2015,7 +2015,7 @@ AUD_API Sound* checkSound(PyObject* sound)
 
 bool initializeSound()
 {
-	import_array();
+	import_array1(false);
 
 	return PyType_Ready(&SoundType) >= 0;
 }
