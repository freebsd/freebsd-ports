--- cligen_getline.h.orig	2020-10-18 14:29:28 UTC
+++ cligen_getline.h
@@ -48,11 +48,11 @@ void	gl_redraw(cligen_handle h);	/* issue \n and redra
 int     gl_regfd(int, cligen_fd_cb_t *, void *);
 int     gl_unregfd(int);
 
-int 	(*gl_in_hook)(void *, char *);
-int 	(*gl_out_hook)(void*, char *);
-int	(*gl_tab_hook)(cligen_handle, int *);
-cligen_susp_cb_t *gl_susp_hook;
-cligen_interrupt_cb_t *gl_interrupt_hook;
-int	(*gl_qmark_hook)(cligen_handle, char *);
+extern int 	(*gl_in_hook)(void *, char *);
+extern int 	(*gl_out_hook)(void*, char *);
+extern int	(*gl_tab_hook)(cligen_handle, int *);
+extern cligen_susp_cb_t *gl_susp_hook;
+extern cligen_interrupt_cb_t *gl_interrupt_hook;
+extern int	(*gl_qmark_hook)(cligen_handle, char *);
 
 #endif /* CLIGEN_GETLINE_H */
