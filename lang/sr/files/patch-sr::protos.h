--- sr/protos.h.orig	Sat Dec 13 19:36:36 2003
+++ sr/protos.h	Sat Dec 13 19:36:45 2003
@@ -147,7 +147,7 @@
 extern	void	copen		PARAMS ((char *fname));
 extern	void	cdivert		PARAMS ((int n));
 extern	void	undivert	PARAMS ((int n));
-extern	void	cprintf		PARAMS ((/* VARARGS */));
+extern	void	cprintf		PARAMS ((char *fmt, ...));
 extern	void	cflush		PARAMS (());
 extern	void	cclose		PARAMS ((NOARGS));	
 extern	void	setstream	PARAMS ((int n));
