--- src/themerc.c.orig	Fri Oct 25 23:11:17 2002
+++ src/themerc.c	Fri Oct 25 23:11:20 2002
@@ -18,31 +18,31 @@
         gchar *rc,**rcs;
 
         if((fd=open(fname, O_RDONLY))==-1) {
-                fprintf(stderr, __func__ ": open() %s failed: %s\n", fname, strerror(errno));
+                fprintf(stderr, "%s: open() %s failed: %s\n", __FUNCTION__, fname, strerror(errno));
                 return NULL;
         }
         if((fstat(fd, &fds))==-1) {
                 close(fd);
-                fprintf(stderr, __func__ ": fstat() failed: %s\n", strerror(errno));
+                fprintf(stderr, "%s: fstat() failed: %s\n", __FUNCTION__, strerror(errno));
                 return NULL;
         }
         if(!(fds.st_size)) {
                 close(fd);
-                fprintf(stderr, __func__ ": zero length file.\n");
+                fprintf(stderr, "%s: zero length file.\n", __FUNCTION__);
                 return NULL;
         }
         if(!(rc=malloc(fds.st_size+1))) {
                 close(fd);
-                fprintf(stderr, __func__ ": malloc() failed: cannot alloc %d bytes\n", (int)fds.st_size);
+                fprintf(stderr, "%s: malloc() failed: cannot alloc %d bytes\n", __FUNCTION__, (int)fds.st_size);
                 return NULL;
         }
         if((rb=read(fd, rc, fds.st_size))!=fds.st_size) {
                 free(rc);
                 close(fd);
                 if(rb==-1) {
-                	fprintf(stderr, __func__ ": read() failed: %s\n", strerror(errno));
+                	fprintf(stderr, "%s: read() failed: %s\n", __FUNCTION__, strerror(errno));
                 } else {
-                	fprintf(stderr, __func__ ": read() reads less bytes than expected =/\n");
+                	fprintf(stderr, "%s: read() reads less bytes than expected =/\n", __FUNCTION__);
                 }
                 return NULL;
         }
@@ -66,11 +66,11 @@
         gchar **strval,*val;
 
         if(!rcs) {
-        	fprintf(stderr, __func__ " called with uninitialised rcs. strange. \n");
+        	fprintf(stderr, "%s called with uninitialised rcs. strange. \n", __FUNCTION__);
 		return NULL;
         }
         if(!param) {
-        	fprintf(stderr, __func__ " called with NULL param. strange. \n");
+        	fprintf(stderr, "%s called with NULL param. strange. \n", __FUNCTION__);
 		return NULL;
         }
         for(i=0;rcs[i];i++) {
