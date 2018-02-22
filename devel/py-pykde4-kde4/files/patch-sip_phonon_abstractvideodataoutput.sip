PyList_SET_ITEM() is supposed to be void, but as a macro it's an 
expression and has a pointer value. Clang 4.0 trips on the bogus
pointer comparison; given the comparison, it should be PyList_SetItem()
which returns -1 on failure.

--- sip/phonon/abstractvideodataoutput.sip.orig	2014-08-14 20:17:11 UTC
+++ sip/phonon/abstractvideodataoutput.sip
@@ -72,7 +72,7 @@ protected:
     foreach (Phonon::Experimental::VideoFrame2::Format value, set)
     {
         PyObject *obj = PyInt_FromLong ((long) value);
-        if (obj == NULL || PyList_SET_ITEM (l, i, obj) < 0)
+        if (obj == NULL || PyList_SetItem (l, i, obj) < 0)
         {
             Py_DECREF(l);
 
