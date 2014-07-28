--- sxsame.c.orig	Sun May  5 04:09:26 1996
+++ sxsame.c	Tue Jul 11 21:35:38 2000
@@ -12,6 +12,11 @@
 char *program_version = "3.02";
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
+#include <time.h>
+#include <string.h>
+#include <sys/param.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #ifndef LOCAL_XPM_H
@@ -163,11 +168,21 @@
 int      hisc_height = 80;
 #endif /* !ENABLE_HISCORE */
 
-
+int ReadInitFile(int* width, int* height, int* same_pic);
+int SaveInitFile(int width, int height, int same_pic);
 int CheckSameDataFile(DataFile ***);
 int LoadBMPSameData(Display *dpy, Colormap cmap, SameGame *, char *);
 int LoadSameData(ImportSameData *, char *);
+int CheckSelectSame(int sx, int sy);
 
+static
+int
+Access(const char* path)
+{
+	return access(path, R_OK);
+}
+
+# define access(x)	Access(x)		
 
 void main(argc, argv)
 int argc;
@@ -726,7 +741,7 @@
 {
 	ImportSameData data;
 	int i, j, val, ncol;
-	char tmpfname[256];
+	char tmpfname[MAXPATHLEN];
 
 	if(strlen(fname)>4) /* check Windows data file... */
 	{
@@ -784,9 +799,13 @@
 			{
 				if(!access(data.xpm_data[i][j]))
 					strcpy(tmpfname,data.xpm_data[i][j]);
-				else
-					sprintf(tmpfname,"%s/%s",same_dir,
-						data.xpm_data[i][j]);
+				else {
+					if (MAXPATHLEN <=
+						snprintf(tmpfname, MAXPATHLEN, "%s/%s",same_dir,
+						data.xpm_data[i][j])) {
+						goto xpm_error;
+					}
+				}
 				val = XpmReadFileToPixmap(dpy, root,
 					tmpfname, &game.bits_xpm[i][j],
 					NULL, &xpm_attr);
@@ -804,7 +823,9 @@
 	if(!access(data.bg_data))
 		strcpy(tmpfname,data.bg_data);
 	else
-		sprintf(tmpfname,"%s/%s",same_dir, data.bg_data);
+		if (MAXPATHLEN <= snprintf(tmpfname, MAXPATHLEN, "%s/%s",same_dir, data.bg_data)) {
+			goto xpm_error;
+		}
 	val = XpmReadFileToPixmap(dpy, root, tmpfname,
 			&game.bg_xpm, NULL, &xpm_attr);
 	free(data.bg_data);
@@ -815,6 +836,10 @@
 		strcpy(tmpfname,data.frame_data);
 	else
 		sprintf(tmpfname,"%s/%s",same_dir, data.frame_data);
+		if (MAXPATHLEN <= snprintf(tmpfname, MAXPATHLEN, "%s/%s",same_dir, data.frame_data)) {
+			
+			goto xpm_error;
+		}
 	val = XpmReadFileToPixmap(dpy, root, tmpfname,
 			&game.frame_xpm, NULL, &xpm_attr);
 	free(data.frame_data);
