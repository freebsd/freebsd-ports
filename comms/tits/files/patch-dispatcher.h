
$FreeBSD$

--- dispatcher.h	2001/04/18 14:50:37	1.1
+++ dispatcher.h	2001/04/18 14:51:57
@@ -43,4 +43,8 @@
 extern void	dispatcher_del_client(struct client_ctx *);
 extern int	dispatcher_mainloop(void);
 
+#ifdef __FreeBSD__
+typedef unsigned int nfds_t;
+#endif
+
 #endif /* __dispatcher_h */
