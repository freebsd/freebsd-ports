
$FreeBSD$

--- dlhack.c
+++ dlhack.c
@@ -1,5 +1,6 @@
 #include <Python.h>
 #include <dlfcn.h>
+#include <unistd.h>
 
 /* This is a fake perl module that will look for the real thing ('perl2.so')
  * in sys.path and then load this one with the RTLD_GLOBAL set in order to
@@ -33,6 +34,8 @@
 	if (strlen(buf) != len)
 	    continue; /* v contains '\0' */
 	strcpy(buf+len, "/perl2.so");
+	if (access(buf, R_OK) == -1)
+	    continue;
 
 	handle = dlopen(buf, RTLD_NOW | RTLD_GLOBAL);
 	if (handle) {
@@ -45,6 +48,7 @@
 	    }
 	    return;
 	}
+	break;
     }
-    PyErr_SetString(PyExc_ImportError, "perl2.so not found");
+    PyErr_SetString(PyExc_ImportError, dlerror());
 }
