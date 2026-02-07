--- pygraphviz/graphviz_wrap.c.orig	2020-08-05 09:03:40 UTC
+++ pygraphviz/graphviz_wrap.c
@@ -3030,7 +3030,7 @@ SWIG_FromCharPtr(const char *cptr)
 }
   
 
-  int agattr_label(Agraph_t *g, int kind, char *name, char *val)
+  Agsym_t *agattr_label(Agraph_t *g, int kind, char *name, char *val)
 {
     int len;
     char *hs;
@@ -4364,7 +4364,7 @@ SWIGINTERN PyObject *_wrap_agattr_label(PyObject *SWIG
   char *buf4 = 0 ;
   int alloc4 = 0 ;
   PyObject *swig_obj[4] ;
-  int result;
+  Agsym_t *result = 0 ;
   
   if (!SWIG_Python_UnpackTuple(args, "agattr_label", 4, 4, swig_obj)) SWIG_fail;
   res1 = SWIG_ConvertPtr(swig_obj[0], &argp1,SWIGTYPE_p_Agraph_t, 0 |  0 );
@@ -4388,13 +4388,13 @@ SWIGINTERN PyObject *_wrap_agattr_label(PyObject *SWIG
   }
   arg4 = (char *)(buf4);
   {
-    result = (int)agattr_label(arg1,arg2,arg3,arg4);
+    result = (Agsym_t *)agattr_label(arg1,arg2,arg3,arg4);
     if (!result) {
       PyErr_SetString(PyExc_KeyError,"agattr_label: no key");
       return NULL;
     }
   }
-  resultobj = SWIG_From_int((int)(result));
+  resultobj = SWIG_NewPointerObj(SWIG_as_voidptr(result), SWIGTYPE_p_Agsym_t, 0 |  0 );
   if (alloc3 == SWIG_NEWOBJ) free((char*)buf3);
   if (alloc4 == SWIG_NEWOBJ) free((char*)buf4);
   return resultobj;
