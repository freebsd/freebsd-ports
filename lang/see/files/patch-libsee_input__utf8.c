--- libsee/input_utf8.c.orig	Wed Jan 18 12:40:19 2006
+++ libsee/input_utf8.c	Tue Dec 12 08:48:44 2006
@@ -63,7 +63,7 @@
 
 struct input_utf8 {
 	struct SEE_input	inp;
-	const char *	s;
+	const unsigned char *	s;
 };
 
 static SEE_unicode_t
@@ -141,7 +141,7 @@
 	inpu->inp.inputclass = &input_utf8_class;
 	inpu->inp.filename = NULL;
 	inpu->inp.first_lineno = 1;
-	inpu->s = s;
+	inpu->s = (const unsigned char *)s;
 	SEE_INPUT_NEXT((struct SEE_input *)inpu);	/* prime */
 	return (struct SEE_input *)inpu;
 }
