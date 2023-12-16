--- python/header-py.c.orig	2023-11-30 19:45:23 UTC
+++ python/header-py.c
@@ -741,7 +741,7 @@
 	0,				/* tp_as_number */
 	&hdr_as_sequence,		/* tp_as_sequence */
 	&hdr_as_mapping,		/* tp_as_mapping */
-	hdr_hash,			/* tp_hash */
+	(hashfunc)hdr_hash,		/* tp_hash */
 	0,				/* tp_call */
 	0,				/* tp_str */
 	(getattrofunc) hdr_getattro,	/* tp_getattro */
