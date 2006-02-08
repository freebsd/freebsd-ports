--- libdesklets/system/gtop.c.orig	Sat Jan  1 20:33:47 2005
+++ libdesklets/system/gtop.c	Thu Feb 17 21:53:53 2005
@@ -48,6 +48,8 @@
 #include <sys/socket.h>
 #include <arpa/inet.h>
 
+/* for INET_ADDRSTRLEN and INET6_ADDRSTRLEN on FreeBSD 4 */
+#include <netinet/in.h>
 
 typedef struct
 {
@@ -1275,8 +1277,8 @@
         tuple = PyTuple_New(len);

         for(i = 0; i < len; ++i) {
-            p = &glibtop_sys_siglist[i];
             PyObject* d;
+            p = &glibtop_sys_siglist[i];

             d = PyDict_New();
             my_dict_add_and_decref(d, "number", PyI_L(p->number));
