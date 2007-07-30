--- bubbob/statesaver.c.orig	Sun Jul 15 08:59:52 2007
+++ bubbob/statesaver.c	Sun Jul 15 09:01:41 2007
@@ -44,10 +44,12 @@
     Py_INCREF(g);  /* exhausted -- can return 'g' itself */
     return g;
   }
+#if PY_VERSION_HEX < 0x02050000
   if (f->f_nfreevars || f->f_ncells) {
     PyErr_SetString(PyExc_ValueError, "generator has cell or free vars");
     return NULL;
   }
+#endif
 
   dummy = (PyObject**) malloc(co->co_argcount * sizeof(PyObject*));
   if (dummy == NULL)
@@ -95,10 +97,12 @@
         return -1;
       }
       f2 = (PyFrameObject*) x;
+#if PY_VERSION_HEX < 0x02050000
       if (f2->f_stacksize != f->f_stacksize) {
         PyErr_SetString(PyExc_TypeError, "stack size mismatch");
         return -1;
       }
+#endif
 
       if (f2->f_stacktop != NULL)
         while (f2->f_stacktop != f2->f_localsplus)
