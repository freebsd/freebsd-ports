--- Pax/paxtkinter.c.orig	Sun May  4 04:55:36 2003
+++ Pax/paxtkinter.c	Mon Apr 18 12:40:08 2005
@@ -1866,6 +1866,9 @@
 	char *className = NULL;
 	int interactive = 0;
 
+	int ignored_int = 0;
+	char *ignored_charp = NULL;
+
 	baseName = strrchr(Py_GetProgramName(), '/');
 	if (baseName != NULL)
 		baseName++;
@@ -1873,9 +1876,10 @@
 		baseName = Py_GetProgramName();
 	className = "Tk";
   
-	if (!PyArg_ParseTuple(args, "|zssi",
+	if (!PyArg_ParseTuple(args, "|zssiiiiz:create",
 			      &screenName, &baseName, &className,
-			      &interactive))
+			      &interactive, &ignored_int, &ignored_int,
+			      &ignored_int, &ignored_charp))
 		return NULL;
 
 	return (PyObject *) Tkapp_New(screenName, baseName, className, 
