--- src/sysctl.c.orig	2011-04-12 12:30:50.000000000 +0400
+++ src/sysctl.c	2011-04-12 12:37:45.000000000 +0400
@@ -121,7 +121,7 @@ const size_t sysctl_type_sizes[CTLTYPE] 
 	0,			/* CTLTYPE_NODE */
 	sizeof(int),		/* CTLTYPE_INT */
 	0,			/* CTLTYPE_STRING */
-	sizeof(quad_t),		/* CTLTYPE_QUAD */
+	sizeof(quad_t),		/* CTLTYPE_S64 */
 	0,			/* CTLTYPE_OPAQUE */
 	sizeof(unsigned int),	/* CTLTYPE_UINT */
 	sizeof(long),		/* CTLTYPE_LONG */
@@ -329,7 +329,7 @@ PyFB_sysctl(PyObject *self, PyObject *ar
 	case CTLTYPE_UINT:
 	case CTLTYPE_LONG:
 	case CTLTYPE_ULONG:
-	case CTLTYPE_QUAD:
+	case CTLTYPE_S64:
 		if (!PyInt_Check(newobj) && !PyLong_Check(newobj)) {
 			PyErr_SetString(PyExc_TypeError,
 				"argument 2 must be integer for this node");
@@ -350,7 +350,7 @@ PyFB_sysctl(PyObject *self, PyObject *ar
 		case CTLTYPE_ULONG:
 			val.m_ulong = PyLong_AsUnsignedLong(newobj);
 			break;
-		case CTLTYPE_QUAD:
+		case CTLTYPE_S64:
 			val.m_quad = (quad_t)PyLong_AsLongLong(newobj);
 			break;
 		}
@@ -439,7 +439,7 @@ PyFB_sysctl(PyObject *self, PyObject *ar
 	case CTLTYPE_STRING:
 		ret = PyString_FromStringAndSize(oldp, oldlen - 1);
 		break;
-	case CTLTYPE_QUAD:
+	case CTLTYPE_S64:
 		assert(oldlen == sizeof(quad_t));
 		ret = PyLong_FromLongLong((long long)*(quad_t *)oldp);
 		break;
