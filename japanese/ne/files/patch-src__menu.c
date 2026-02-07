--- src/menu.c.orig
+++ src/menu.c
@@ -105,14 +105,14 @@
 	va_list 	args;
 	char	*p;
 
-	args=*(va_list *)vp;
+	va_copy(args, *(va_list *)vp);
 
 	p=va_arg(args, char *);
 	if (p==NULL)
 		strcpy(mip->str,"null"); else
 		strcpy(mip->str,p);
 
-	*(va_list *)vp=args;
+	va_copy(*(va_list *)vp, args);
 }
 
 
