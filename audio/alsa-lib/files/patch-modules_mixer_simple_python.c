https://git.alsa-project.org/?p=alsa-lib.git;a=commitdiff;h=345843fc24b3

--- modules/mixer/simple/python.c.orig	2016-08-02 17:48:38 UTC
+++ modules/mixer/simple/python.c
@@ -25,6 +25,10 @@
 #include "asoundlib.h"
 #include "mixer_abst.h"
 
+#if (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 2))
+#pragma GCC diagnostic ignored "-Wstrict-aliasing"
+#endif
+
 struct python_priv {
 	int py_initialized;
 	PyObject *py_event_func;
@@ -56,20 +60,49 @@ struct pymixer {
 
 static PyInterpreterState *main_interpreter;
 
+#if PY_MAJOR_VERSION >= 3
+  #define PyInt_FromLong PyLong_FromLong
+#endif
+
+static inline int get_long(PyObject *o, long *val)
+{
+#if PY_MAJOR_VERSION < 3
+        if (PyInt_Check(o)) {
+                *val = PyInt_AsLong(o);
+                return 0;
+        }
+#endif
+        if (PyLong_Check(o)) {
+                *val = PyLong_AsLong(o);
+                return 0;
+        }
+        return 1;
+}
+
+static inline PyObject *InternFromString(const char *name)
+{
+#if PY_MAJOR_VERSION < 3
+        return PyString_InternFromString(name);
+#else
+        return PyUnicode_InternFromString(name);
+#endif
+}
+
 static void *get_C_ptr(PyObject *obj, const char *attr)
 {
 	PyObject *o;
+	long val;
 
-	o = PyObject_GetAttr(obj, PyString_InternFromString(attr));
+	o = PyObject_GetAttr(obj, InternFromString(attr));
 	if (!o) {
 		PyErr_Format(PyExc_TypeError, "missing '%s' attribute", attr);
 		return NULL;
 	}
-	if (!PyInt_Check(o)) {
-		PyErr_Format(PyExc_TypeError, "'%s' attribute is not integer", attr);
+	if (get_long(o, &val)) {
+		PyErr_Format(PyExc_TypeError, "'%s' attribute is not Int or Long", attr);
 		return NULL;
 	}
-	return (void *)PyInt_AsLong(o);
+	return (void *)val;
 }
 
 static struct pymelem *melem_to_pymelem(snd_mixer_elem_t *elem)
@@ -80,11 +113,11 @@ static struct pymelem *melem_to_pymelem(snd_mixer_elem
 static int pcall(struct pymelem *pymelem, const char *attr, PyObject *args, PyObject **_res)
 {
 	PyObject *obj = (PyObject *)pymelem, *res;
-	int xres = 0;
+	long xres = 0;
 
 	if (_res)
 		*_res = NULL;
-	obj = PyObject_GetAttr(obj, PyString_InternFromString(attr));
+	obj = PyObject_GetAttr(obj, InternFromString(attr));
 	if (!obj) {
 		PyErr_Format(PyExc_TypeError, "missing '%s' attribute", attr);
 		PyErr_Print();
@@ -103,8 +136,12 @@ static int pcall(struct pymelem *pymelem, const char *
 		*_res = res;
 		res = PyTuple_GetItem(res, 0);
 	}
-	if (PyInt_Check(res)) {
+	if (PyLong_Check(res)) {
+		xres = PyLong_AsLong(res);
+#if PY_MAJOR_VERSION < 3
+	} else if (PyInt_Check(res)) {
 		xres = PyInt_AsLong(res);
+#endif
 	} else if (res == Py_None) {
 		xres = 0;
 	} else if (PyBool_Check(res)) {
@@ -155,7 +192,7 @@ static int is_ops(snd_mixer_elem_t *elem, int dir, int
 static int get_x_range_ops(snd_mixer_elem_t *elem, int dir,
                            long *min, long *max, const char *attr)
 {
-	PyObject *obj1, *res;
+	PyObject *obj1, *t1, *t2, *res;
 	struct pymelem *pymelem = melem_to_pymelem(elem);
 	int err;
 	
@@ -163,21 +200,23 @@ static int get_x_range_ops(snd_mixer_elem_t *elem, int
 	PyTuple_SET_ITEM(obj1, 0, PyInt_FromLong(dir));
 	err = pcall(pymelem, attr, obj1, &res);
 	if (err >= 0) {
-		err = !PyInt_Check(PyTuple_GetItem(res, 1)) || !PyInt_Check(PyTuple_GetItem(res, 2));
-		if (err) {
-			err = !PyLong_Check(PyTuple_GetItem(res, 1)) || !PyLong_Check(PyTuple_GetItem(res, 2));
-			if (err) {
-				PyErr_Format(PyExc_TypeError, "wrong result (invalid tuple)");
-				PyErr_Print();
-				PyErr_Clear();
-				err = -EIO;
-			} else {
-				*min = PyLong_AsLong(PyTuple_GetItem(res, 1));
-				*max = PyLong_AsLong(PyTuple_GetItem(res, 2));
-			}
-		} else {
+		t1 = PyTuple_GetItem(res, 1);
+		t2 = PyTuple_GetItem(res, 2);
+		if (PyLong_Check(t1) && PyLong_Check(t2)) {
+			*min = PyLong_AsLong(PyTuple_GetItem(res, 1));
+			*max = PyLong_AsLong(PyTuple_GetItem(res, 2));
+			err = 0;
+#if PY_MAJOR_VERSION < 3
+		} else if (PyInt_Check(t1) && PyInt_Check(t2)) {
 			*min = PyInt_AsLong(PyTuple_GetItem(res, 1));
 			*max = PyInt_AsLong(PyTuple_GetItem(res, 2));
+			err = 0;
+#endif
+		} else {
+			PyErr_Format(PyExc_TypeError, "wrong result (invalid tuple)");
+			PyErr_Print();
+			PyErr_Clear();
+			err = -EIO;
 		}
 	}
 	Py_XDECREF(res);
@@ -207,7 +246,7 @@ static int get_x_ops(snd_mixer_elem_t *elem, int dir,
                      long channel, long *value,
                      const char *attr)
 {
-	PyObject *obj1, *res;
+	PyObject *obj1, *t1, *res;
 	struct pymelem *pymelem = melem_to_pymelem(elem);
 	int err;
 	
@@ -216,19 +255,20 @@ static int get_x_ops(snd_mixer_elem_t *elem, int dir,
 	PyTuple_SET_ITEM(obj1, 1, PyInt_FromLong(channel));
 	err = pcall(pymelem, attr, obj1, &res);
 	if (err >= 0) {
-		err = !PyInt_Check(PyTuple_GetItem(res, 1));
-		if (err) {
-			err = !PyLong_Check(PyTuple_GetItem(res, 1));
-			if (err) {
-				PyErr_Format(PyExc_TypeError, "wrong result (invalid tuple)");
-				PyErr_Print();
-				PyErr_Clear();
-				err = -EIO;
-			} else {
-				*value = PyLong_AsLong(PyTuple_GetItem(res, 1));
-			}
+		t1 = PyTuple_GetItem(res, 1);
+		if (PyLong_Check(t1)) {
+			*value = PyLong_AsLong(t1);
+			err = 0;
+#if PY_MAJOR_VERSION < 3
+		} else if (PyInt_Check(t1)) {
+			*value = PyInt_AsLong(t1);
+			err = 0;
+#endif
 		} else {
-			*value = PyInt_AsLong(PyTuple_GetItem(res, 1));
+			PyErr_Format(PyExc_TypeError, "wrong result (invalid tuple)");
+			PyErr_Print();
+			PyErr_Clear();
+			err = -EIO;
 		}
 	}
 	Py_XDECREF(res);
@@ -265,7 +305,7 @@ static int ask_dB_vol_ops(snd_mixer_elem_t *elem,
 			  long *dbValue,
 			  int xdir)
 {
-	PyObject *obj1, *res;
+	PyObject *obj1, *t1, *res;
 	struct pymelem *pymelem = melem_to_pymelem(elem);
 	int err;
 	
@@ -275,19 +315,20 @@ static int ask_dB_vol_ops(snd_mixer_elem_t *elem,
 	PyTuple_SET_ITEM(obj1, 2, PyInt_FromLong(xdir));
 	err = pcall(pymelem, "opsGetDBVol", obj1, &res);
 	if (err >= 0) {
-		err = !PyInt_Check(PyTuple_GetItem(res, 1));
-		if (err) {
-			err = !PyLong_Check(PyTuple_GetItem(res, 1));
-			if (err) {
-				PyErr_Format(PyExc_TypeError, "wrong result (invalid tuple)");
-				PyErr_Print();
-				PyErr_Clear();
-				err = -EIO;
-			} else {
-				*dbValue = PyLong_AsLong(PyTuple_GetItem(res, 1));
-			}
+		t1 = PyTuple_GetItem(res, 1);
+		if (PyLong_Check(t1)) {
+			*dbValue = PyLong_AsLong(t1);
+			err = 0;
+#if PY_MAJOR_VERSION < 3
+		} else if (PyInt_Check(t1)) {
+			*dbValue = PyInt_AsLong(t1);
+			err = 0;
+#endif
 		} else {
-			*dbValue = PyInt_AsLong(PyTuple_GetItem(res, 1));
+			PyErr_Format(PyExc_TypeError, "wrong result (invalid tuple)");
+			PyErr_Print();
+			PyErr_Clear();
+			err = -EIO;
 		}
 	}
 	Py_XDECREF(res);
@@ -353,7 +394,7 @@ static int enum_item_name_ops(snd_mixer_elem_t *elem,
                               unsigned int item,
                               size_t maxlen, char *buf)
 {
-	PyObject *obj1, *res;
+	PyObject *obj1, *obj2, *t1, *res;
 	struct pymelem *pymelem = melem_to_pymelem(elem);
 	int err;
 	unsigned int len;
@@ -363,19 +404,35 @@ static int enum_item_name_ops(snd_mixer_elem_t *elem,
 	PyTuple_SET_ITEM(obj1, 0, PyInt_FromLong(item));
 	err = pcall(pymelem, "opsGetEnumItemName", obj1, &res);
 	if (err >= 0) {
-		err = !PyString_Check(PyTuple_GetItem(res, 1));
-		if (err) {
-			PyErr_Format(PyExc_TypeError, "wrong result (invalid tuple)");
-			PyErr_Print();
-			PyErr_Clear();
-			err = -EIO;
-		} else {
-			s = PyString_AsString(PyTuple_GetItem(res, 1));
+		t1 = PyTuple_GetItem(res, 1);
+		if (PyUnicode_Check(t1)) {
+			obj2 = PyUnicode_AsEncodedString(t1, "utf-8", "strict");
+			if (obj2) {
+				s = PyBytes_AsString(obj2);
+				len = strlen(s);
+				if (maxlen - 1 > len)
+					len = maxlen - 1;
+				memcpy(buf, s, len);
+				buf[len] = '\0';
+				Py_DECREF(obj2);
+			} else {
+				goto errlbl;
+			}
+#if PY_MAJOR_VERSION < 3
+		} else if (PyString_Check(t1)) {
+			s = PyString_AsString(t1);
 			len = strlen(s);
 			if (maxlen - 1 > len)
 				len = maxlen - 1;
 			memcpy(buf, s, len);
 			buf[len] = '\0';
+#endif
+		} else {
+errlbl:
+			PyErr_Format(PyExc_TypeError, "wrong result (invalid tuple)");
+			PyErr_Print();
+			PyErr_Clear();
+			err = -EIO;
 		}
 	}
 	Py_XDECREF(res);
@@ -386,7 +443,7 @@ static int get_enum_item_ops(snd_mixer_elem_t *elem,
                              snd_mixer_selem_channel_id_t channel,
                              unsigned int *itemp)
 {
-	PyObject *obj1, *res;
+	PyObject *obj1, *t1, *res;
 	struct pymelem *pymelem = melem_to_pymelem(elem);
 	int err;
 	
@@ -394,14 +451,20 @@ static int get_enum_item_ops(snd_mixer_elem_t *elem,
 	PyTuple_SET_ITEM(obj1, 0, PyInt_FromLong(channel));
 	err = pcall(pymelem, "opsGetEnumItem", obj1, &res);
 	if (err >= 0) {
-		err = !PyInt_Check(PyTuple_GetItem(res, 1));
-		if (err) {
+		t1 = PyTuple_GetItem(res, 1);
+		if (PyLong_Check(t1)) {
+			*itemp = PyLong_AsLong(t1);
+			err = 0;
+#if PY_MAJOR_VERSION < 3
+		} else if (PyInt_Check(t1)) {
+			*itemp = PyInt_AsLong(t1);
+			err = 0;
+#endif
+		} else {
 			PyErr_Format(PyExc_TypeError, "wrong result (invalid tuple)");
 			PyErr_Print();
 			PyErr_Clear();
 			err = -EIO;
-		} else {
-			*itemp = PyInt_AsLong(PyTuple_GetItem(res, 1));
 		}
 	}
 	Py_XDECREF(res);
@@ -464,7 +527,7 @@ pymelem_get_caps(struct pymelem *pymelem, void *priv A
 static PyObject *
 pymelem_get_name(struct pymelem *pymelem, void *priv ATTRIBUTE_UNUSED)
 {
-	return PyString_FromString(snd_mixer_selem_id_get_name(pymelem->selem.id));
+	return PyUnicode_FromString(snd_mixer_selem_id_get_name(pymelem->selem.id));
 }
 
 static PyObject *
@@ -476,12 +539,18 @@ pymelem_get_index(struct pymelem *pymelem, void *priv 
 static int
 pymelem_set_caps(struct pymelem *pymelem, PyObject *val, void *priv ATTRIBUTE_UNUSED)
 {
-	if (!PyInt_Check(val)) {
-		PyErr_SetString(PyExc_TypeError, "The last attribute value must be an integer");
-		return -1;
+	if (PyLong_Check(val)) {
+		pymelem->selem.caps = PyLong_AsLong(val);
+		return 0;
 	}
-	pymelem->selem.caps = PyInt_AsLong(val);
-	return 0;
+#if PY_MAJOR_VERSION < 3
+	if (PyInt_Check(val)) {
+		pymelem->selem.caps = PyInt_AsLong(val);
+		return 0;
+	}
+#endif
+	PyErr_SetString(PyExc_TypeError, "The last attribute value must be an integer");
+	return -1;
 }
 
 static PyObject *
@@ -588,7 +657,6 @@ static void
 pymelem_dealloc(struct pymelem *self)
 {
 	selem_free(self->melem);
-        self->ob_type->tp_free(self);
 }
 
 static PyGetSetDef pymelem_getseters[] = {
@@ -634,7 +702,7 @@ static PyMethodDef pymelem_methods[] = {
 };
 
 static PyTypeObject pymelem_type = {
-        PyObject_HEAD_INIT(0)
+        PyVarObject_HEAD_INIT(NULL, 0)
         tp_name:        "smixer_python.InternalMElement",
         tp_basicsize:   sizeof(struct pymelem),
         tp_dealloc:     (destructor)pymelem_dealloc,
@@ -708,7 +776,7 @@ pymixer_melement_new(struct pymixer *pymixer, PyObject
 		obj1 = PyTuple_New(4);
 		if (PyTuple_SET_ITEM(obj1, 0, (PyObject *)pymixer))
 			Py_INCREF((PyObject *)pymixer);
-		PyTuple_SET_ITEM(obj1, 1, PyString_FromString(name));
+		PyTuple_SET_ITEM(obj1, 1, PyUnicode_FromString(name));
 		PyTuple_SET_ITEM(obj1, 2, PyInt_FromLong(index));
 		PyTuple_SET_ITEM(obj1, 3, PyInt_FromLong(weight));
 		obj2 = PyObject_CallObject(obj, obj1);
@@ -800,7 +868,6 @@ static void
 pymixer_dealloc(struct pymixer *self)
 {
 	pymixer_free(self);
-        self->ob_type->tp_free(self);
 }
 
 static PyGetSetDef pymixer_getseters[] = {
@@ -816,7 +883,7 @@ static PyMethodDef pymixer_methods[] = {
 };
 
 static PyTypeObject pymixer_type = {
-        PyObject_HEAD_INIT(0)
+        PyVarObject_HEAD_INIT(NULL, 0)
         tp_name:        "smixer_python.InternalMixer",
         tp_basicsize:   sizeof(struct pymixer),
         tp_dealloc:     (destructor)pymixer_dealloc,
@@ -910,12 +977,12 @@ int alsa_mixer_simple_event(snd_mixer_class_t *class, 
 			    snd_hctl_elem_t *helem, snd_mixer_elem_t *melem)
 {
 	struct python_priv *priv = snd_mixer_sbasic_get_private(class);
-	PyThreadState *tstate, *origstate;
+	PyThreadState *tstate;
 	PyObject *t, *o, *r;
 	int res = -ENOMEM;
 
 	tstate = PyThreadState_New(main_interpreter);
-        origstate = PyThreadState_Swap(tstate);
+	PyThreadState_Swap(tstate);
         
         t = PyTuple_New(3);
         if (t) {
@@ -935,8 +1002,12 @@ int alsa_mixer_simple_event(snd_mixer_class_t *class, 
 		r = PyObject_CallObject(priv->py_event_func, t);
 		Py_DECREF(t);
 		if (r) {
-			if (PyInt_Check(r)) {
+			if (PyLong_Check(r)) {
+				res = PyLong_AsLong(r);
+#if PY_MAJOR_VERSION < 3
+			} else if (PyInt_Check(r)) {
 				res = PyInt_AsLong(r);
+#endif
 			} else if (r == Py_None) {
 				res = 0;
 			}
@@ -966,6 +1037,71 @@ static void alsa_mixer_simple_free(snd_mixer_class_t *
 	free(priv);
 }
 
+static int alsa_mixer_simple_pyinit(struct python_priv *priv,
+                                    PyObject *py_mod,
+                                    FILE *fp,
+				    const char *file,
+				    snd_mixer_class_t *class,
+				    snd_mixer_t *mixer,
+				    const char *device)
+{
+	PyObject *obj, *obj1, *obj2, *mdict;
+
+	mdict = priv->py_mdict = PyModule_GetDict(py_mod);
+	obj = PyUnicode_FromString(file);
+	if (obj)
+		PyDict_SetItemString(mdict, "__file__", obj);
+	Py_XDECREF(obj);
+	obj = PyUnicode_FromString(device);
+	if (obj)
+		PyDict_SetItemString(mdict, "device", obj);
+	Py_XDECREF(obj);
+	Py_INCREF(&pymelem_type);
+	Py_INCREF(&pymixer_type);
+	PyModule_AddObject(py_mod, "InternalMElement", (PyObject *)&pymelem_type);
+	PyModule_AddObject(py_mod, "InternalMixer", (PyObject *)&pymixer_type);
+	obj = PyDict_GetItemString(mdict, "InternalMixer");
+	if (obj) {
+		obj1 = PyTuple_New(3);
+		PyTuple_SET_ITEM(obj1, 0, PyInt_FromLong((long)class));
+		PyTuple_SET_ITEM(obj1, 1, PyInt_FromLong((long)mixer));
+		if (PyTuple_SET_ITEM(obj1, 2, mdict))
+			Py_INCREF(mdict);
+		obj2 = PyObject_CallObject(obj, obj1);
+		Py_XDECREF(obj1);
+		PyDict_SetItemString(mdict, "mixer", obj2);
+		priv->py_mixer = obj2;
+	} else {
+		SNDERR("Unable to create InternalMixer object");
+		return -EIO;
+	}
+
+	obj = PyRun_FileEx(fp, file, Py_file_input, mdict, mdict, 1);
+	if (obj == NULL)
+		PyErr_Print();
+	Py_XDECREF(obj);
+	priv->py_event_func = PyDict_GetItemString(mdict, "event");
+	if (priv->py_event_func == NULL) {
+		SNDERR("Unable to find python function 'event'");
+		return -EIO;
+	}
+	return 0;
+}
+
+#if PY_MAJOR_VERSION >= 3
+static struct PyModuleDef smixer_python_module = {
+        PyModuleDef_HEAD_INIT,
+        "smixer_python",
+        NULL,
+        0,
+        python_methods,
+        NULL,
+        NULL,
+        NULL,
+        NULL
+};
+#endif
+
 int alsa_mixer_simple_finit(snd_mixer_class_t *class,
 			    snd_mixer_t *mixer,
 			    const char *device)
@@ -973,7 +1109,7 @@ int alsa_mixer_simple_finit(snd_mixer_class_t *class,
 	struct python_priv *priv;
 	FILE *fp;
 	const char *file;
-	PyObject *obj, *obj1, *obj2, *py_mod, *mdict;
+	PyObject *obj, *py_mod;
 
 	priv = calloc(1, sizeof(*priv));
 	if (priv == NULL)
@@ -993,54 +1129,21 @@ int alsa_mixer_simple_finit(snd_mixer_class_t *class,
 	}
 	
 	Py_Initialize();
-	if (PyType_Ready(&pymelem_type) < 0)
+	if (PyType_Ready(&pymelem_type) < 0 ||
+	    PyType_Ready(&pymixer_type) < 0) {
+		fclose(fp);
 		return -EIO;
-	if (PyType_Ready(&pymixer_type) < 0)
-		return -EIO;
+	}
+#if PY_MAJOR_VERSION < 3
 	Py_InitModule("smixer_python", python_methods);
+#else
+	PyModule_Create(&smixer_python_module);
+#endif
 	priv->py_initialized = 1;
 	main_interpreter = PyThreadState_Get()->interp;
 	obj = PyImport_GetModuleDict();
 	py_mod = PyDict_GetItemString(obj, "__main__");
-	if (py_mod) {
-		mdict = priv->py_mdict = PyModule_GetDict(py_mod);
-		obj = PyString_FromString(file);
-		if (obj)
-			PyDict_SetItemString(mdict, "__file__", obj);
-		Py_XDECREF(obj);
-		obj = PyString_FromString(device);
-		if (obj)
-			PyDict_SetItemString(mdict, "device", obj);
-		Py_XDECREF(obj);
-		Py_INCREF(&pymixer_type);
-		PyModule_AddObject(py_mod, "InternalMElement", (PyObject *)&pymelem_type);
-		PyModule_AddObject(py_mod, "InternalMixer", (PyObject *)&pymixer_type);
-		obj = PyDict_GetItemString(mdict, "InternalMixer");
-		if (obj) {
-			obj1 = PyTuple_New(3);
-			PyTuple_SET_ITEM(obj1, 0, PyInt_FromLong((long)class));
-			PyTuple_SET_ITEM(obj1, 1, PyInt_FromLong((long)mixer));
-			if (PyTuple_SET_ITEM(obj1, 2, mdict))
-				Py_INCREF(mdict);
-			obj2 = PyObject_CallObject(obj, obj1);
-			Py_XDECREF(obj1);
-			PyDict_SetItemString(mdict, "mixer", obj2);
-			priv->py_mixer = obj2;
-		} else {
-			SNDERR("Unable to create InternalMixer object");
-			return -EIO;
-		}
-
-
-		obj = PyRun_FileEx(fp, file, Py_file_input, mdict, mdict, 1);
-		if (obj == NULL)
-			PyErr_Print();
-		Py_XDECREF(obj);
-		priv->py_event_func = PyDict_GetItemString(mdict, "event");
-		if (priv->py_event_func == NULL) {
-			SNDERR("Unable to find python function 'event'");
-			return -EIO;
-		}
-	}
+	if (py_mod)
+		alsa_mixer_simple_pyinit(priv, py_mod, fp, file, class, mixer, device);
 	return 0;
 }
