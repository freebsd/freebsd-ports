--- src/netstat.c.orig	Sun Dec  5 10:58:17 2004
+++ src/netstat.c	Sun Dec  5 10:55:25 2004
@@ -71,7 +71,7 @@
     size_t len = sizeof ipstat; 
     PyObject *r, *t;
 
-    if (sysctlbyname("net.inet.ip.stats", &ipstat, &len, NULL, NULL) < 0) {
+    if (sysctlbyname("net.inet.ip.stats", &ipstat, &len, NULL, 0) < 0) {
         PyErr_SetFromErrno(PyExc_OSError);
         return Py_None;
     }
@@ -114,7 +114,7 @@
     size_t len = sizeof tcpstat; 
     PyObject *r, *t;
 
-    if (sysctlbyname("net.inet.tcp.stats", &tcpstat, &len, NULL, NULL) < 0) {
+    if (sysctlbyname("net.inet.tcp.stats", &tcpstat, &len, NULL, 0) < 0) {
         PyErr_SetFromErrno(PyExc_OSError);
         return Py_None;
     }
@@ -166,7 +166,7 @@
     size_t len = sizeof udpstat; 
     PyObject *r, *t;
 
-    if (sysctlbyname("net.inet.udp.stats", &udpstat, &len, NULL, NULL) < 0) {
+    if (sysctlbyname("net.inet.udp.stats", &udpstat, &len, NULL, 0) < 0) {
         PyErr_SetFromErrno(PyExc_OSError);
         return Py_None;
     }
@@ -218,7 +218,7 @@
     PyObject *r, *d, *t;
 
     len = sizeof value;
-    if (sysctlbyname("net.link.generic.system.ifcount", &value, &len, NULL, NULL) < 0) {
+    if (sysctlbyname("net.link.generic.system.ifcount", &value, &len, NULL, 0) < 0) {
         PyErr_SetFromErrno(PyExc_OSError);
         return Py_None;
     }
@@ -263,8 +263,7 @@
         p_long(ibytes);     p_long(obytes);
         p_long(imcasts);    p_long(omcasts);
         p_long(iqdrops);    p_long(noproto);
-        p_long(hwassist);   p_long(unused);
-#undef p, p_long, p_str, p_int
+#undef p
 
         PyDict_SetItemString(r, ifmd.ifmd_name, d);
         Py_DECREF(d);
