--- src/glbind.c.orig	Wed May  4 18:45:48 2005
+++ src/glbind.c	Wed May  4 18:46:20 2005
@@ -2147,8 +2147,6 @@
     TCL_CHECK(Tcl_GetIntFromObj(interp, objv[2], &i), ERROR);
     GL_CHECK(glLightModeli (pname, i));
     return 3;
-
-  default:
   }
 
 ERROR:
@@ -2886,8 +2884,6 @@
     }
     GL_CHECK(glTexEnvfv (GL_TEXTURE_ENV, pname, param));
     return 6;
-
-  default:
   }
 
 ERROR:
@@ -3078,8 +3074,6 @@
     param[0] = d;
     GL_CHECK(glTexParameterf (target, pname, param[0]));
     return 4;
-
-  default:
   }
 
 ERROR:
