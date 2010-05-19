--- proto.h.orig	2003/10/26 11:34:23	1.5
+++ proto.h	2007/11/06 23:07:52	1.5.22.1
@@ -112,6 +112,7 @@ extern	double	getfval(Cell *);
 extern	char	*getsval(Cell *);
 extern	char	*getpssval(Cell *);     /* for print */
 extern	char	*tostring(const char *);
+extern	char	*tostringN(const char *, size_t n);
 extern	char	*qstring(const char *, int);
 
 extern	void	recinit(unsigned int);
