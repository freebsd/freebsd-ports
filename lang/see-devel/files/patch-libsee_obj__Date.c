--- libsee/obj_Date.c.orig	Sun May  7 06:43:55 2006
+++ libsee/obj_Date.c	Tue Sep  5 09:11:09 2006
@@ -335,7 +335,7 @@
 	struct SEE_interpreter *interp;
 	SEE_number_t t;
 {
-	return t + LocalTZA(interp) + DaylightSavingTA(interp, t);
+	return t + LocalTZA(interp) - DaylightSavingTA(interp, t);
 }
 
 /*
