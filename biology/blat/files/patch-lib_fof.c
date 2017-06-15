--- lib/fof.c.orig	2014-11-06 03:15:59 UTC
+++ lib/fof.c
@@ -336,7 +336,11 @@ static int cmpOnFilePos(const void *va, 
 {
 const struct fofBatch *a = *((struct fofBatch **)va);
 const struct fofBatch *b = *((struct fofBatch **)vb);
+#ifdef __DragonFly__
+int dif = (struct __FILE_public*)a->f - (struct __FILE_public*)b->f;
+#else
 int dif = a->f - b->f;
+#endif
 if (dif == 0)
     dif = a->offset - b->offset;
 return dif;
