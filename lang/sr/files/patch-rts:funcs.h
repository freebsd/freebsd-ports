--- rts/funcs.h.orig	Sat Dec 13 19:48:15 2003
+++ rts/funcs.h	Sat Dec 13 19:51:42 2003
@@ -6,7 +6,7 @@
 extern	char*	sr_fmt_locn ();
 extern	void	sr_malf ();
 extern	void	sr_message ();
-extern	int	sr_runerr ();
+extern	int	sr_runerr (char *locn, ...);
 extern	void	sr_net_abort ();
 extern	void	sr_stk_corrupted ();
 extern	void	sr_stk_overflow ();
@@ -30,8 +30,8 @@
 extern	Array*	sr_aswap ();
 extern	String*	sr_chgstr ();
 extern	Ptr	sr_clone ();
-extern	Array*	sr_init_array ();
-extern	Ptr	sr_slice ();
+extern	Array*	sr_init_array (char *locn, Array *addr, ...);
+extern	Ptr	sr_slice (char *locn, ...);
 extern	Ptr	sr_sslice ();
 extern	Array*	sr_strarr ();
 
@@ -97,8 +97,8 @@
 extern	int	sr_inchar ();
 extern	void	sr_init_io ();
 extern	File	sr_open ();
-extern	void	sr_printf ();
-extern	int	sr_read ();
+extern	void	sr_printf (char *locn, ...);
+extern	int	sr_read (char *locn, ...);
 extern	Bool	sr_remove ();
 extern	int	sr_seek ();
 extern	int	sr_where ();
@@ -111,14 +111,14 @@
 extern	void	sr_rm_iop ();
 
 /* math.c */
-extern	int	sr_imax ();
-extern	int	sr_imin ();
+extern	int	sr_imax (int n, ...);
+extern	int	sr_imin (int n, ...);
 extern	int	sr_imod ();
 extern	void	sr_init_random ();
 extern	int	sr_itoi ();
 extern	Real	sr_random ();
-extern	Real	sr_rmax ();
-extern	Real	sr_rmin ();
+extern	Real	sr_rmax (int n, ...);
+extern	Real	sr_rmin (int n, ...);
 extern	Real	sr_rmod ();
 extern	Real	sr_round ();
 extern	Real	sr_rtoi ();
@@ -134,7 +134,7 @@
 extern	int	sr_arg_ptr ();
 extern	int	sr_arg_real ();
 extern	int	sr_arg_string ();
-extern	Ptr	sr_cat ();
+extern	Ptr	sr_cat (String *a, ...);
 extern	void	sr_dispose ();
 extern	Ptr	sr_gswap ();
 extern	void	sr_init_misc ();
@@ -210,7 +210,7 @@
 extern	Ptr	sr_literal_rcap ();
 
 /* scan.c */
-extern	int	sr_scanf ();
+extern	int	sr_scanf (char *locn, ...);
 
 /* semaphore.c */
 extern	void	P ();
