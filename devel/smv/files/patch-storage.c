--- storage.c
+++ storage.c
@@ -9,7 +9,7 @@
 {
 #ifdef MACH
   mach_init();		/* needed to make sbrk() work */
-#endif MACH
+#endif
   /* addrfree points to the first free byte
      addrlimit points to the memory limit */
     addrfree = addrlimit = (char *) sbrk(0);
@@ -34,7 +34,7 @@
 }
 
 /* provide malloc for miscellaneuos storage allocation */
-char *malloc(n)
+char* smv_malloc(n)
 int n;
 {
   if(n % 4)n=n+4-(n%4);  /* always allocate multiple of four bytes */
@@ -47,7 +47,7 @@
 }
 
 /* very simple implementation of free */
-void free(p)
+void smv_free(p)
 char *p;
 {
   return;
@@ -61,7 +61,7 @@
 mgr_ptr new_mgr(rec_size)
 int rec_size;
 {
-  register mgr_ptr mp = (mgr_ptr)malloc(sizeof(struct mgr));
+  register mgr_ptr mp = (mgr_ptr)smv_malloc(sizeof(struct mgr));
   mp->free.link = 0;
   mp->rec_size = rec_size;
   mp->count = 0;
diff -ru ./storage.h /usr3/marc/research/hagen/10-ws0304/77075 Model Checking/praktikum/smv/smv/storage.h
