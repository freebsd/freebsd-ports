
$FreeBSD$

--- src/music.c	2002/05/09 21:56:01	1.1
+++ src/music.c	2002/05/09 21:56:51
@@ -148,7 +148,7 @@
     /*DOC*/    "Temporarily stops the current music.\n"
     /*DOC*/ ;
 
-static PyObject* pause(PyObject* self, PyObject* args)
+static PyObject* music_pause(PyObject* self, PyObject* args)
 {
 	if(!PyArg_ParseTuple(args, ""))
 		return NULL;
@@ -365,7 +365,7 @@
 	{ "get_busy", get_busy, 1, doc_get_busy },
 	{ "fadeout", fadeout, 1, doc_fadeout },
 	{ "stop", stop, 1, doc_stop },
-	{ "pause", pause, 1, doc_pause },
+	{ "pause", music_pause, 1, doc_pause },
 	{ "unpause", unpause, 1, doc_unpause },
 	{ "rewind", mus_rewind, 1, doc_rewind },
 	{ "set_volume", set_volume, 1, doc_set_volume },
