--- bubbob/statesaver.c.orig
+++ bubbob/statesaver.c
@@ -75,10 +75,12 @@
     Py_INCREF(g);  /* exhausted -- can return 'g' itself */
     return g;
   }
+#if PY_VERSION_HEX < 0x02050000
   if (f->f_nfreevars || f->f_ncells) {
     PyErr_SetString(PyExc_ValueError, "generator has cell or free vars");
     goto error;
   }
+#endif
 
   if (co->co_argcount == 0)
     dummy = NULL;
@@ -143,10 +145,12 @@
       }
       f2 = (PyFrameObject*) x;
 
+#if PY_VERSION_HEX < 0x02050000
       if (f2->f_stacksize != f->f_stacksize) {
         PyErr_SetString(PyExc_TypeError, "stack size mismatch");
         goto error;
       }
+#endif
 
       if (f2->f_stacktop != NULL)
         while (f2->f_stacktop != f2->f_localsplus)
