Obtained from:	https://github.com/json-c/json-c/commit/31243e4d1204ef78be34b0fcae73221eee6b83be

--- printbuf.c.orig	2020-04-19 03:36:00 UTC
+++ printbuf.c
@@ -15,6 +15,7 @@
 
 #include "config.h"
 
+#include <limits.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
@@ -65,10 +66,16 @@ static int printbuf_extend(struct printbuf *p, int min
 
 	if (p->size >= min_size)
 		return 0;
-
-	new_size = p->size * 2;
-	if (new_size < min_size + 8)
+	/* Prevent signed integer overflows with large buffers. */
+	if (min_size > INT_MAX - 8)
+		return -1;
+	if (p->size > INT_MAX / 2)
 		new_size = min_size + 8;
+	else {
+		new_size = p->size * 2;
+		if (new_size < min_size + 8)
+			new_size = min_size + 8;
+	}
 #ifdef PRINTBUF_DEBUG
 	MC_DEBUG("printbuf_memappend: realloc "
 	         "bpos=%d min_size=%d old_size=%d new_size=%d\n",
@@ -83,6 +90,9 @@ static int printbuf_extend(struct printbuf *p, int min
 
 int printbuf_memappend(struct printbuf *p, const char *buf, int size)
 {
+	/* Prevent signed integer overflows with large buffers. */
+	if (size > INT_MAX - p->bpos - 1)
+		return -1;
 	if (p->size <= p->bpos + size + 1)
 	{
 		if (printbuf_extend(p, p->bpos + size + 1) < 0)
@@ -100,6 +110,9 @@ int printbuf_memset(struct printbuf *pb, int offset, i
 
 	if (offset == -1)
 		offset = pb->bpos;
+	/* Prevent signed integer overflows with large buffers. */
+	if (len > INT_MAX - offset)
+		return -1;
 	size_needed = offset + len;
 	if (pb->size < size_needed)
 	{
