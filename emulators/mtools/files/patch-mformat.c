--- mformat.c~	Sat May 27 07:09:45 2006
+++ mformat.c	Sat May 27 07:24:05 2006
@@ -689,6 +689,7 @@
 	exit(1);
 }
 
+#ifdef OS_linux
 static int get_block_geom(int fd, struct MT_STAT *buf, struct device *dev,
 			  char *errmsg) {
 	struct hd_geometry geom;
@@ -733,6 +734,7 @@
 	size = dev->tracks * dev->heads * dev->sectors + dev->hidden;
 	return 0;
 }
+#endif
 
 void mformat(int argc, char **argv, int dummy)
 {
