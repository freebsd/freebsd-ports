--- qcc.c.orig	2012-01-31 16:40:51.000000000 +0800
+++ qcc.c	2012-01-31 16:41:46.000000000 +0800
@@ -1025,7 +1025,7 @@
 main
 ============
 */
-void main (int argc, char **argv)
+int main (int argc, char **argv)
 {
 	char	*src;
 	char	*src2;
@@ -1043,7 +1043,7 @@
 		printf ("to build a clean data tree: qcc -copy <srcdir> <destdir>\n");
 		printf ("to build a clean pak file: qcc -pak <srcdir> <packfile>\n");
 		printf ("to bsp all bmodels: qcc -bspmodels <gamedir>\n");
-		return;
+		return EXIT_SUCCESS;
 	}
 	
 	p = CheckParm ("-src");
@@ -1112,4 +1112,6 @@
 
 // report / copy the data files
 	CopyFiles ();
+
+	return EXIT_SUCCESS;
 }
