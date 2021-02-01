--- xlib/shmbitmap.c.orig	1998-03-04 18:59:19 UTC
+++ xlib/shmbitmap.c
@@ -237,7 +237,7 @@ ShmPutBitmap (int x, int y, int w, int h, void *_dp)
 #define __clipy1 0
 #undef __clipy2
 #define __clipy2 (MAPHEIGHT+19)
-#ifdef __i386__
+#if defined(__i386__)&&defined(ASSEMBLY)
 static INLINE int
 muldiv64 (int CONST m1, int CONST m2, int CONST d)
 {
@@ -333,7 +333,7 @@ Line (int x1, int y1, int x2, int y2, int c)
 	  }
 	if (r1 & 1)
 	  {			/* left */
-#ifdef __i386__
+#if defined(__i386__)&&defined(ASSEMBLY)
 	    y1 += muldiv64 (__clipx1 - x1, y2 - y1, x2 - x1);
 #else
 	    y1 += (long) (__clipx1 - x1) * (long) (y2 - y1) / (long) (x2 - x1);
@@ -342,7 +342,7 @@ Line (int x1, int y1, int x2, int y2, int c)
 	  }
 	else if (r1 & 2)
 	  {			/* right */
-#ifdef __i386__
+#if defined(__i386__)&&defined(ASSEMBLY)
 	    y1 += muldiv64 (__clipx2 - x1, y2 - y1, x2 - x1);
 #else
 	    y1 += (long) (__clipx2 - x1) * (long) (y2 - y1) / (long) (x2 - x1);
@@ -351,7 +351,7 @@ Line (int x1, int y1, int x2, int y2, int c)
 	  }
 	else if (r1 & 4)
 	  {			/* top */
-#ifdef __i386__
+#if defined(__i386__)&&defined(ASSEMBLY)
 	    x1 += muldiv64 (__clipy1 - y1, x2 - x1, y2 - y1);
 #else
 	    x1 += (long) (__clipy1 - y1) * (long) (x2 - x1) / (long) (y2 - y1);
@@ -360,7 +360,7 @@ Line (int x1, int y1, int x2, int y2, int c)
 	  }
 	else if (r1 & 8)
 	  {			/* bottom */
-#ifdef __i386__
+#if defined(__i386__)&&defined(ASSEMBLY)
 	    x1 += muldiv64 (__clipy2 - y1, x2 - x1, y2 - y1);
 #else
 	    x1 += (long) (__clipy2 - y1) * (long) (x2 - x1) / (long) (y2 - y1);
