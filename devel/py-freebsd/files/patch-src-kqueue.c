--- src/kqueue.c.orig	2022-01-23 05:12:10 UTC
+++ src/kqueue.c
@@ -245,7 +245,11 @@ static PyTypeObject KEventType = {
 "argument for kqueue.event().";
 
 static PyTypeObject KEventType = {
+#if PY_VERSION_HEX >= 0x030C0000
+	PyVarObject_HEAD_INIT(NULL, 0)
+#else
 	PyObject_HEAD_INIT(NULL)
+#endif
 	.tp_name =	"kevent",
 	.tp_basicsize =	sizeof(keventobject),
 	.tp_dealloc =	(destructor)kevent_dealloc,
@@ -553,7 +557,11 @@ static PyTypeObject KQueueType = {
 "per kqueue.";
 
 static PyTypeObject KQueueType = {
+#if PY_VERSION_HEX >= 0x030C0000
+	PyVarObject_HEAD_INIT(NULL, 0)
+#else
 	PyObject_HEAD_INIT(NULL)
+#endif
 	.tp_name =	"kqueue",
 	.tp_basicsize =	sizeof(kqueueobject),
 	.tp_dealloc =	(destructor)kqueue_dealloc,
