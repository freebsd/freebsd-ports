--- sem_stubs.c.orig	Tue Apr 19 16:20:34 2005
+++ sem_stubs.c	Sat Apr 23 14:18:56 2005
@@ -137,12 +137,14 @@
 };
 
 value stub_sem_getvalue(value sem) {
+	int * vp;
+
 	CAMLparam1(sem);
 	CAMLlocal2(estr, v);
 
 	estr = copy_string("");
 
-	int * vp = calloc(1, sizeof(int));
+	vp = calloc(1, sizeof(int));
 	if (sem_getvalue((sem_t *)sem,vp) == -1) {
 		uerror("sem_getvalue", estr);
 	};
