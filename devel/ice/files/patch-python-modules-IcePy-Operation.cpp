--- python/modules/IcePy/Operation.cpp.orig	2017-01-29 22:23:51.186130998 +0100
+++ python/modules/IcePy/Operation.cpp	2017-01-29 22:24:55.929130998 +0100
@@ -1682,11 +1682,11 @@
             }
             else
             {
-                if(PyTuple_SET_ITEM(results.get(), info->pos, Unset) < 0)
+                if(PyTuple_SetItem(results.get(), info->pos, Unset) < 0)
                 {
                     return 0;
                 }
-                Py_INCREF(Unset); // PyTuple_SET_ITEM steals a reference.
+                Py_INCREF(Unset); // PyTuple_SetItem steals a reference.
             }
         }
 
@@ -2546,7 +2546,7 @@
             throwPythonException();
         }
 
-        if(PyTuple_SET_ITEM(result.get(), 0, ok ? incTrue() : incFalse()) < 0)
+        if(PyTuple_SetItem(result.get(), 0, ok ? incTrue() : incFalse()) < 0)
         {
             throwPythonException();
         }
@@ -2586,11 +2586,11 @@
         }
 #endif
 
-        if(PyTuple_SET_ITEM(result.get(), 1, op.get()) < 0)
+        if(PyTuple_SetItem(result.get(), 1, op.get()) < 0)
         {
             throwPythonException();
         }
-        op.release(); // PyTuple_SET_ITEM steals a reference.
+        op.release(); // PyTuple_SetItem steals a reference.
 
         return result.release();
     }
@@ -2827,7 +2827,7 @@
             return 0;
         }
 
-        if(PyTuple_SET_ITEM(args.get(), 0, ok ? incTrue() : incFalse()) < 0)
+        if(PyTuple_SetItem(args.get(), 0, ok ? incTrue() : incFalse()) < 0)
         {
             return 0;
         }
@@ -2867,11 +2867,11 @@
         memcpy(buf, results.first, sz);
 #endif
 
-        if(PyTuple_SET_ITEM(args.get(), 1, op.get()) < 0)
+        if(PyTuple_SetItem(args.get(), 1, op.get()) < 0)
         {
             return 0;
         }
-        op.release(); // PyTuple_SET_ITEM steals a reference.
+        op.release(); // PyTuple_SetItem steals a reference.
 
         return args.release();
     }
@@ -2910,7 +2910,7 @@
             return;
         }
 
-        if(PyTuple_SET_ITEM(args.get(), 0, ok ? incTrue() : incFalse()) < 0)
+        if(PyTuple_SetItem(args.get(), 0, ok ? incTrue() : incFalse()) < 0)
         {
             assert(PyErr_Occurred());
             PyErr_Print();
@@ -2958,13 +2958,13 @@
         memcpy(buf, results.first, sz);
 #endif
 
-        if(PyTuple_SET_ITEM(args.get(), 1, op.get()) < 0)
+        if(PyTuple_SetItem(args.get(), 1, op.get()) < 0)
         {
             assert(PyErr_Occurred());
             PyErr_Print();
             return;
         }
-        op.release(); // PyTuple_SET_ITEM steals a reference.
+        op.release(); // PyTuple_SetItem steals a reference.
 
         PyObjectHandle tmp = PyObject_Call(_response, args.get(), 0);
         if(PyErr_Occurred())
@@ -3126,7 +3126,7 @@
             return;
         }
 
-        if(PyTuple_SET_ITEM(args.get(), 0, ok ? incTrue() : incFalse()) < 0)
+        if(PyTuple_SetItem(args.get(), 0, ok ? incTrue() : incFalse()) < 0)
         {
             assert(PyErr_Occurred());
             PyErr_Print();
@@ -3174,13 +3174,13 @@
         memcpy(buf, results.first, sz);
 #endif
 
-        if(PyTuple_SET_ITEM(args.get(), 1, op.get()) < 0)
+        if(PyTuple_SetItem(args.get(), 1, op.get()) < 0)
         {
             assert(PyErr_Occurred());
             PyErr_Print();
             return;
         }
-        op.release(); // PyTuple_SET_ITEM steals a reference.
+        op.release(); // PyTuple_SetItem steals a reference.
 
         const string methodName = "ice_response";
         if(!PyObject_HasAttrString(_callback, STRCAST(methodName.c_str())))
@@ -3302,11 +3302,11 @@
                 }
                 else
                 {
-                    if(PyTuple_SET_ITEM(args.get(), info->pos + offset, Unset) < 0)
+                    if(PyTuple_SetItem(args.get(), info->pos + offset, Unset) < 0)
                     {
                         throwPythonException();
                     }
-                    Py_INCREF(Unset); // PyTuple_SET_ITEM steals a reference.
+                    Py_INCREF(Unset); // PyTuple_SetItem steals a reference.
                 }
             }
 
@@ -3329,11 +3329,11 @@
     // Create an object to represent Ice::Current. We need to append this to the argument tuple.
     //
     PyObjectHandle curr = createCurrent(current);
-    if(PyTuple_SET_ITEM(args.get(), PyTuple_GET_SIZE(args.get()) - 1, curr.get()) < 0)
+    if(PyTuple_SetItem(args.get(), PyTuple_GET_SIZE(args.get()) - 1, curr.get()) < 0)
     {
         throwPythonException();
     }
-    curr.release(); // PyTuple_SET_ITEM steals a reference.
+    curr.release(); // PyTuple_SetItem steals a reference.
 
     if(_op->amd)
     {
@@ -3347,7 +3347,7 @@
         }
         obj->upcall = new UpcallPtr(this);
         obj->encoding = current.encoding;
-        if(PyTuple_SET_ITEM(args.get(), 0, (PyObject*)obj) < 0) // PyTuple_SET_ITEM steals a reference.
+        if(PyTuple_SetItem(args.get(), 0, (PyObject*)obj) < 0) // PyTuple_SetItem steals a reference.
         {
             Py_DECREF(obj);
             throwPythonException();
@@ -3698,23 +3698,23 @@
     }
 #endif
 
-    if(PyTuple_SET_ITEM(args.get(), start, ip.get()) < 0)
+    if(PyTuple_SetItem(args.get(), start, ip.get()) < 0)
     {
         throwPythonException();
     }
     ++start;
-    ip.release(); // PyTuple_SET_ITEM steals a reference.
+    ip.release(); // PyTuple_SetItem steals a reference.
 
     //
     // Create an object to represent Ice::Current. We need to append
     // this to the argument tuple.
     //
     PyObjectHandle curr = createCurrent(current);
-    if(PyTuple_SET_ITEM(args.get(), start, curr.get()) < 0)
+    if(PyTuple_SetItem(args.get(), start, curr.get()) < 0)
     {
         throwPythonException();
     }
-    curr.release(); // PyTuple_SET_ITEM steals a reference.
+    curr.release(); // PyTuple_SetItem steals a reference.
 
     string dispatchName = "ice_invoke";
     if(_amd)
@@ -3730,7 +3730,7 @@
         }
         obj->upcall = new UpcallPtr(this);
         obj->encoding = current.encoding;
-        if(PyTuple_SET_ITEM(args.get(), 0, (PyObject*)obj) < 0) // PyTuple_SET_ITEM steals a reference.
+        if(PyTuple_SetItem(args.get(), 0, (PyObject*)obj) < 0) // PyTuple_SetItem steals a reference.
         {
             Py_DECREF(obj);
             throwPythonException();
