See patch-sip_phonon_abstractvideodataoutput.sip

--- sip/solid/powermanagement.sip.orig	2014-08-14 20:17:11 UTC
+++ sip/solid/powermanagement.sip
@@ -83,7 +83,7 @@ bool                    stopSuppressingS
 #else
         PyObject *obj = PyInt_FromLong ((long) value);
 #endif
-        if (obj == NULL || PyList_SET_ITEM (l, i, obj) < 0)
+        if (obj == NULL || PyList_SetItem (l, i, obj) < 0)
         {
             Py_DECREF(l);
 
