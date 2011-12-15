--- src/packet.c.orig	2011-12-14 22:00:49.000000000 +0100
+++ src/packet.c	2011-12-14 22:00:53.000000000 +0100
@@ -1747,24 +1747,22 @@
 	int i, j, err = 0;
 
 	/* XXX nested function not portable, to be removed */
-	int
-	bits(int count)
-	{
-		int r, n;
-
-		r = buf;
-
-		if ((n = count - left) > 0) {
-			r |= (buf = *triplet++) << left;
-			left = 18;
-		} else
-			n = count;
-
-		buf >>= n;
-		left -= n;
-
-		return r & ((1UL << count) - 1);
-	}
+#define  bits(count) 	({               \
+		int r, n;               \
+                                        \
+		r = buf;                \
+                                        \
+		if ((n = count - left) > 0) {   \
+			r |= (buf = *triplet++) << left;        \
+			left = 18;      \
+		} else                  \
+			n = count;      \
+                                        \
+		buf >>= n;              \
+		left -= n;              \
+                                        \
+		(r & ((1UL << count) - 1)); \
+	})
 
 	if ((designation = vbi_unham8 (*p)) < 0)
 		return FALSE;
