--- gcc/d/phobos/config/gen_unix.c.orig	Sun Dec  4 17:51:01 2005
+++ gcc/d/phobos/config/gen_unix.c	Sun Dec  4 17:51:42 2005
@@ -115,7 +115,11 @@
 	finish_struct(fi, 2, sizeof(rec), "timezone");
     }
     {
+#ifdef HAVE_TM_GMTOFF_AND_ZONE
+	FieldInfo fi[11];
+#else
 	FieldInfo fi[9];
+#endif
 	unsigned n;
 	struct tm rec;
 	INT_FIELD(fi[0], tm_sec);
