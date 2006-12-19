--- ftp_var.h.orig	Thu Jul 25 16:49:16 2002
+++ ftp_var.h	Mon Dec 18 23:27:38 2006
@@ -65,6 +65,9 @@
  *	@(#)ftp_var.h	8.4 (Berkeley) 10/9/94
  */
 
+#ifndef __FTP_VAR_H
+#define __FTP_VAR_H
+
 /*
  * FTP global variables.
  */
@@ -86,6 +89,22 @@
 #endif
 
 #include "stringlist.h"
+
+/*
+ * Format of command table.
+ */
+struct cmd {
+	char	*c_name;	/* name of command */
+	char	*c_help;	/* help string */
+	char	 c_bell;	/* give bell when command completes */
+	char	 c_conn;	/* must be connected to use command */
+	char	 c_proxy;	/* proxy server may execute */
+#ifndef SMALL
+	char	*c_complete;	/* context sensitive completion list */
+#endif /* !SMALL */
+	void	(*c_handler) __P((int, char **)); /* function to call */
+};
+
 #include "extern.h"
 
 #define HASHBYTES	1024
@@ -195,21 +214,6 @@
 
 int	options;		/* used during socket creation */
 
-/*
- * Format of command table.
- */
-struct cmd {
-	char	*c_name;	/* name of command */
-	char	*c_help;	/* help string */
-	char	 c_bell;	/* give bell when command completes */
-	char	 c_conn;	/* must be connected to use command */
-	char	 c_proxy;	/* proxy server may execute */
-#ifndef SMALL
-	char	*c_complete;	/* context sensitive completion list */
-#endif /* !SMALL */
-	void	(*c_handler) __P((int, char **)); /* function to call */
-};
-
 struct macel {
 	char mac_name[9];	/* macro name */
 	char *mac_start;	/* start of macro in macbuf */
@@ -224,3 +228,5 @@
 
 /* sig_t isn't what we expect on all platforms so we use a custom one */
 typedef void (*my_sig_t)__P((int));
+
+#endif
