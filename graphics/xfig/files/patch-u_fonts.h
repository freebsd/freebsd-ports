I attached patch file, and that patch file can works with both ports xfig,

xfig-devel.


Patch attached with submission follows:

--- u_fonts.h.orig	Fri May 25 21:39:29 2007
+++ u_fonts.h	Fri May 25 21:40:07 2007
@@ -32,9 +32,6 @@
 
 extern int		psfontnum();
 extern int		latexfontnum();
-extern struct _xfstruct	x_fontinfo[], x_backup_fontinfo[];
-extern struct _fstruct	ps_fontinfo[];
-extern struct _fstruct	latex_fontinfo[];
 
 /* element of linked list for each font
    The head of list is for the different font NAMES,
@@ -60,6 +57,10 @@
     struct xfont   *xfontlist;	/* linked list of X fonts for different point
 				 * sizes */
 };
+
+extern struct _xfstruct	x_fontinfo[], x_backup_fontinfo[];
+extern struct _fstruct	ps_fontinfo[];
+extern struct _fstruct	latex_fontinfo[];
 
 int		x_fontnum();
 #endif /* U_FONTS_H */


