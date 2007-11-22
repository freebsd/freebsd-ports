--- src/dialog.cc.orig	2007-11-21 17:49:38.000000000 +0100
+++ src/dialog.cc	2007-11-21 17:52:11.000000000 +0100
@@ -90,7 +90,7 @@
         {
             s = PyList_GetItem (list, i);
             if (s && PyString_Check (s)) strings[i] = PyString_AsString (s);
-            else strings[i] = "*** Error";
+            else strings[i] = (char *)"*** Error";
         }
 
         Py_DECREF (list);
@@ -157,7 +157,7 @@
     do
     {
         // Execute the next part of the dialogue
-        arg = Py_BuildValue ("(i)", answer);
+        arg = Py_BuildValue ((char *)"(i)", answer);
         
          // run next part of dialogue
         dialogue.run (arg);
@@ -222,7 +222,7 @@
             }
             
             // check whether we shall continue or not
-            arg = Py_BuildValue ("(i)", answer);
+            arg = Py_BuildValue ((char *)"(i)", answer);
             result = dialogue.call_method_ret ("stop", arg);
             stop = PyInt_AsLong (result);
             Py_XDECREF (result);
@@ -298,9 +298,9 @@
             strncpy (str, start+3, end);
 
             if (the_player->storage::get_val ("gender") == FEMALE)
-                mid = get_substr (str, "{", "/");
+                mid = get_substr (str, (char *)"{", (char *)"/");
             else
-                mid = get_substr (str, "/", "}");
+                mid = get_substr (str, (char *)"/", (char *)"}");
 
             begin = newstr.length () - strlen(start);
             tmp = new char[newstr.length () - end + strlen (mid)];
