--- c2t.c.orig	1993-02-24 14:29:23.000000000 +0800
+++ c2t.c	2011-09-05 14:25:34.000000000 +0800
@@ -18,14 +18,18 @@
 
 #define MEMAREA 4096 /* max number of lines in DICT file, wc -l DICT */
 
-main(argc, argv)
+int main(argc, argv)
 int argc;
 char **argv;
 {
+#ifndef CHINDICT
   char *DICT="/home/ftp/software/unix/X-Window/cxterm-dictionary/TONEPY.tit";
+#else
+  char *DICT=CHINDICT;
+#endif
   register int eka=0, toka=0, i=0;
   register char hz[4], **pipo=0;
-  register char **taulu=0, rivi[82];
+  char **taulu=0, rivi[82];
   register int rpit=0, tila=0, rraja=0, mulpin=0;
   int monitila=0;
   FILE *piffi=0;
@@ -57,12 +61,12 @@ char **argv;
 	   i =0;
 	} /*if argc > 1 */	
   if ((piffi = fopen (DICT, "r")) == 0) {
-    printf (stderr, "Error: unable to open pinyin dictionnary %s\n",
+    fprintf (stderr, "Error: unable to open pinyin dictionnary %s\n",
 	    DICT);
     exit (-1);
   }
   if ((taulu = (char **)malloc (MEMAREA*sizeof(char *))) == 0) {
-    printf (stderr, "Error: out of memory when allocating taulu(MEMAREA too large)\n");
+    fprintf (stderr, "Error: out of memory when allocating taulu(MEMAREA too large)\n");
     exit (-2);
   }
   pipo = taulu;
@@ -81,13 +85,13 @@ char **argv;
     } else {
       if (rivi[0] == '#') continue;
       if ((*pipo = (char *)malloc (rpit+8)) == 0) {
-	printf (stderr, "Error: out of memory when allocating *pipo\n");
+	fprintf (stderr, "Error: out of memory when allocating *pipo\n");
 	exit (-3);
       }
       strcpy (*pipo, rivi);
       pipo++;
       if (++rraja >= MEMAREA) {
-	printf (stderr, "Error: out of memory when allocating *pipo(MEMAREA too small)...\n");
+	fprintf (stderr, "Error: out of memory when allocating *pipo(MEMAREA too small)...\n");
 	exit (-4);
       }
     }
