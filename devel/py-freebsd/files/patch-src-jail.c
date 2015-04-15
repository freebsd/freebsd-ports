--- src/jail.c.orig	2005-05-08 06:55:00.000000000 +0000
+++ src/jail.c	2008-12-23 13:54:31.000000000 +0000
@@ -40,21 +40,37 @@ static PyObject *
 PyFB_jail(PyObject *self, PyObject *args)
 {
 	struct jail jp;
+	struct in_addr ia;
 	char *ipaddr;
+	int error;
 
 	if (!PyArg_ParseTuple(args, "sss:jail", &(jp.path),
 			      &(jp.hostname), &ipaddr))
 		return NULL;
 
-	jp.version   = 0;
-	jp.ip_number = inet_addr(ipaddr);
-
-	if (jp.ip_number == INADDR_NONE) {
+	ia.s_addr	= inet_addr(ipaddr);
+	if (ia.s_addr == INADDR_NONE) {
 		PyErr_SetString(PyExc_ValueError, "malformed internet address");
 		return NULL;
 	}
 
-	if (jail(&jp) == -1)
+	jp.version	= JAIL_API_VERSION;
+	jp.jailname	= NULL;
+	jp.ip4s		= 1;
+	jp.ip4		= malloc(jp.ip4s * sizeof(struct in_addr));
+	if (jp.ip4 == NULL) {
+		PyErr_SetString(PyExc_ValueError, "Cannot allocate memory");
+		return NULL;
+	}
+	jp.ip4->s_addr = ia.s_addr;
+	jp.ip6s		= 0;
+	jp.ip6		= NULL;
+
+	error = jail(&jp);
+
+	free(jp.ip4);
+
+	if (error == -1)
 		return OSERROR();
 
 	Py_RETURN_NONE;
