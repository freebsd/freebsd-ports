--- socket.c.orig	2009-03-03 18:05:10.000000000 +0200
+++ socket.c	2009-03-03 18:07:34.000000000 +0200
@@ -25,6 +25,7 @@
 
 #define SCM_SOCKETP(x)	(SCM_OBJTYPE(x) == SOBJ_T_SOCKET)
 #define SCM_SOCKET(x)	((SCM_SocketAux*)SCM_AUX(x))
+#define SCM_SOCKET_SET	SCM_AUX_SET
 
 /* report system error */
 static void system_error(char *msg)
@@ -39,7 +40,8 @@
 {
   SOBJ new;
   new = scm_newcell(SOBJ_T_SOCKET);
-  SCM_SOCKET(new) = scm_must_alloc(sizeof(SCM_SocketAux));
+  /*SCM_SOCKET(new) = scm_must_alloc(sizeof(SCM_SocketAux));*/
+  SCM_SOCKET_SET(new, scm_must_alloc(sizeof(SCM_SocketAux)));
   memset(SCM_SOCKET(new), 0, sizeof(SCM_SocketAux));
   return(new);
 }
@@ -323,7 +325,8 @@
 	/*	scm_puts("; sweeping socket "); scm_cprint(x); */
 	scm_socket_shutdown2(x, 1);
 	scm_free(SCM_SOCKET(x));
-	SCM_SOCKET(x) = NULL;
+	/*SCM_SOCKET(x) = NULL;*/
+	SCM_SOCKET_SET(x, NULL);
   }
 }
 
