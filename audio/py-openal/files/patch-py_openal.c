--- py_openal.c	Sat Jul 16 09:19:11 2005
+++ py_openal.c	Mon Aug 21 01:33:49 2006
@@ -1041,28 +1041,26 @@
 }
 
 
-static PyObject *_wrap_alutLoadWAVFile(PyObject *self, PyObject *arg) {
+static PyObject *_wrap_alutLoadMemoryFromFile(PyObject *self, PyObject *arg) {
     ALvoid *wave = NULL;
     ALsizei format;
     ALsizei size;
-    ALsizei bits;
-    ALsizei freq;
+    ALfloat freq;
     PyObject* resultobj;
 
     if(!PyString_Check(arg)) return NULL;
 
-    alutLoadWAVFile((char* const) PyString_AS_STRING(arg), &wave, &format, &size, &bits, &freq);
+    wave = alutLoadMemoryFromFile ((char* const) PyString_AS_STRING(arg), &format, &size, &freq);
 
     if(wave == NULL) {
         Py_INCREF(Py_None);
         return Py_None;
     } else {
-        resultobj = PyTuple_New(5);
+        resultobj = PyTuple_New(4);
         PyTuple_SET_ITEM(resultobj, 0, PyString_FromStringAndSize(wave, size));
         PyTuple_SET_ITEM(resultobj, 1, PyInt_FromLong((long) format));
         PyTuple_SET_ITEM(resultobj, 2, PyInt_FromLong((long) size));
-        PyTuple_SET_ITEM(resultobj, 3, PyInt_FromLong((long) bits));
-        PyTuple_SET_ITEM(resultobj, 4, PyInt_FromLong((long) freq));
+        PyTuple_SET_ITEM(resultobj, 3, PyInt_FromLong((long) freq));
         return resultobj;
     }
 }
@@ -2274,7 +2272,7 @@
 */
 	 { (char *)"alutInit", (PyCFunction) _wrap_alutInit, METH_VARARGS },
 	 { (char *)"alutExit", (PyCFunction) _wrap_alutExit, METH_NOARGS },
-	 { (char *)"alutLoadWAVFile", (PyCFunction) _wrap_alutLoadWAVFile, METH_VARARGS },
+	 { (char *)"alutLoadMemoryFromFile", (PyCFunction) _wrap_alutLoadMemoryFromFile, METH_VARARGS },
 /*
 	 { (char *)"alcGetAudioChannel_LOKI", (PyCFunction) _wrap_alcGetAudioChannel_LOKI, METH_VARARGS },
 	 { (char *)"alcSetAudioChannel_LOKI", (PyCFunction) _wrap_alcSetAudioChannel_LOKI, METH_VARARGS },
