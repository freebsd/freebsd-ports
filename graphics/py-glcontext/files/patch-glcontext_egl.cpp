--- glcontext/egl.cpp.orig	2023-01-20 19:29:43 UTC
+++ glcontext/egl.cpp
@@ -216,7 +216,7 @@ GLContext * meth_create_context(PyObject * self, PyObj
             return NULL;
         }
 
-        EGLDeviceEXT* devices = malloc(sizeof(EGLDeviceEXT) * num_devices);
+        EGLDeviceEXT* devices = (EGLDeviceEXT*)malloc(sizeof(EGLDeviceEXT) * num_devices);
         if (!res->m_eglQueryDevicesEXT(num_devices, devices, &num_devices)) {
             PyErr_Format(PyExc_Exception, "eglQueryDevicesEXT failed (0x%x)", res->m_eglGetError());
             free(devices);
