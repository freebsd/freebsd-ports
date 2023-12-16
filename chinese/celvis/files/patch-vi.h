--- vi.h.orig	1991-10-21 02:08:33 UTC
+++ vi.h
@@ -101,7 +101,7 @@ extern struct _viflags
 #define READONLY	0x0002	/* the file is read-only */
 #define HADNUL		0x0004	/* the file contained NUL characters */
 #define MODIFIED	0x0008	/* the file has been modified */
-#define NOFILE		0x0010	/* no name is known for the current text */
+#define NOFILENAME	0x0010	/* no name is known for the current text */
 #define ADDEDNL		0x0020	/* newlines were added to the file */
 
 /* macros used to set/clear/test flags */
