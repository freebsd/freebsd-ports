
$FreeBSD$

--- src/mixer.c	2002/05/09 21:53:08	1.1
+++ src/mixer.c	2002/05/09 21:55:19
@@ -926,7 +926,7 @@
     /*DOC*/    "Temporarily stops playback on all the mixer channels.\n"
     /*DOC*/ ;
 
-static PyObject* pause(PyObject* self, PyObject* args)
+static PyObject* all_pause(PyObject* self, PyObject* args)
 {
 	if(!PyArg_ParseTuple(args, ""))
 		return NULL;
@@ -1029,7 +1029,7 @@
 	{ "find_channel", find_channel, 1, doc_find_channel },
 	{ "fadeout", fadeout, 1, doc_fadeout },
 	{ "stop", stop, 1, doc_stop },
-	{ "pause", pause, 1, doc_pause },
+	{ "pause", all_pause, 1, doc_pause },
 	{ "unpause", unpause, 1, doc_unpause },
 /*	{ "lookup_frequency", lookup_frequency, 1, doc_lookup_frequency },*/
 
