Obtained from:	https://github.com/mcfletch/simpleparse/commit/dc6dc546f03397fe9a906500cf7560e223b1b8ee

--- simpleparse/stt/TextTools/mxTextTools/mxTextTools.c.orig	2020-02-17 16:02:36 UTC
+++ simpleparse/stt/TextTools/mxTextTools/mxTextTools.c
@@ -2835,7 +2835,7 @@ PyObject *mxTextTools_UnicodeJoin(PyObject *seq,
 
 	o = PySequence_GetItem(seq, i);
 
-	if PyTuple_Check(o) {
+	if (PyTuple_Check(o)) {
 	    /* Tuple entry: (string,l,r,[...]) */
 	    register Py_ssize_t l,r;
 
@@ -2980,7 +2980,7 @@ PyObject *mxTextTools_Join(PyObject *seq,
 
 	o = PySequence_GetItem(seq, i);
 
-	if PyTuple_Check(o) {
+	if (PyTuple_Check(o)) {
 	    /* Tuple entry: (string,l,r,[...]) */
 	    register Py_ssize_t l,r;
 
