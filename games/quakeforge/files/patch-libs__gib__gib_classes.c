--- ./libs/gib/gib_classes.c.orig	Fri Nov 28 23:01:31 2003
+++ ./libs/gib/gib_classes.c	Sun Dec 17 15:56:41 2006
@@ -192,7 +192,7 @@
 	unsigned int size;
 	unsigned int i = 0;
 	
-	static qboolean
+	qboolean
 	iterator (gib_class_t *class, void *unused)
 	{
 		reply[i++] = class->name;
@@ -610,13 +610,13 @@
 	gib_classdesc_t desc;
 	enum {CLASS, INSTANCE} mode = INSTANCE;
 	
-	static void
+	void
 	mtabfree (void *mtab, void *unused)
 	{
 		free (mtab);
 	}
 
-	static const char *
+	const char *
 	fname (const char *str)
 	{
 		if (mode == INSTANCE)
