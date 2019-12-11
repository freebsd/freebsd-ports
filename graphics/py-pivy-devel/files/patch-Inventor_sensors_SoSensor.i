--- Inventor/sensors/SoSensor.i.orig	2018-06-08 08:15:18 UTC
+++ Inventor/sensors/SoSensor.i
@@ -4,7 +4,7 @@ SoSensorPythonCB(void * data, SoSensor * sensor)
 {
   PyGILState_STATE gil = PyGILState_Ensure();
   swig_type_info * swig_type = 0;
-  char * sensor_cast_name = NULL;
+  const char * sensor_cast_name = NULL;
   PyObject * func, * arglist;
   PyObject * result, * pysensor;
 
