--- nh2ps.c.orig	Tue Oct 20 07:10:01 1998
+++ nh2ps.c	Wed Oct 23 16:51:28 2002
@@ -255,6 +255,8 @@
 #define A4_WIDTH         8.27
 #define A4_HEIGHT       11.64
 
+#if A4_PAPERSIZE
+
 #ifndef WIDTH
 #define	WIDTH	A4_WIDTH
 #endif
@@ -263,6 +265,18 @@
 #define	HEIGHT	A4_HEIGHT
 #endif
 
+#else
+
+#ifndef WIDTH
+#define	WIDTH	USA_WIDTH
+#endif
+
+#ifndef HEIGHT
+#define	HEIGHT	USA_HEIGHT
+#endif
+
+#endif
+
 #ifndef MARGIN
 #define	MARGIN	1.4
 #endif
@@ -560,7 +574,7 @@
     fprintf(stderr,"pos.   =  -#num\t\tnumber of copies to print\n");
     fprintf(stderr,"          -1\t\tone page per sheet\n");
     fprintf(stderr,"          -2\t\tTWIN PAGES per sheet\n");
-#if A4_PAPERSIZE == 1
+#if A4_PAPERSIZE
     fprintf(stderr,"          -a\t\tUse USA paper size (8.5\" x 11\")\n");
 #else
     fprintf(stderr,"          -a\t\tUse A4 paper size (21cm x 29.56cm (8.27\" x 11.64\"))\n");
@@ -677,10 +691,14 @@
 	interpret = TRUE;
 	break;
     case 'a':                           /* American paper sizes */
-#if defined(USA_HEIGHT) && defined(USA_WIDTH)
+#if A4_PAPERSIZE
         paper_height = USA_HEIGHT;
         paper_width = USA_WIDTH;
 	strcpy(papersizename, "Letter");
+#else
+        paper_height = A4_HEIGHT;
+        paper_width = A4_WIDTH;
+	strcpy(papersizename, "A4");
 #endif
         break;
     case 'n':
@@ -2323,7 +2341,7 @@
 
 #endif
 
-#ifdef A4_PAPERSIZE
+#if A4_PAPERSIZE
     strcpy(papersizename, "A4");
 #else
     strcpy(papersizename, "Letter");
