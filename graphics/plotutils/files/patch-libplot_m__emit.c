
$FreeBSD$

--- libplot/m_emit.c.orig	Mon Jun 19 22:02:48 2000
+++ libplot/m_emit.c	Thu Aug  7 11:48:12 2003
@@ -66,7 +66,7 @@
       if (_plotter->meta_portable_output)
 	(*(_plotter->data->outstream)) << ' ' << x;
       else
-	_plotter->data->outstream->write((char *)&x, sizeof(int));
+	_plotter->data->outstream->write((const char *)&x, sizeof(int));
     }
 #endif
 }
@@ -107,7 +107,7 @@
 	  float f;
 	  
 	  f = FROUND(x);
-	  _plotter->data->outstream->write((char *)&f, sizeof(float));
+	  _plotter->data->outstream->write((const char *)&f, sizeof(float));
 	}
     }
 #endif
