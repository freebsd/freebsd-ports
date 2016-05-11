--- src/source.h.orig	1997-06-09 08:02:53 UTC
+++ src/source.h
@@ -8,7 +8,7 @@ extern	const	Byte	*inptr;
 extern	void	init_source(FILE *src, Bool gen_listing);
 extern	void	enterfile(FILE *f);
 extern	Bool	interactive(void);
-extern	Bool	getline(void);
+extern	Bool	get_line(void);
 
 #ifdef	RE_EDIT
 extern	void	set_script(const char *filename);
