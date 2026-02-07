Index: Wnn/etc/bcopy.c
===================================================================
RCS file: /home/cvs/private/hrs/freewnn/Wnn/etc/bcopy.c,v
retrieving revision 1.1.1.1
retrieving revision 1.2
diff -u -p -r1.1.1.1 -r1.2
--- Wnn/etc/bcopy.c	20 Dec 2008 07:13:30 -0000	1.1.1.1
+++ Wnn/etc/bcopy.c	20 Dec 2008 15:22:40 -0000	1.2
@@ -38,47 +38,43 @@
 
 #ifndef HAVE_BCOPY
 void
-bcopy (b1, b2, length)
-     unsigned char *b1, *b2;
-     int length;
+bcopy(unsigned char *b1,
+      unsigned char *b2,
+      int length)
 {
-  if (length <= 0)
-    return;
-  if (b1 < b2 && b1 + length > b2)
-    {
-      b2 += length;
-      b1 += length;
-      while (length--)
-        {
-          *--b2 = *--b1;
-        }
-    }
-  else
-    {
-      memcpy (b2, b1, length);
-    }
+	if (length <= 0)
+		return;
+
+	if (b1 < b2 && b1 + length > b2) {
+		b2 += length;
+		b1 += length;
+
+		while (length--)
+			*--b2 = *--b1;
+	} else {
+		memcpy (b2, b1, length);
+	}
 }
 #endif /* !HAVE_BCOPY */
 
 #ifndef HAVE_BZERO
 void
-bzero (b, length)
-     unsigned char *b;
-     int length;
+bzero(unsigned char *b,
+      int length)
 {
-  memset (b, 0, length);
+	memset (b, 0, length);
 }
 #endif /* !HAVE_BZERO */
 
 #ifndef HAVE_BCMP
 int
-bcmp (b1, b2, length)
-     unsigned char *b1;
-     unsigned char *b2;
-     int length;
+bcmp(unsigned char *b1,
+     unsigned *b2,
+     int length)
 {
-  if (length == 0)
-    return 0;
-  return memcmp (b1, b2, length);
+	if (length == 0)
+		return 0;
+
+	return memcmp(b1, b2, length);
 }
 #endif /* !HAVE_BCMP */
