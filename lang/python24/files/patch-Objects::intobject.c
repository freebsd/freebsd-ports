diff -u python/dist/src/Objects/intobject.c:2.105 python/dist/src/Objects/intobject.c:2.105.8.1
--- Objects/intobject.c:2.105	Sat Jun 28 13:04:24 2003
+++ Objects/intobject.c	Sun Feb  8 10:56:07 2004
@@ -1080,7 +1080,7 @@
 	int ival;
 #if NSMALLNEGINTS + NSMALLPOSINTS > 0
 	for (ival = -NSMALLNEGINTS; ival < NSMALLPOSINTS; ival++) {
-		if ((free_list = fill_free_list()) == NULL)
+              if (!free_list && (free_list = fill_free_list()) == NULL)
 			return 0;
 		/* PyObject_New is inlined */
 		v = free_list;
